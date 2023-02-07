#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//编程题1
//int main()
//{
//	unsigned int a = 0;
//	unsigned int b = 0;
//	scanf("%d %d",&a,&b);
//  //方法二
//	int i = 0;
//	for (i = 1;; i++)
//	{
//		if (a * i % b == 0)
//		{
//			printf("最小公倍数是:%d\n", a*i);
//			break;
//		}
//	}
//  ////方法一
//	//int max = a > b ? a : b;
//	//while (1)
//	//{
//	//	if ((max % a) == 0 && (max % b) == 0)
//	//		break;
//	//	else
//	//		max++;
//	//}
//	//printf("最小公倍数是:%d\n",max);
//	return 0;
//}


//编程题2
#include <string.h>
void reverse(char * letf, char *right)
{
	while (letf<right)
	{
		char tmp = *letf;
		*letf = *right;
		*right = tmp;
		letf++;
		right--;
	}
	
}

int main()
{
	char arr[100] = "I like guangzhou.";
	//scanf("%s",arr);//这样不可以 
	gets(arr);
	//三步翻转法
	//1.字符串整体翻转
	int len = strlen(arr);
	reverse(arr, arr+len-1);
	//2.每个单词逆序
	char* start = arr;
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		//逆序单词
		reverse(start, end-1);
		if (*end == ' ')
		{
			start = end + 1;
		}
		else
			start = end;
	}
	
	printf("%s\n", arr);
	return 0;
}