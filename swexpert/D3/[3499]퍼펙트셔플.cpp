#include <stdio.h>

int main()
{
	int T; scanf("%d", &T);
	char cards[1000][81];

	for (int tc = 1; tc <= T; tc++)
	{
		int N; scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf(" %s", cards[i]);

		
		int mid = N / 2, i = 0, j;
		if (N & 1) 
		{
			j = (N + 1) / 2;
		}
		else j = mid;

		printf("#%d", tc);

		while (i < mid && j < N)
		{
			printf(" %s %s", cards[i++], cards[j++]);
		}

		if (N & 1) printf(" %s", cards[mid]);
		printf("\n");
	}
	return 0;
}