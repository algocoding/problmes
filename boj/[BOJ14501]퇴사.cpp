//https://www.acmicpc.net/problem/14501
#include <stdio.h>

inline int MAX(int a, int b){ return a > b ? a : b; }
int main()
{
	int T[16] = { 0, }, P[16] = { 0, };
	int dp[16] = { 0, };

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &T[i], &P[i]);

	for (int i = 1; i <= N; i++) 
	{
		if (i + T[i] > N + 1)   // 불가능한 상담일 경우 0으로 설정
			P[i] = 0;
	}
	int max = 0;
	for (int i = 1; i <= N; i++) // i 일의 상담을 끝으로 할때 최대 이익
	{
		for (int j = 0; j < i; j++)
		{
			if (j + T[j] > i) continue;

			dp[i] = MAX(dp[i], P[i] + dp[j]);
		}
		max = MAX(max, dp[i]);
	}
	
	printf("%d\n", max);
	return 0;
}	