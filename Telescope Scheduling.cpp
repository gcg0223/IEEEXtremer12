#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 10005;
struct t
{
	int S;
	int F;
	int D;
} star[N];
int *pre = new int[N + 1];
int *opt = new int[N + 1];
int solve_dp(int n);
int max(int x, int y);
int max(int x, int y)
{
	return x > y ? x : y;
}
int solve_dp(int n)
{
	if (n == 1)
		return star[1].D;
	int i, j;
	//int *pre = new int[n + 1];
	memset(pre, 0, (n + 1) * sizeof(pre));
	for (i = 2; i <= n; i++)
	for (j = i - 1; j >= 1; j--)
	if (star[i].S > star[j].F)
	{
		pre[i] = j;
		break;
	}
	//int *opt = new int[n + 1];
	opt[1] = star[1].D;
	for (i = 2; i <= n; i++)
	{
		if (pre[i] == 0)
			opt[i] = max(star[i].D, opt[i - 1]);
		else
			opt[i] = max((star[i].D + opt[pre[i]]), opt[i - 1]);
	}
	return opt[n];
}
bool paixu(t a, t b)
{
	return a.F <b.F;
}
int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d%d%d", &star[i].S, &star[i].F, &star[i].D);
	sort(star + 1, star + n + 1, paixu);
	printf("%d", solve_dp(n));
	return 0;
}
