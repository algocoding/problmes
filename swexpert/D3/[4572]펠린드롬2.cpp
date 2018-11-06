/*
1. * 이 없는 경우
2. * 이 시작과 끝에 있는 경우
3. * 내부에 있는 경우
*/
#include <stdio.h>

int main()
{
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char str[30];
		scanf(" %s", str);

		int cnt = 0, len = 0;
		for (len = 0; str[len]; len++)
		{
			if (str[len] == '*') cnt++;
		}

		bool flag = false;

		if (cnt == 0){
			int i;
			for (i = 0; i < len / 2; i++)
			{
				if (str[i] != str[len - 1 - i]) break;
			}
			if (i == len / 2) flag = true;
		}
		else if (str[0] == '*' || str[len - 1] == '*')
			flag = true;
		else
		{
			flag = true;
			for (int i = 0; i < len / 2; i++)
			{
				if (str[i] == '*' || str[len - 1 - i] == '*')
					break;
				
				if (str[i] != str[len - 1 - i])
				{
					flag = false; break;
				}
			}			
		}
		if (flag) printf("#%d Exist\n", tc);
		else printf("#%d Not exist\n", tc);
	}
	return 0;
}