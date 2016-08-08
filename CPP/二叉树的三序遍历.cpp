#include <stdio.h>
#include <malloc.h>
#define maxsize 100
typedef char Elemtype;
typedef struct node
{
	Elemtype data;
	struct node *lchild;
	struct node *rchild;
}BTnode;

void CreateBTnode(BTnode *&b,char *str)
{
	BTnode *st[maxsize], *p = NULL;
	int top = - 1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while(ch!='\0')
	{
		if(ch == '(')
		{
			top++;
			st[top] = p;
			k = 1;
		}
		else if(ch == ')')
		{
			top--;
		}
		else if(ch == ',')
		{
			k = 2;
		}
		else
		{
			p=(BTnode *)malloc(sizeof(BTnode));
			p->data = ch;	p->lchild = p->rchild = NULL;
			if(b == NULL)
				b = p;
			else
			{
				if(k == 1)
					st[top]->lchild = p;
				else if(k == 2)
					st[top]->rchild = p;
			}
		}
		j++;
		ch = str[j];
	}
}

void PreOrder(BTnode *p)
{
	if(p!=NULL)
	{
		printf(" %c",p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void InOrder(BTnode *p)
{
	if(p!=NULL)
	{
		InOrder(p->lchild);
		printf(" %c",p->data);
		InOrder(p->rchild);
	}
}

void PostOrder(BTnode *p)
{
	if(p!=NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf(" %c",p->data);
	}
}

void PreOrder1(BTnode *p)
{
	BTnode *st[maxsize], *b;
	int top = -1;
	if(p != NULL)
	{
		top++;
		st[top] = p;
		while(top > -1)
		{
			b = st[top];
			top--;
			printf(" %c",b->data);
			if(b->rchild != NULL)
			{
				st[++top] = b->rchild;
			}
			if(b->lchild !=NULL)
			{
				st[++top] = b->lchild;
			}

		}
	}
	printf("\n");
}

void InOrder1(BTnode *p)
{
	BTnode *st[maxsize], *b;
	int top = -1;
	if(p != NULL)
	{
		b = p;
		while(top>-1 || b != NULL)
		{
			while(b != NULL)
			{
				st[++top] = b;
				b = b->lchild;
			}
			if(top>-1)
			{
				b = st[top--];
				printf(" %c",b->data);
				b=b->rchild;
			}
		}
	}
	printf("\n");
}

void PostOrder1(BTnode *p)
{
	BTnode *st[maxsize], *b;
	int top = -1,flag;
	if(p != NULL)
	{
		do
		{
			while(p != NULL)
			{
				st[++top] = p;
				p=p->lchild;
			}
			b = NULL;
			flag = 1;
			while(top != -1 && flag)
			{
				p = st[top];
				if(p->rchild == b)
				{
					printf(" %c",p->data);
					top--;
					b = p;
				}
				else
				{
					p = p->rchild;
					flag = 0;
				}
			}
		}while(top>-1);
	}
	printf("\n");
}

void DestroyBTNode(BTnode *p)
{
	if(p!=NULL)
	{
		DestroyBTNode(p->lchild);
		DestroyBTNode(p->rchild);
		free(p);
	}
}

void DispBTnode(BTnode *p)
{
	if(p != NULL)
	{
		printf("%c",p->data);
		if(p->lchild != NULL || p->rchild != NULL)
		{
			printf("(");
			DispBTnode(p->lchild);
			if(p->rchild != NULL) printf(",");
			DispBTnode(p->rchild);
			printf(")");
		}
	}
}

void TravLevel(BTnode *b)
{
	BTnode *qu[maxsize];
	int front ,rear ;
	front = rear = 0;
	if(b != NULL)
		printf(" %c",b->data);
	rear++;
	qu[rear] = b;
	while(rear != front)
	{
		front = (front + 1) % maxsize;
		b = qu[front];
		if(b->lchild !=NULL)
		{
			printf(" %c",b->lchild->data);
			rear = (rear + 1) % maxsize;
			qu[rear] = b->lchild;
		}
		if(b->rchild != NULL)
		{
			printf(" %c",b->rchild->data);
			rear = (rear + 1) % maxsize;
			qu[rear] = b->rchild;
		}
	}
	printf("\n");
}

int main()
{
	BTnode *b,*p,*lp,*rp;
	CreateBTnode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("二叉树 b ："); DispBTnode(b); printf("\n");
	printf("层次遍历序列：");
	TravLevel(b);
	printf("先序遍历序列\n");
	printf("    递归算法："); PreOrder(b); printf("\n");
	printf("  非递归算法："); PreOrder1(b);
	printf("中序遍历序列\n");
	printf("    递归算法：");InOrder(b); printf("\n");
	printf("  非递归算法：");InOrder1(b);
	printf("后序遍历序列\n");
	printf("    递归算法：");PostOrder(b); printf("\n");
	printf("  非递归算法：");PostOrder1(b);

	DestroyBTNode(b);
	return 0;
}
