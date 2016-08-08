#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

struct card
{
    int hp, att, c;
    bool d;
};

const int maxn = 10;

int n, perm[maxn], fac[maxn], ans;
card a[maxn];

void dfs(int al, int vd, bool dd, int ts)
{
    if (!al || !vd)
    {
        for (int i = 0; i < n; ++ i)
            if (a[i]. hp > 0)
                ts += a[i]. c * a[i]. att;
        if (ts > ans)
            ans = ts;
    }
    else
    {
        for (int i = 0; i < n; ++ i)
            if (a[i]. hp > 0 && a[i]. c)
            {
                -- a[i]. c;
                if (a[i]. d)
                {
                    a[i]. d = 0;
                    dfs(al - 1, (dd ? vd : max(0, vd - a[i]. att)), 0, 0);
                    a[i]. d = 1;
                }
                else
                {
                    a[i]. hp -= 8;
                    dfs(al - 1, (dd ? vd : max(0, vd - a[i]. att)), 0, 0);
                    a[i]. hp += 8;
                }
                ++ a[i]. c;
            }
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int tc(0);
        for (int i = 0; i < n; ++ i)
        {
            scanf("%d%d", &a[i]. att, &a[i]. hp);
            a[i]. d = 0;
            a[i]. c = 1;
            int d;
            while (1)
            {
                d = getchar();
                if (d == EOF || d == 10)
                    break;
                else if (d == 'W')
                    a[i]. c = 2;
                else if (d == 'D')
                    a[i]. d = 1;
            }
            tc += a[i]. c;
        }
        ans = 0;
        dfs(tc, 8, 1, 0);
        printf("%d\n", ans);
    }
}

