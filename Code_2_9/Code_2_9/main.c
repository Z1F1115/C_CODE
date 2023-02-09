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
//	//上面的*p == arr == *p1
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
//	int arr[5] = {0};          //整型数组
//	int* parr1[10] = {NULL};   //整型指针数组
//	int(*parr2)[10];		   //数组指针
//	//上面的数组指针能够指向一个数组，数组10个元素，每个元素的类型是int
//	int(*parr3[10])[5];		   //数组指针数组
//	//上面的parr3是一个存储数组指针的数组
//	//该数组能够存放10个数组指针
//	//每个数组指针能够指向一个数组，数组5个元素，每个元素是int类型
//
//
//	return 0;
//}


//编程练习8
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
//	printf("输入多少相：>");
//	scanf("%d", &b);
//	int ret = Add(a,b);
//	printf("%d\n",ret);
//	return 0;
//}


//编程练习9
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


//编程练习10
//自己想的
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)//i=153
//	{
//		int count = 0;//计算i有几位
//		int n = i;
//		int m = i;
//		int a = 0;
//		int sum = 0;
//		int j = 0;
//		while (n)//i多少位
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

//优化上面的练习
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)//i=153
//	{
//		int count = 0;//计算i有几位
//		int n = i;
//		int a = 0;
//		int sum = 0;
//		int j = 0;
//		while (n)//i多少位
//		{
//			count++;
//			n = n / 10;
//		}
//		n = i;
//		while (n)//计算i的每一位n次方之和
//		{
//			sum = sum + (int)pow(n % 10, count);
//			n = n / 10;
//		}
//		if (sum == i)//判断
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//指针编程题
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