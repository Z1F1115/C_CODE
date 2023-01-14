#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0;
	scanf("%d",&a);
	if (a <= 100000 && a >= 1)
	{
		int x = 0;
		x = a % 5;
		if (x == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		return 0;
	return 0;

	//return a % 5 == 0 ? "YES" : "NO";
}
