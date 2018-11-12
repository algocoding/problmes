#include <stdio.h>

inline int MAX(int a, int b) { return a > b ? a : b; }
int T[16], P[16], N;
bool isPossible(int day, int cnt[])
{
	if (day + T[day] - 1 > N) return false;
	for (int i = day; i < day + T[day]; i++)
		if (cnt[i]) return false;
	return true;
}
int main()
{	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &T[i], &P[i]);

	int max = 0;
	for (int i = 1; i < (1 << (N + 1)); i++)
	{
		int cnt[16] = { 0, };
		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			if ((i & (1 << j)) == 0) continue;

			if (!isPossible(j, cnt)) break;

			for (int k = j; k < j + T[j]; k++)
				cnt[k] = 1;
			sum += P[j];
		}
		max = MAX(max, sum);
	}

	printf("%d\n", max);
	return 0;
}