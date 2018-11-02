//https://www.acmicpc.net/problem/14500
#include <stdio.h>

int map[500][500];
int N, M;	//행,열

inline int MAX(int a, int b){ return a > b ? a : b; }
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	}
	int max = 0, sum;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			// 첫번째
			if (y <= M - 4)
			{
				sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3];
				max = MAX(max, sum);
			}
			if (x <= N - 4)
			{
				sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y];
				max = MAX(max, sum);
			}
			// 두번째
			if (x <= N - 2 && y <= M - 2)
			{
				sum = map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1];
				max = MAX(max, sum);
			}
			// 3 x 2
			if (x <= N - 3 && y <= M - 2)
			{
				sum = 0;
				for (int i = x; i < x + 3; i++)
					for (int j = y; j < y + 2; j++)
						sum += map[i][j];

				// 세번째
				max = MAX(max, sum - map[x][y + 1] - map[x + 1][y + 1] );
				max = MAX(max, sum - map[x][y] - map[x + 1][y]);
				max = MAX(max, sum - map[x + 1][y] - map[x + 2][y]);
				max = MAX(max, sum - map[x + 1][y + 1] - map[x + 2][y + 1]);
				
				//네번째
				max = MAX(max, sum - map[x][y + 1] - map[x + 2][y]);
				max = MAX(max, sum - map[x][y] - map[x + 2][y + 1]);

				//다섯번째
				max = MAX(max, sum - map[x][y + 1] - map[x + 2][y + 1]);
				max = MAX(max, sum - map[x][y] - map[x + 2][y]);
			}
			
			// 2 x 3
			if (x <= N - 2 && y <= M - 3){
				sum = 0;
				for (int i = x; i < x + 2; i++)
					for (int j = y; j < y + 3; j++)
						sum += map[i][j];
				// 세번째
				max = MAX(max, sum - map[x][y] - map[x][y + 1]);
				max = MAX(max, sum - map[x][y + 1] - map[x][y + 2]);
				max = MAX(max, sum - map[x + 1][y] - map[x + 1][y + 1]);
				max = MAX(max, sum - map[x + 1][y + 1] - map[x + 1][y + 2]);

				//네번째
				max = MAX(max, sum - map[x][y] - map[x + 1][y + 2]);
				max = MAX(max, sum - map[x][y + 2] - map[x + 1][y]);

				//다섯번째
				max = MAX(max, sum - map[x + 1][y] - map[x + 1][y + 2]);
				max = MAX(max, sum - map[x][y] - map[x][y + 2]);
			}
		}
	}
	printf("%d\n", max);
	return 0;
}