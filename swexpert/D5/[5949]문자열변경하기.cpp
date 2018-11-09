#include <stdio.h>

char s1[100002], s2[100002];
int pos1[100002], pos2[100002];
inline int ABS(long long a){ return a > 0 ? a : -a; }

int main()
{
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf(" %s", s1);
		scanf(" %s", s2);

		int a1 = 0, a2 = 0;
		int idx = 0;
		while (s1[idx])
		{
			if (s1[idx] == 'a') pos1[a1++] = idx;
			if (s2[idx] == 'a') pos2[a2++] = idx;			
			idx++;
		}
				
		long long cnt = 0;
		for (int i = 0; i < a1; i++)
			cnt += ABS((long long)pos1[i] - pos2[i]);
				
		printf("#%d %lld\n", tc, cnt);
		
		for (int i = 0; i < idx; i++)
			pos1[i] = pos2[i];
	}
	return 0;
}
