#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��ҵ3
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
//	printf("��%d��", count);
//	return 0;
//}


//��ҵ4
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

//����ķ�����
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


//��ҵ5
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


//��ҵ6
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


//��ҵ7
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int n = rand() % 100;
//	int i = 0;
//	while (1)
//	{
//		printf("����һ��һ�����ڵ�����");
//		scanf("%d", &i);
//		if (i == n)
//		{
//			printf("�¶��ˣ���%d\n",n);
//			break;
//		}
//		else if (i < n)
//			printf("��С��\n");
//		else if (i > n)
//			printf("������\n");
//	}
//	return 0;
//}


//��ҵ8
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
//		printf("�Ҳ���\n");
//	else
//		printf("�ҵ��ˣ��±���%d\n",n);
//	return 0;
//}


//��ϰ
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


//��������ϰ��������ĳ˷��ھ���
//#include "print_table.h"
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	print_table(n);
//	return 0;
//}


//������ϰ3
//#include "print.h"
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//
//	return 0;
//}


//������ϰ6
//#include "reverse_string.h"
//int main()
//{
//	char arr[] = { "abcdef" };
//	reverse_string(arr);
//	printf("%s\n",arr);
//	return 0;
//}


//������ϰ7
//#include "DigitSum.h"
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d\n",DigitSum(n));
//	return 0;
//}


//������ϰ8
//#include "Pow.h"
//int main()
//{
//	int n = 0;
//	printf("������n��ֵ��");
//	scanf("%d",&n);
//	int k = 0;
//	printf("������k��ֵ��");
//	scanf("%d", &k);
//	printf("%lf",Pow(n,k));
//	return 0;
//}


//������ϰ9
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