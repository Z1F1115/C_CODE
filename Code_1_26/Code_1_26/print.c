#include <stdio.h>
#include "print.h"

void print(int i)
{
	if (i > 9)
	{
		print( i / 10);
	}
	printf("%d ", i % 10);
}
