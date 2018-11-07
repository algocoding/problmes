#include <stdio.h>
typedef long long ll;
inline int ABS(int a){ return a > 0 ? a : -a; }
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++)
	{
		int N, A, B;
		scanf("%d%d%d", &N, &A, &B);

		int sqrt;
		for (sqrt = 0; sqrt < N; sqrt++)
			if (sqrt * sqrt > N) break;
		
		ll R = sqrt - 1;
		ll C = R;
		
		ll min = 0xfffffffffffffff;		
			
		for (int i = R; ; i++)
		{
			int j;
			for (j = i; i * j <= N; j++)
			{
				ll t = (ll)A * ABS(i - j) + (ll)B * ABS(N - (i*j));
				if (t < min) min = t;
			}
			if (i * j > N) break;
		}
		for (int i = 1; i < R; i++)
		{
			int j;
			for (j = i; i * j <= N; j++)
			{
				ll t = (ll)A * ABS(i - j) + (ll)B * ABS(N - i*j);
				if (t < min) min = t;				
			}			
		}
		
		printf("#%d %lld\n", tc, min);
	}
	return 0;
}