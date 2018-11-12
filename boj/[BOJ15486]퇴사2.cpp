//https://www.acmicpc.net/problem/15486
#include <stdio.h>
const int MAXN = 1500000;
int dp[MAXN + 2] = { 0, };
int T[MAXN + 2], P[MAXN + 2];

inline int MAX(int a, int b) { return a > b ? a : b; }
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &T[i], &P[i]);

	int max = 0;
	for (int i = 1; i <= N + 1; i++) // i일 상담이 가능하면 
	{
		max = MAX(max, dp[i]);
		if (i + T[i] > N + 1) continue;
		dp[i + T[i]] = MAX(max + P[i], dp[i + T[i]]);
	}

	printf("%d\n", max);
	return 0;
}