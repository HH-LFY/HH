#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int N, M;
ll A[1000100];
int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
	{
		int x;
		scanf("%d", &x);
		A[i] = x;
	}
	int l = 1, r = N;
	ll depth = 2;
	ll total = 0;
	while(r - l > 2 * M)
	{
		total += depth * (A[l + M] - A[l]);
		total += depth * (A[r] - A[r - M]);
		l += M;
		r -= M;
		depth += 2;
	}
	total += depth * (A[r] - A[l]);
	cout << total << endl;
	return 0;
}
