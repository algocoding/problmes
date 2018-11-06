//주의>> 올림한 자리값도 더할 때 포함한다.
#include <stdio.h>

int main()
{
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int A[102] = { 0, }, B[102] = { 0, };
		int ret[103] = { 0, };

		int alen = 0, blen = 0;
		char str[105];
		scanf(" %s", str);
		while (str[alen]) alen++;

		for (int i = 0; i < alen; i++)
			A[alen - 1 - i] = str[i] - '0';
		
		scanf(" %s", str);
		while (str[blen]) blen++;

		for (int i = 0; i < blen; i++)
			B[blen - 1 - i] = str[i] - '0';
		
		int maxlen = alen > blen ? alen : blen;

		for (int i = 0; i < maxlen; i++)
		{
			int s = A[i] + B[i] + ret[i];
			ret[i] = s % 10;
			ret[i + 1] += s / 10;
		}
		
		printf("#%d ", tc);
		int start = maxlen - 1;
		if (ret[maxlen]) start = maxlen;

		for (int i = start; i >= 0; i--)
			printf("%d", ret[i]);
		
		printf("\n");
	}
	return 0;
}