#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int visit[301] = { 0, };
		int num[7];
		for (int i = 0; i < 7; i++)
			scanf("%d", &num[i]);

		for (int i = 0; i <= 4; i++)
		{
			for (int j = i + 1; j <= 5; j++)
			{
				for (int k = j + 1; k < 7; k++)
				{
					int sum = num[i] + num[j] + num[k];
					visit[sum]++;
				}
			}
		}
		int cnt = 0, i;
		for (i = 300; i >= 0; i--)
		{
			if (visit[i]) {             // 중복된 값은 1개로 간주한다.
				++cnt;
				if (cnt == 5) break;
			}
		}
		printf("#%d %d\n", tc, i);
	}
	return 0;
}