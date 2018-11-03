//https://www.acmicpc.net/problem/14501
#include <stdio.h>

inline int MAX(int a, int b){ return a > b ? a : b; }
int max;
int T[16], P[16], cnt[16];

void subset(int k, int n, int p){
	if (k == n){
		max = MAX(max, p);
		return;
	}
	subset(k + 1, n, p);
	if (k + T[k] > n) return;

	for (int i = k; i < k + T[k]; i++)
		if (cnt[i]) return;
	
	for (int i = k; i < k + T[k]; i++)
		cnt[i] = 1;
	subset(k + 1, n, p + P[k]);
	for (int i = k; i < k + T[k]; i++)
		cnt[i] = 0;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &T[i], &P[i]);

	subset(1, N + 1, 0);

	printf("%d\n", max);
	return 0;
}