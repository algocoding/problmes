#include <stdio.h>
const int MAXN = 12;
int N;
int op[4];
int order[MAXN];
int num[MAXN];
int min, max;

int calc()
{
	int ret = num[0];
	for (int i = 0; i <= N - 2; i++)
	{
		switch (order[i]){
		case 0:
			ret = ret + num[i + 1];
			break;
		case 1:
			ret = ret - num[i + 1];
			break;
		case 2:
			ret = ret * num[i + 1];
			break;
		case 3:
			ret = ret / num[i + 1];
			break;
		}
	}
	return ret;
}
void makeExp(int k){
	if (k == N - 1) {
		int ret = calc();
		min = ret < min ? ret : min;
		max = ret > max ? ret : max;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] == 0) continue;
		op[i]--;
		order[k] = i;
		makeExp(k + 1);
		op[i]++;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		scanf("%d%d%d%d", &op[0], &op[1], &op[2], &op[3]);
		for (int i = 0; i < N; i++)
			scanf("%d", &num[i]);

		min = 0xffffff;
		max = -0xffffff;
		makeExp(0);
		printf("#%d %d\n", tc, max - min);
	}
	return 0;
}