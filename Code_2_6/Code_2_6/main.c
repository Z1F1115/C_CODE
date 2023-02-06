#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}

//优化上面的
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}

//继续优化上面的
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//再次优化
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(src != NULL);//断言
//	assert(dest != NULL);
//	char* ret = dest;//先把起始地址保存起来
//	//保存了起始地址，后面改地址也不影响返回起始地址
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//返回目标空间的起始地址
//}
//
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxx";
//	char arr2[] = "hello";
//
//	printf("%s\n", my_strcpy(arr1, arr2));//链式访问
//	return 0;
//}


//练习
//#include <assert.h>
//unsigned int my_strlen(const char *str)
//{
//	assert(str != null);
//	const char*  ret = str;
//	while(*str++ != '\0')
//	{
//		;
//	}
//	return str - ret - 1;
//}
//
//int main()
//{
//	char arr[] = "assassin";
//	printf("%d\n",my_strlen(arr));
//
//	return 0;
//}


//编程练习5
// 方法一  如果传负数，则不行
//int Number0f1(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n % 2 == 0)
//	{
//		return Number0f1(n / 2);
//	}
//	else 
//	{
//		return 1 + Number0f1(n / 2);
//	}
//}
//方法二  如果传负数，则不行
//int Number0f1(int n)
//{
//	static int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n /= 2;
//	}
//	return count;
//}
//方法三
//int Number0f1(int n)
//{
//	static int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n & 1) == 1)
//		{
//			count++;
//			n = n >> 1;
//		}
//		else
//		{
//			n = n >> 1;
//		}
//	}
//	return count;
//}
//优化
//int Number0f1(int n)
//{
//	static int count = 0;
//	int i = 0;
//	for (i=0;i<32;i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//优化 方法一
//int Number0f1(int n)
//{
//	if (n != 0)
//		return 1 + Number0f1(n = (n & (n - 1)));
//	return 0; 
//}
//优化 方法二
//int Number0f1(int n)
//{
//	static int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int ret = Number0f1(n);
//	printf("ret = %d\n",ret);
//
//	return 0;
//}


//练习 写一个代码判断一个数字是不是2的n次方
//自己想的   n为负数不行
//void ASS(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n / 2; i++)
//	{
//		int j = 0;
//		int m = 1;
//		for (j=0;j<i;j++)
//		{
//			m = m * 2;
//		}
//		if (n == m)
//		{
//			printf("是2的%d次方", i);
//			break;
//		}
//	}
//	if(i>n/2)
//		printf("不是");
//}
//参考别人的  n为负数不行
//void ASS(int n)
//{
//	int i = 0;
//	int m = n;
//	for (i = 1; i <= 32; i++)
//	{
//		if ((m=(m / 2)) == 1)
//			break;
//		
//	}
//	if((n&(n-1)) == 0)
//		printf("是2的%d次方", i);
//	else
//		printf("不是");
//}
//参考别人的  n为负数不行
//void ASS(int n)
//{
//	if ((n & (n - 1)) == 0)
//		printf("是2的n次方");
//	else
//		printf("不是2的n次方");
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	ASS(n);
//	return 0;
//}


//编程练习3
//自己写的
//int cmp(int n,int m)
//{
//	int i = 0;
//	int count = 0 ;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) != ((m >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//参考别人的
//int numberof1(int num)
//{
//	int i = 0;
//	int count = 0;
//	while (num)
//	{
//		num = num & (num - 1);
//		count++;
//	}
//	return count;
//}
//int cmp(int n, int m)
//{
//	int num = n ^ m;
//	return numberof1(num);
//}
//
//int main()
//{
//	int n = 0;//22-000010110
//	int m = 0;//33-000100001
//	scanf("%d %d",&n,&m);
//	int ret = cmp(n, m);
//	printf("ret = %d\n", ret);
//	return 0;
//}


//编程练习4
//int main()
//{
//	int n=  0;
//	scanf("%d",&n);
//	//偶数位
//	int i = 0;
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf(" %d", (n >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}


//编程练习6
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d",&n,&m);
	n = n ^ m;
	m = n ^ m;
	n = n ^ m;
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	return 0;
}