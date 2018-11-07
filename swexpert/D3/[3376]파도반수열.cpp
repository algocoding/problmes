#include <stdio.h>

int main()
{
	long long dp[101] = { 0, 1, 1, 1, 2, 2, };
	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N; 
		scanf("%d", &N);

		printf("#%d %lld\n", tc, dp[N]);
	}
	return 0;
}