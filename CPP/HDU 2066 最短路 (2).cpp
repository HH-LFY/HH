#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int inf=999999;
#define f 101
int map[f][f];
int t,s,d;
int a,b,c;
int i,j,k;
int main()
{
    while(~scanf("%d%d%d",&t,&s,&d)&&t&&s&&d)
    {
        for(i=0;i<f;i++)
            for(j=0;j<f;j++)
            map[i][j]=inf;
        for(i=1;i<=f;i++)
            map[i][i]=0;
        int max=0;
        for(i=1;i<=t;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=c;
            if(max<a) max=a;
            if(max<b) max=b;
        }
        for(k=1;k<f;k++)
        {
            for(i=1;i<f;i++)
            {
                for(j=1;j<f;j++)
                {
                   /// if(map[i][j]==-1||map[i][k]==-1||map[j][k]==-1)continue;
                    if(map[i][j]<map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
        int result=inf;
        int a1[1010],a2[1010];
        for(i=0;i<s;i++)
            scanf("%d",&a1[i]);
        for(i=0;i<d;i++)
            scanf("%d",&a2[i]);
        for(i=0;i<s;i++)
            for(j=0;j<d;j++)
        {
            if(result>map[a1[i]][a2[j]])
            result=map[a1[i]][a2[j]];
          ///  printf("%d\n",map[a1[i]][a2[j]]);
          ///  printf("%d\n",result);
        }
        printf("%d\n",result);
    }
    system("pause");
    printf("\n");
    return 0;
}
