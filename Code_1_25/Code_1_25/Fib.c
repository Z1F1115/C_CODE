#include <stdio.h>

//int	Fib(int n)
//{
//	if (n > 2)
//		return Fib(n - 1) + Fib(n - 2);
//	else
//		return 1;
//}

int Fib(int n)
{
	int a = 1,b = 1,c = 1;
	while (n >2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}