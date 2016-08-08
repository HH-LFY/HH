#include<iostream>
#include<cstdio>
using namespace std;
#define blue 0
#define purple 1
#define arr 110
int tree[arr];
int color[arr];
int dis[arr];
int g[arr][arr];
int root;
int sum;
int main()
{
	int n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>g[i][j];
	for(int i=1;i<=n;i++)
	color[i]=blue;
	root=1;
	color[root]=purple;
	dis[root]=0;
	for(int i=2;i<=n;i++)
	dis[i]=g[root][i];
	sum=0;
	for(int i=1;i<=n;i++)
	 tree[i]=root;
	 for(int times=1;times<n;times++)
	 {
	 	int wqd=100000000;
	 	int k;
	 	for(int j=1;j<=n;j++)
	 	{
	     	if(color[j]==blue&&wqd>dis[j])
	 		{wqd=dis[j];
	 		  k=j;}
	 	}

	 sum+=wqd;
	 color[k]=purple;
 	 for(int j=1;j<=n;j++)
 	 {
	  if(color[j]=purple)
 	 continue;
 	 if(dis[j]>g[j][k])
 	 {
 	     dis[j]=g[j][k];
 	     tree[j]=k;
 	     }
 	 }
    }
}



