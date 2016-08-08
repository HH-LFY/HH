#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main ()
{
    int limit, sum;
    scanf ("%d %d", &sum, &limit);
    vector <int> val(limit + 1);
    for (int i = 1; i <= limit; i++)
    {
        val[i] = i & -i;
    }

    vector <int> ans;

    for (int i = limit; i > 0; i--)
    {
        if (val[i] <= sum)
        {
            sum -= val[i];
            ans.push_back(i);
        }
        if (sum == 0)
            break;
    }

    if (sum)
        printf ("-1");
    else
    {
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++)
            cout << ans[i] << " ";
    }

    return 0;
}
