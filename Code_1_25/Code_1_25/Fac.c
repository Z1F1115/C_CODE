#include <stdio.h>
int Fac(int n)
{
	if (n > 0)
		return n * Fac(n - 1);
	else
		return 0;
}