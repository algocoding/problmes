// 요리사
#include <stdio.h>

int min;
const int MAXN = 16;
int S[MAXN][MAXN];
int N, R;
int A[10], B[10];
inline int ABS(int a){ return a > 0 ? a : -a; }
int calcDiff(){	
	bool used[MAXN] = { false, };
	for (int i = 0; i < R; i++)
		used[A[i]] = true;
	int idx = 0;
	for (int i = 0; i < N; i++)
		if (!used[i]) B[idx++] = i;
	
	int Asum = 0, Bsum = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < R; j++)
		{
			if (i == j) continue;
			Asum += S[A[i]][A[j]];
			Bsum += S[B[i]][B[j]];
		}
	}
	
	return ABS(Asum - Bsum);
}
void solve(int k, int start)    // 조합 생성하기
{
	if (k == R){
		int ret = calcDiff();
		if (ret < min) 
			min = ret;
		return;
	}
	for (int i = start; i < N; i++)
	{
		A[k] = i;
		solve(k + 1, i + 1);
	}	
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		R = N / 2;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &S[i][j]);
			}
		}
		min = 0xffffff;
		solve(0, 0);
		printf("#%d %d\n", tc, min);
	}
	return 0;
}