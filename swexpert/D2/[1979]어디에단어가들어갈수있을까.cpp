#include <stdio.h>
const int MAXN = 15;
int map[MAXN][MAXN];
int N, K;

int main()
{
	int T; 
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &K);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);
		}

		int ans = 0;
		// 가로
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				if (map[x][y] == 0) continue;

				int cnt = 0;
				while (y < N && map[x][y] == 1) cnt++, y++;
				if (cnt == K) ans++;				
			}
		}

		// 세로
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (map[x][y] == 0) continue;

				int cnt = 0;
				while (x < N && map[x][y] == 1) cnt++, x++;
				if (cnt == K) ans++;
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}