#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int a = 0;
//	int b = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (1 == a %2 )
//		{
//			b++;
//			printf("%d\n", a);
//		}
//	}
//	printf("有多少个奇数：%d", b);
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		if (1 == a % 2)
//			printf("%d\n",a);
//		a++;
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	for (a = 1; a <= 100; a+=2)	
//			printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf("%s", password);
//	printf("请确认密码(Y/N):>");
//	int tmp = 0;
//	while ((tmp = getchar()) != '\n')
//	{	
//		;
//    }
//	int ch = getchar();
//	if ('Y' == ch)
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//
//	return 0;
//}

//练习1
//int main()
//{
//	int a = 0;
//	int ret = 1;
//	int n = 0;
//	printf("请输入n的值:>");
//	scanf("%d", &n);
//	for (a = 1; a < n+1; a++)
//	{
//		ret = a * ret;
//	}
//	printf("%d\n",ret);
//
//	return 0;
//}

//练习2
//int main()
//{
//	int a = 0;
//	int ret = 1;
//	int sum = 0;
//	for (a = 1; a < 10+1; a++)
//	{
//		ret *= a;
//		sum += ret;
//	}
//	printf("%d\n",sum);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//	for (n = 1; n < 10+1; n++)
//	{
//		int ret = 1;
//		for (a = 1; a < n+1;a++)
//		{
//			ret *= a;
//		}
//		sum += ret;
//	}
//	printf("%d\n",sum);
//	return 0;
//}

//练习3
//int main()
//{
//	int n = 0, i = 0;
//	int num[20] = { 0 };
//	printf("输入有序数组:>");
//	scanf("%d", num);
//	printf("输入要查找的数字:>");
//	scanf("%d", &n);
//	while (1)
//	{
//		if (n == num[i])
//		{
//			printf("%d\n", num[i]);
//			break;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return 0;
//}

//二分查找
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	printf("输入要查找的数字:>");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;

		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，下标是:%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到了\n");
	}

	return 0;
}