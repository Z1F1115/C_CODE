#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	/*const char* ps = "hello bit";
//	ps++;
//	printf("%c\n",*ps);*/
//
//	double* d[5] = { NULL };
//
//	double* (*pd)[5] = &d;
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	/*printf("%p\n", arr  );
//	printf("%p\n",arr + 1);
//	printf("%p\n",& arr + 1);*/
//
//	int* p1 = arr;
//	int(*p2)[10] = &arr;
//	printf("%p\n", p1);
//	printf("%p\n", p1 + 1);
//	printf("%p\n", p2);
//	printf("%p\n", p2 + 1);
//	printf("%p\n", p2[1]);
//	printf("%p\n", *p2 + 1);
//
//	printf("%d\n", *p1 + 1);
//	printf("%d\n", *((*p2) + 1));
//	//�����*p == arr == *p1
//
//	return 0;
//}

//void print(int (*p)[5],int x,int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(p+i)+j));
//			//printf("%d ", p[i][j]);
//		}
//		printf("\n");
//
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print(arr, 3, 5);
//
//	return 0;
//}

//int main()
//{
//	int arr[5] = {0};          //��������
//	int* parr1[10] = {NULL};   //����ָ������
//	int(*parr2)[10];		   //����ָ��
//	//���������ָ���ܹ�ָ��һ�����飬����10��Ԫ�أ�ÿ��Ԫ�ص�������int
//	int(*parr3[10])[5];		   //����ָ������
//	//�����parr3��һ���洢����ָ�������
//	//�������ܹ����10������ָ��
//	//ÿ������ָ���ܹ�ָ��һ�����飬����5��Ԫ�أ�ÿ��Ԫ����int����
//
//
//	return 0;
//}


//�����ϰ8
//int Add(int a,int b)
//{
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	for (i = 0; i < b ; i++)
//	{
//		j = j * 10+a;//22
//		sum += j ;//22+2=24
//	}
//	return sum;
//}
//
////int Add(int a, int b)
////{
////	if (b > 0)
////	{
////		b--;
////		return a + Add(a * 10 + 2, b);
////	}
////	else
////		return 0;
////}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d",&a);
//	printf("��������ࣺ>");
//	scanf("%d", &b);
//	int ret = Add(a,b);
//	printf("%d\n",ret);
//	return 0;
//}


//�����ϰ9
//void print(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *arr);
//		arr++;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}


//�����ϰ10
//�Լ����
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)//i=153
//	{
//		int count = 0;//����i�м�λ
//		int n = i;
//		int m = i;
//		int a = 0;
//		int sum = 0;
//		int j = 0;
//		while (n)//i����λ
//		{
//			n = n / 10;
//			count++;
//		}
//		while (m)
//		{
//			int b = 1;
//			a = m % 10;
//			for (j = 0; j < count; j++)
//			{
//				b = a * b;
//			}
//			m = m / 10;
//			sum = sum + b;
//		}
//		if (sum == i)
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}

//�Ż��������ϰ
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)//i=153
//	{
//		int count = 0;//����i�м�λ
//		int n = i;
//		int a = 0;
//		int sum = 0;
//		int j = 0;
//		while (n)//i����λ
//		{
//			count++;
//			n = n / 10;
//		}
//		n = i;
//		while (n)//����i��ÿһλn�η�֮��
//		{
//			sum = sum + (int)pow(n % 10, count);
//			n = n / 10;
//		}
//		if (sum == i)//�ж�
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//ָ������
#include <string.h>
#include <assert.h>
//void reverse(char *a)
//{
//	assert(a);
//
//	int left = 0;
//	int sz = strlen(a);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		char tmp = *(a+left);
//		*(a + left) = *(a + right);
//		*(a + right) = tmp;
//		left++;
//		right--;
//	}
//}

void reverse(char* a)
{
	assert(a);

	char* left = a;
	int sz = strlen(a);
	char* right = a + sz - 1;
	while (left <= right)
	{
		char tmp = * left;
		*left = *right;
		*right= tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcdef";
	reverse(arr);
	printf("%s\n",arr);
	return 0;
}