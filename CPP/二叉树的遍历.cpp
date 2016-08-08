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

/** ��STR���������� **/
void CreateBTNode(BTNode *&b,char * str)
{
    int i = 0;
    Insertnode(b,i,str); ///�Եݹ���ʽ�������ݣ�i ����ű仯
}



/** ����e�Ľڵ�ָ�� **/
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

/** ��������� **/
void DispBTNode(BTNode * b)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("��");
            DispBTNode(b->lchild);
            if(b->rchild != NULL)printf("��");
            DispBTNode(b->rchild);
            printf("��");
        }
    }
}

/** ��� **/
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

/** ��������Ŀ�� **/
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

/** ��������Ľڵ���� **/
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

/** ��Ҷ�ӽڵ���� **/
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
    printf("��������\n");
    printf("��1�������������");
    DispBTNode(root);
    puts("");
    printf("��2��H�ڵ㣺");
    p = FindNode(root,'H');
    if(p!=NULL)
    {
        lp = p->lchild;
        if(lp != NULL)
        {
            printf("����Ϊ %c ",lp->data);
        }
        else
        {
            printf("������");
        }
        rp = p->rchild;
        if(rp != NULL)
        {
            printf("�Һ���Ϊ %c ",rp->data);
        }
        else
        {
            printf("���Һ���");
        }
    }
    puts("");
    printf("��3������������ȣ� %d\n",BTNodeDepth(root));
    printf("��4���������Ŀ���� %d\n",BTWidth(root));
    printf("��5���������Ľڵ���:%d\n",Nodes(root));
    printf("��6����������Ҷ�ӽڵ������%d\n",leafNodes(root));
    printf("��7���ͷŶ�����\n");
    DestroyBTNode(root);
    return 0;
}
