#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void fun(int x, int y)
{
	if(y == 0 || y==1)
	{
		if (x == 5 || x == 6)
			printf("%c", '*');
		else if(x == 11)
			printf("%c\n", ' ');
		else
			printf("%c", ' ');
	}
	if (y == 2 || y == 3)
	{
		if (x == 11)
			printf("%c\n", '*');
		else
			printf("%c", '*');
	}
	if (y == 4 || y == 5)
	{
		if (x == 4 || x == 7)
			printf("%c", '*');
		else if (x == 11)
			printf("%c\n", ' ');
		else
			printf("%c", ' ');
	}
}

//int main()
//{
//	
//	for(int y = 0; y < 6; y++)
//	{
//		for (int x = 0; x < 12; x++)
//		{
//			fun(x, y);
//		}
//	}
//
//	return 0;
//}
