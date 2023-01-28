#include <stdio.h>
#include "DigitSum.h"

//int DigitSum(int i)
//{
//	static int a = 0;
//	if (i > 9)
//	{
//		DigitSum(i / 10);
//	}
//	a += i % 10;
//	return a;
//}

//另一种方法
int DigitSum(int n)
{
	if (n > 9)
		return DigitSum(n / 10) + n % 10;
	else
		return n;

}