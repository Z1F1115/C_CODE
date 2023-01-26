#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//#include "Fac.h"
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fac(n));
//	return 0;
//}

#include "Fib.h"
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}