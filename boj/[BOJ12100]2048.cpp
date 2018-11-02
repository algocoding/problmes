// https://www.acmicpc.net/problem/12100
// 2048
#include <stdio.h>

int N;
int map[20][20];
enum DIR{ UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3};
const int CNT = 5;

int max;

int findMax(int arr[][20]){
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0) continue;
			if (ret < arr[i][j])
				ret = arr[i][j];
		}
	}
	return ret;
}

void move(int cur[][20], int next[][20], int dir)
{
	int arr[20] { 0, };
	if (dir == UP){
		for (int i = 0; i < N; i++)
		{
			int top = -1;
			bool flag = false;
			for (int j = 0; j < N; j++)
			{
				if (cur[j][i] == 0) continue;
				
				if (flag && arr[top] == cur[j][i])
				{
					arr[top] <<= 1;
					flag = false;
				}
				else{
					arr[++top] = cur[j][i];
					flag = true;
				}
			}			
			for (int j = 0; j <= top; j++)
				next[j][i] = arr[j];
		}
	}
	else if (dir == DOWN){
		for (int i = 0; i < N; i++)
		{
			int top = -1;
			bool flag = false;
			for (int j = N - 1; j >= 0; j--)
			{
				if (cur[j][i] == 0) continue;
				
				if (flag && arr[top] == cur[j][i])
				{
					arr[top] = cur[j][i] << 1;
					flag = false;
				}
				else{
					arr[++top] = cur[j][i];
					flag = true;
				}
			}
			
			for (int j = 0; j <= top; j++)
				next[N - 1 - j][i] = arr[j];
		}
	}
	else if (dir == LEFT){
		for (int i = 0; i < N; i++)
		{
			int top = -1;
			bool flag = false;
			for (int j = 0; j < N; j++)
			{
				if (cur[i][j] == 0) continue;
				
				if (flag && arr[top] == cur[i][j])
				{
					arr[top] <<= 1;
					flag = false;
				}
				else{
					arr[++top] = cur[i][j];
					flag = true;
				}
			}
			for (int j = 0; j <= top; j++)
				next[i][j] = arr[j];
		}
	}
	else {
		for (int i = 0; i < N; i++)
		{
			int top = -1;
			bool flag = false;
			for (int j = N - 1; j >= 0; j--)
			{
				if (cur[i][j] == 0) continue;
				
				if (flag && arr[top] == cur[i][j])
				{
					arr[top] = cur[i][j] << 1;
					flag = false;
				}
				else{
					arr[++top] = cur[i][j];
					flag = true;
				}
			}

			for (int j = 0; j <= top; j++)
				next[i][N - 1 - j] = arr[j];
		}
	}
}
void copyarr(int from[][20], int to[][20]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			to[i][j] = from[i][j];
}
void play(int k, int cur[][20])
{
	if (k == CNT){		
		int ret = findMax(cur);
		if (ret > max) max = ret;
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int next[20][20] = { 0, };
		
		move(cur, next, i);

		play(k + 1, next);
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}	
	max = 0;
	play(0, map);
	printf("%d\n", max);
	return 0;
}