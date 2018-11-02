//https://www.acmicpc.net/problem/13458
#include <stdio.h>

const int MAXN = 1000000;
int arr[MAXN + 1];
int N, A, B;

int main()
{
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d%d", &A, &B);

	long long cnt = 0;

	for (int i = 0; i < N; i++)
	{
		int t = arr[i] - A;
		cnt++;
		if (t <= 0) continue;
			
		int q = t / B;
		int r = t % B;
		if (r == 0) cnt += q;
		else if (q == 0) cnt++;
		else cnt += q + 1;
	}
	printf("%lld\n", cnt);
	
	return 0;
}