#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//编程题10
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (j=0;j<13;j++)
//	{
//		if (j < 7)
//		{
//			for (i = 0; i < 6 - j; i++)
//			{
//				printf("   ");
//			}
//			for (i = 0; i < j + 1; i++)
//			{
//				printf(" * ");
//
//			}
//			for (i = 0; i < j; i++)
//			{
//				printf(" * ");
//
//			}
//			printf("\n");
//		}
//		else//j=7
//		{
//			for (i=0;i<j-6;i++)
//			{
//				printf("   ");
//			}
//			for (i=0;i<13-j;i++)
//			{
//				printf(" * ");
//			}
//			for (i = 0; i <12-j ; i++)
//			{
//				printf(" * ");
//
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int line = 0;
//	scanf("%d",&line);//7
//	int i = 0;
//	int j = 0;
//	//上行
//	for (i = 0; i < line; i++)
//	{
//		// 空格
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		// 星号
//		for (j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	
//	//下行
//	for (i = 0; i < line - 1; i++)
//	{
//		// 空格
//		for (j = 0; j < 1 + i; j++)
//		{
//			printf(" ");
//		}
//		// 星号// 7
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}


//编程题11
//int main()
//{
//	int money = 0;
//	printf("喝多少钱的汽水\n");
//	scanf("%d",&money);//20
//	int count = 0;
//	if (money > 0)
//	{
//		count = 2 * money - 1;
//	}
//	//int count = money;//计算喝了多瓶
//	//int i = 0;
//	//for (i = 1; i <= count; i++)
//	//{
//	//	if (i%2==0)
//	//	{
//	//		count++;
//	//	}
//	//}
//	printf("可以喝%d瓶汽水\n",count);
//	return 0;
//}


//调试编程题7
//自己想的
//void move(int *a, int s)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < s; i++)
//	{
//		if (*a % 2 != 0)
//		{
//			a++;
//			count++;
//		}
//		else
//		{
//			int j = 0;
//			int tmp = *a;
//			int* pa = a;
//			for (j= 0;j<s-count-1;j++)
//			{
//				
//				*pa = *(pa + 1);
//				pa++;
//			}
//			*pa = tmp;
//		}
//	}
//}

//参考别人的
//void move(int* a, int s)
//{
//	int left = 0;
//	int right = s - 1;
//	
//	while (left<right)
//	{
//		while ((left<right) && a[left] % 2 == 1)
//		{
//			left++;
//		}
//		while ((left < right) && a[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = *(a + left);
//			*(a + left) = *(a + right);
//			*(a + right) = tmp;
//		}
//	}
//}
//
//void print(int* a, int s)
//{
//	int i = 0;
//	for (i = 0; i < s; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	print(arr, sz);
//	return 0;
//}


//数据的存储编程练习6
//int main()
//{
//	
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i=0;i<10;i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i>=2 && j>=1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i=0;i<10;i++)
//	{
//		for (j=0;j<=i;j++)
//		{
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//编程练习7
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	
//	return 0;
//}


//编程练习8
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (   ((b == 2) + (a == 3) == 1)
							&& ((b == 2) + (e == 4) == 1)
							&& ((c == 1) + (d == 2) == 1)
							&& ((c == 5) + (d == 3) == 1)
							&& ((e == 4) + (a == 1) == 1)
							)
						{
							if (a * b * c * d * e == 120)
							{
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}