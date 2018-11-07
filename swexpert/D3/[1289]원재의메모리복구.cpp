#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		char str[51];		
		scanf(" %s", str);

		char cur = '0';
		int cnt = 0;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] != cur)
			{
				cur = (cur == '0') ? '1' : '0';
				cnt++;
			}
		}
		printf("#%d %lld\n", tc, cnt);
	}
	return 0;
}