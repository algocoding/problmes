#include <stdio.h>

bool prime[1000];
int arr[1000], end;
int cnt[1000];
void findPrime(){
	for (int i = 2; i <= 999; i++)
		prime[i] = true;


	for (int i = 2; i <= 100; i++)
	{
		if (prime[i]){
			for (int j = i * i; j <= 999; j += i)
				prime[j] = false;
		}
	}
	for (int i = 2; i <= 999; i++)
	{
		if (prime[i]) arr[end++] = i;
	}
	
	for (int i = 0; i < end - 2; i++)
	{
		for (int j = i; j < end - 1; j++)
		{
			for (int k = j; k < end; k++)
			{
				int t = arr[i] + arr[j] + arr[k];
				if (t > 999)					
					break;

				cnt[t]++;
			}
		}
	}
}
int main()
{
	findPrime();
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);

		
		printf("#%d %d\n", tc, cnt[N]);
	}
	return 0;
}