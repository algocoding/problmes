#include <stdio.h>

char s1[100002], s2[100002];
int pos1[100002], pos2[100002];
inline int ABS(int a){ return a > 0 ? a : -a; }

int main()
{
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf(" %s", s1);
		scanf(" %s", s2);

		int i = 0, j = 0;
		long long cnt = 0;

		while (1)
		{
			while (s1[i] && s1[i] == 'b') i++;
			while (s2[j] && s2[j] == 'b') j++;
			if (s1[i] == '\0' || s2[j] == '\0')
				break;
			
			cnt += ABS(i - j);
			i++, j++;
		}		
				
		printf("#%d %lld\n", tc, cnt);		
	}
	return 0;
}
