#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void Swap(int* x,int* y)
//{
//	int z = *x;
//	*x = *y;
//	*y = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ:a=%d b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("������:a=%d b=%d\n", a, b);
//	return 0;
//}

//��ϰ����һ����ϰ���Ż�
//void Swap(int* x,int* y)
//{
//	int z = *x;
//	*x = *y;
//	*y = z;
//}
//
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//�ϴ���ϰ
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//�Ż������
//int is_prime(int x)
//{
//	int j = 0;
//	for (j = 2; j < x; j++)
//	{
//		if (x % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{ 
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d ", count);
//	return 0;
//}


//��һ����ϰ����������
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//�Ż�
//int is_leap_year(int x)
//{
//	return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (1 == is_leap_year(y))
//			printf("%d ",y);
//	}
//	return 0;
//}

//���ֲ���
//int binary_search(int a[], int k, int s)
//{
//	int left = 0;
//	int right = s - 1;
//	while (left<=right)
//	{
//		int ret = (left + right) / 2;
//		if (a[ret] < k)
//		{
//			left = ret+1;
//		}
//		else if (a[ret] > k)
//		{
//			right = ret-1;
//		}
//		else
//			return ret;
//	}
//	return -1;
//}
// 
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int key = 11;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, key, sz);
//	if (ret == -1)
//		printf("�Ҳ���\n");
//	else
//		printf("�ҵ��ˣ��±���:%d\n",ret);
//	return 0;
//}


//��ϰ
void Add(int* p)
{
	(*p)++;
}
int main()
{
	int num = 0;
	Add(&num);
	printf("%d\n", num);

	Add(&num);
	printf("%d\n", num);

	Add(&num);
	printf("%d\n", num);
	return 0;
}
