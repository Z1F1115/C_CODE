#include <stdio.h>
#include "print_table.h"

void print_table(int n)
{
	
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int a = 0;
		for (a = 1; a <= i; a++)
		{
			printf("%d*%d=%-2d ", a, i, a * i);
		}
		printf("\n");
	}
}