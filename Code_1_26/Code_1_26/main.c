#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//作业3
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i < 101;i++)
//	{
//		if (i % 10 == 9) 
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("有%d个", count);
//	return 0;
//}


//作业4
//int main()
//{
//	int i = 0;
//	double n = 1.0;
//	for (i = 2; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//			n -= 1.0 / i;
//		else
//			n += 1.0 / i;
//	}
//	printf("%lf\n",n);
//	return 0;
//}

//上面的方法二
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}


//作业5
//int main()
//{
//	int arr[] = { 1099,200,30,40,50,60,70,80,90,100 };
//	int i = 0;
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//	}
//	printf("%d\n",max);
//	return 0;
//}


//作业6
//#include "print.h"
//int main()
//{
//	int i = 0;
//	for (i=1;i<=9;i++)
//	{
//		print(i);
//		printf("\n");
//	}
//	return 0;
//}


//作业7
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int n = rand() % 100;
//	int i = 0;
//	while (1)
//	{
//		printf("输入一个一百以内的数：");
//		scanf("%d", &i);
//		if (i == n)
//		{
//			printf("猜对了，是%d\n",n);
//			break;
//		}
//		else if (i < n)
//			printf("数小了\n");
//		else if (i > n)
//			printf("数大了\n");
//	}
//	return 0;
//}


//作业8
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,9,8,10 };
//	int i = 6;
//	int n = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int rigth = sz-1;
//	while (left<=rigth)
//	{
//		n = (left + rigth) / 2;
//		if (i > arr[n])
//			left = n + 1;
//		else if (i < arr[n])
//			rigth = n - 1;
//		else if (i == arr[n])
//			break;
//	}
//	if (left > rigth)
//		printf("找不到\n");
//	else
//		printf("找到了，下标是%d\n",n);
//	return 0;
//}


//练习
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int n = 0;
//		int a = 1;
//		for (n = 2; n < i; n++)
//		{
//			if (i % n == 0)
//			{ 
//				a = 0;
//				break;
//			}	
//		}
//		if (a == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


//函数的练习，升级后的乘法口诀表
//#include "print_table.h"
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	print_table(n);
//	return 0;
//}


//函数练习3
//#include "print.h"
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//
//	return 0;
//}


//函数练习6
//#include "reverse_string.h"
//int main()
//{
//	char arr[] = { "abcdef" };
//	reverse_string(arr);
//	printf("%s\n",arr);
//	return 0;
//}


//函数练习7
//#include "DigitSum.h"
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d\n",DigitSum(n));
//	return 0;
//}


//函数练习8
//#include "Pow.h"
//int main()
//{
//	int n = 0;
//	printf("请输入n的值：");
//	scanf("%d",&n);
//	int k = 0;
//	printf("请输入k的值：");
//	scanf("%d", &k);
//	printf("%lf",Pow(n,k));
//	return 0;
//}


//函数练习9
int fib(int n)
{
	if (n > 2)
	{
		return fib(n - 1) + fib(n - 2);
	}
	else
		return 1;
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	printf("%d",fib(n));
	return 0;
}