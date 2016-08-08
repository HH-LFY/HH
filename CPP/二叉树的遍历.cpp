#include <iostream>
#include <cstdio>
#include <algorithm>
#include <malloc.h>
#define maxx 100
using namespace std;

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BTNode;

void Insertnode(BTNode *&p,int &i,char * str)
{
    int judge = 0;
    if(str[i]>='A'&&str[i]<='Z')
    {
        judge++;
        p = (BTNode *)malloc(sizeof(BTNode));
        p->lchild=NULL;
        p->rchild=NULL;
        p->data = str[i];
        i++;
    }
    if(str[i]=='\0')
    {
        return ;
    }
    if(str[i]=='(')
    {
        i++;
        if(!judge)
        {
            p = (BTNode *)malloc(sizeof(BTNode));
            p->lchild=NULL;
            p->rchild=NULL;
        }
        Insertnode(p->lchild,i,str);
        Insertnode(p->rchild,i,str);
    }
    if(str[i]==','||str[i]==')')
    {
        i++;
        return ;
    }
}

/** 由STR创建二叉链 **/
void CreateBTNode(BTNode *&b,char * str)
{
    int i = 0;
    Insertnode(b,i,str); ///以递归形式插入数据，i 会跟着变化
}



/** 查找e的节点指针 **/
BTNode * FindNode(BTNode * p, char e)
{
    if(p==NULL)
        return NULL;
    if(p->data==e)
        return p;
    else
    {
        BTNode *b = FindNode(p->lchild,e);
        if(b!=NULL)
            return b;
        else
            return FindNode(p->rchild,e);
    }
}

/** 输出二叉树 **/
void DispBTNode(BTNode * b)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("（");
            DispBTNode(b->lchild);
            if(b->rchild != NULL)printf("，");
            DispBTNode(b->rchild);
            printf("）");
        }
    }
}

/** 深度 **/
int BTNodeDepth(BTNode *b)
{
    if(b==NULL)
        return 0;
    else
    {
        int l = BTNodeDepth(b->lchild);
        int r = BTNodeDepth(b->rchild);
        return l>r?l+1:r+1;
    }
}

void search(BTNode *p,int *a,int k)
{
    if(p!=NULL)
    {
        a[k]++;
        search(p->lchild,a,k+1);
        search(p->rchild,a,k+1);
    }
}

/** 求二叉树的宽度 **/
int BTWidth(BTNode * b)
{
    int a[maxx], i, kmax = 0;
    for(i = 0;i < maxx; ++i)
        a[i] = 0;
    int k = 0;
    search(b,a,k);
    for(i = 0;i < maxx; ++i)
        if(a[i]>kmax) kmax = a[i];
    return kmax;
}

/** 求二叉树的节点个数 **/
int Nodes(BTNode *b)
{
    if(b==NULL)
        return 0;
    else if(b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        int l = Nodes(b->lchild);
        int r = Nodes(b->rchild);
        return l + r + 1;
    }
}

/** 求叶子节点个数 **/
int leafNodes(BTNode * b)
{
    if(b==NULL)
        return 0;
    else if(b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        int l = leafNodes(b->lchild);
        int r = leafNodes(b->rchild);
        return l + r;
    }
}

void DestroyBTNode(BTNode *&b)
{
    if(b!=NULL)
    {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}

int main( )
{
    BTNode *root, *p, *lp, *rp;
    CreateBTNode(root,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树：\n");
    printf("（1）输出二叉树：");
    DispBTNode(root);
    puts("");
    printf("（2）H节点：");
    p = FindNode(root,'H');
    if(p!=NULL)
    {
        lp = p->lchild;
        if(lp != NULL)
        {
            printf("左孩子为 %c ",lp->data);
        }
        else
        {
            printf("无左孩子");
        }
        rp = p->rchild;
        if(rp != NULL)
        {
            printf("右孩子为 %c ",rp->data);
        }
        else
        {
            printf("无右孩子");
        }
    }
    puts("");
    printf("（3）二叉树的深度： %d\n",BTNodeDepth(root));
    printf("（4）二叉树的宽带： %d\n",BTWidth(root));
    printf("（5）二叉树的节点数:%d\n",Nodes(root));
    printf("（6）二叉树的叶子节点个数：%d\n",leafNodes(root));
    printf("（7）释放二叉树\n");
    DestroyBTNode(root);
    return 0;
}
