//https://www.acmicpc.net/problem/14501
#include <stdio.h>
const int MAXN = 15;
int dp[MAXN + 2] = { 0, };
int T[MAXN + 2], P[MAXN + 2];
int N, max;

inline int MAX(int a, int b) { return a > b ? a : b; }

void solve(int day, int p)
{
	max = MAX(max, p);
	if (day > N) return;

	if (day + T[day] - 1 <= N)
		solve(day + T[day], p + P[day]);

	solve(day + 1, p);
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &T[i], &P[i]);

	max = 0;
	solve(1, 0);

	printf("%d\n", max);
	return 0;
}