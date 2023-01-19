#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//int main()
//{
//	char arr1[] = "welcmoe to zjf!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//睡眠一秒
//		system("cls");//清空屏幕
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	//假设密码是字符串“123465”
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//	}
//	if (3 == i)
//	{
//		printf("三次密码均错误，退出程序\n");
//	}
//
//	return 0;
//}


//小游戏
//void menu()
//{
//	printf("**************************\n");
//	printf("********  1.play  ********\n");
//	printf("********  0.exit  ********\n");
//	printf("**************************\n");
//}
//
//void game()
//{
//
//	int ret = rand() % 100 + 1;//%100的余数是0-99，然后+1，范围就是1-100
//	//printf("%d\n", ret);
//	int guess = 0;
//	while (1)
//	{
//		printf("请猜数字:>");
//		scanf("%d",&guess);
//		if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		menu();//打印菜单
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误,重新选择\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//练习
//int main()
//{
//	int a = 0, b = 0, c = 0, i= 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//练习
//int main()
//{
//	int i = 0;
//	for (i= 1; i < 100+1; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//练习
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	//假设最大公约数max就是m和n的较小值
//	int max = m < n ? m : n;
//
//	while (1)
//	{
//		if (m % max == 0 && n % max == 0)
//		{
//			printf("最大公约数就是：%d\n", max);
//			break;
//		}
//		max--;
//	}
//	return 0;
//}

//用数学的辗转相除法
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int t = 0;
//	scanf("%d %d", &m, &n);
//	/*while (1)
//	{
//		if ((t = m % n) != 0)
//		{
//			m = n;
//			n = t;
//		}
//		else
//		{
//			printf("最大公约数就是：%d\n", n);
//			break;
//		}
//	}*/
//	while (t = m % n)
//	{
//		m = n;
//		n = t;
//	}
//	printf("最大公约数就是：%d\n", n);
//	return 0;
//}


//打印1000年到2000年之间的闰年
//int main()
//{
//	int y = 0;
//	int a = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if ((y % 4 == 0) && (y % 100 != 0))
//		{
//			printf("%d ", y);
//			a++;
//		}
//		else if (y % 400 == 0)
//		{
//			printf("%d ", y);
//			a++;
//		}
//	}
//	printf("\n%d ", a);
//	return 0;
//}


//打印100-200之间的素数
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
//
//		}
//	}
//	return 0;
//}

//优化上面的代码
#include <math.h>
//int main()
//{
//	int i = 0;
//  //for (i = 101; i <= 200; i+=2)
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (1 == flag)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//goto 关机小程序
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//again:
//	printf("请注意，你的电脑在2分钟内关机，如果输入：你是猪，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input,"你是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//不用goto
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	while (1)
//	{
//		printf("请注意，你的电脑在2分钟内关机，如果输入：你是猪，就取消关机\n");
//		scanf("%s", input);
//		if (strcmp(input, "你是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

