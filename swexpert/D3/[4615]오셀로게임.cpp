#include <stdio.h>
int N, M;
int pan[10][10];
int dx[] = {-1, -1, -1, 0, 1, 1,  1, 0};
int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};
void check(int a, int b, int dol)
{
	int to;
	if (dol & 1) to = 1;
	else to = 2;
	int x, y, ex, ey;
	for (int i = 0; i < 8; i++)
	{
		x = a, y = b;
		bool flag = false;
		while (x + dx[i] > 0 && x + dx[i] <= N && y + dy[i] > 0 && y + dy[i] <= N)
		{
			x += dx[i];
			y += dy[i];
			if (!pan[x][y]) break;
			if (pan[x][y] == dol) {
				flag = true; 
				ex = x; ey = y; 
				break;
			}
		}
		if (flag){
			x = a, y = b;
			while (x != ex || y != ey)
			{
				x += dx[i];
				y += dy[i];
				pan[x][y] = to;
			}
		}
	}	
}
void printArr()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%2d", pan[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &M);

		int mid = N / 2;
		// W = 2, B = 1;
		pan[mid][mid] = pan[mid + 1][mid + 1] = 2;
		pan[mid][mid + 1] = pan[mid + 1][mid] = 1;
		//printArr();

		int a, b, dol;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &dol);
			pan[a][b] = dol;
			check(a, b, dol);
			//printArr();
		}
		int B = 0, W = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (pan[i][j] == 1) B++;
				if (pan[i][j] == 2) W++;
				pan[i][j] = 0;
			}
		}
		printf("#%d %d %d\n", tc, B, W);
	}
	return 0;
}