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
//		Sleep(1000);//˯��һ��
//		system("cls");//�����Ļ
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
//	//�����������ַ�����123465��
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//	}
//	if (3 == i)
//	{
//		printf("��������������˳�����\n");
//	}
//
//	return 0;
//}


//С��Ϸ
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
//	int ret = rand() % 100 + 1;//%100��������0-99��Ȼ��+1����Χ����1-100
//	//printf("%d\n", ret);
//	int guess = 0;
//	while (1)
//	{
//		printf("�������:>");
//		scanf("%d",&guess);
//		if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���\n");
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
//		menu();//��ӡ�˵�
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����,����ѡ��\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//��ϰ
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

//��ϰ
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

//��ϰ
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	//�������Լ��max����m��n�Ľ�Сֵ
//	int max = m < n ? m : n;
//
//	while (1)
//	{
//		if (m % max == 0 && n % max == 0)
//		{
//			printf("���Լ�����ǣ�%d\n", max);
//			break;
//		}
//		max--;
//	}
//	return 0;
//}

//����ѧ��շת�����
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
//			printf("���Լ�����ǣ�%d\n", n);
//			break;
//		}
//	}*/
//	while (t = m % n)
//	{
//		m = n;
//		n = t;
//	}
//	printf("���Լ�����ǣ�%d\n", n);
//	return 0;
//}


//��ӡ1000�굽2000��֮�������
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


//��ӡ100-200֮�������
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

//�Ż�����Ĵ���
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


//goto �ػ�С����
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//again:
//	printf("��ע�⣬��ĵ�����2�����ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input,"������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//����goto
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	while (1)
//	{
//		printf("��ע�⣬��ĵ�����2�����ڹػ���������룺��������ȡ���ػ�\n");
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

