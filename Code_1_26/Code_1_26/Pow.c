#include <stdio.h>
#include "Pow.h"

double Pow(int n, int k)//5,6
{
	int i = 0;
	if (k > 0)
	{
		return Pow(n,k-1) * n;
	}
	else if (k == 0)
	{
		return 1.0;
	}
	else
	{
		return 1.0 / (Pow(n, -k));
	}
	
}