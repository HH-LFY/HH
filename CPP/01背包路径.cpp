#include<cstdio>
#include<cstring>
const int maxn = 10005;

int val[25], dp[maxn];
bool vis[25][maxn];

int main()
{
	int n, m, i, j;
	while (~scanf("%d%d", &n, &m))
	{
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < m; ++i)
			scanf("%d", &val[i]);
		for (i = 0; i < m; ++i)
			for (j = n; j >= val[i]; --j)
				if (dp[j - val[i]] + val[i] >= dp[j])
				{
					dp[j] = dp[j - val[i]] + val[i];
					vis[i][j] = 1;
				}
		j = n;
		for (i = m - 1; i >= 0; --i)
			if (vis[i][j])
			{
				printf("%d ", val[i]);
				j -= val[i];
			}
		printf("sum:%d\n", dp[n]);
	}
	return 0;
}
