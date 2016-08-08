#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>

#define WORD 26
#define MAXN 1050

using namespace std;

struct trie
{
	trie *child[WORD]; //儿子节点指针
	trie *fail; //失败指针(前缀指针)
	int id; //若该节点为某单词的终止节点,id=该单词编号
	trie()
	{
		memset(child,0,sizeof(child)); //儿子节点初始化为空
		fail=NULL;
		id=-1;
	}
}tree[MAXN*100]; //root=根节点

int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1}; //搜索方向，暴力枚举每个点八个方向
int ans[MAXN][3],len[MAXN],L,C,W,nNodesCount=0; //第i个单词的位置=(ans[i][1],ans[i][2]),方向为ans[i][0],nNodeCounts=节点个数

string c[MAXN],word; //保存所有字符串的矩阵

void build(trie *pRoot,string s,int num) //将编号为num的字符串s插入树根为pRoot的trie树中
{
	int i;
	len[num]=s.size();
	for(i=0;s[i];i++)
	{
		if(pRoot->child[s[i]-'A']==NULL) //无现成的字符串对应位置儿子节点
		{
			pRoot->child[s[i]-'A']=tree+nNodesCount;
			nNodesCount++; //节点个数+1
		}
		pRoot=pRoot->child[s[i]-'A']; //将指针移向当前节点下面的对应儿子节点
	}
	pRoot->id=num; //记下终止节点的对应单词编号
}

void acAutomation() //搭建前缀指针，构造AC自动机
{
	int i;
	for(i=0;i<WORD;i++)
		tree[0].child[i]=tree+1; //让第0个节点的所有儿子节点都指向第一个节点，即任何单词都能从根节点匹配下去
	tree[0].fail=NULL; //根节点的失败指针指向空
	tree[1].fail=tree; //第一个节点的失败指针指向根节点
	trie *pRoot,*point;
	queue<trie*>q;
	q.push(tree+1); //将第一个节点入队
	while(!q.empty()) //队列不为空
	{
		pRoot=q.front();
		q.pop(); //队首出队
		for(i=0;i<WORD;i++) //遍历该节点的儿子
		{
			point=pRoot->child[i]; //point=单词当前字母对应的儿子
			if(point)
			{
				trie *pPrev=pRoot->fail; //失败指针指向的节点
				while(pPrev) //当指向的节点不为空，不断向上爬
				{
					if(pPrev->child[i]) //指向的节点能匹配
					{
						point->fail=pPrev->child[i]; //将该节点的失败指针指向失败指针指向的节点的可以匹配的儿子节点
						break;
					}
					else
						pPrev=pPrev->fail; //无法匹配，向该失败指针指向的节点的失败指针往上爬
				}
				q.push(point); //该节点入队
			}
		}
	}
}

void ACsearch(int sx,int sy,int dir) //搜索,单词起点(sx,sy),延伸方向为dir
{
	int i,xx=sx,yy=sy;
	trie *point=tree+1;
	while(xx>=0&&xx<L&&yy>=0&&yy<C)
	{
		while(1)
		{
			if(point->child[c[xx][yy]-'A']) //该节点的儿子节点可以匹配
			{
				point=point->child[c[xx][yy]-'A']; //指针向儿子移动
				if(point->id!=-1) //指针对应节点为危险节点，则匹配成功，记录答案
				{
					ans[point->id][0]=dir; //记录下该单词的开始坐标、方向
					ans[point->id][1]=xx-(len[point->id]-1)*dx[dir];
					ans[point->id][2]=yy-(len[point->id]-1)*dy[dir];
				}
				break;
			}
			else
				point=point->fail; //否则，无法匹配，向失败指针移动
		}
		xx+=dx[dir];
		yy+=dy[dir];
	}
}

int main()
{
	int i,j,k;
	nNodesCount=2;
	scanf("%d%d%d",&L,&C,&W);
	for(i=0;i<L;i++) cin>>c[i];
	for(i=0;i<W;i++)
	{
		cin>>word;
		build(tree+1,word,i); //将单词插入trie树
	}
	acAutomation(); //插入失败指针，构造AC自动机
	for(i=0;i<L;i++)
		for(j=0;j<8;j++)
			ACsearch(i,0,j);
	for(i=0;i<L;i++)
		for(j=0;j<8;j++)
			ACsearch(i,C-1,j);
	for(i=0;i<C;i++)
		for(j=0;j<8;j++)
			ACsearch(0,i,j);
	for(i=0;i<C;i++)
		for(j=0;j<8;j++)
			ACsearch(L-1,i,j);
	for(i=0;i<W;i++)
		printf("%d %d %c\n",ans[i][1],ans[i][2],ans[i][0]+'A');
	return 0;
}
