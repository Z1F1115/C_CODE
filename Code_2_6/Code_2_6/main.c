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

//�Ż������
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}

//�����Ż������
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//�ٴ��Ż�
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(src != NULL);//����
//	assert(dest != NULL);
//	char* ret = dest;//�Ȱ���ʼ��ַ��������
//	//��������ʼ��ַ������ĵ�ַҲ��Ӱ�췵����ʼ��ַ
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//����Ŀ��ռ����ʼ��ַ
//}
//
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxx";
//	char arr2[] = "hello";
//
//	printf("%s\n", my_strcpy(arr1, arr2));//��ʽ����
//	return 0;
//}


//��ϰ
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


//�����ϰ5
// ����һ  ���������������
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
//������  ���������������
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
//������
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
//�Ż�
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
//�Ż� ����һ
//int Number0f1(int n)
//{
//	if (n != 0)
//		return 1 + Number0f1(n = (n & (n - 1)));
//	return 0; 
//}
//�Ż� ������
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


//��ϰ дһ�������ж�һ�������ǲ���2��n�η�
//�Լ����   nΪ��������
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
//			printf("��2��%d�η�", i);
//			break;
//		}
//	}
//	if(i>n/2)
//		printf("����");
//}
//�ο����˵�  nΪ��������
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
//		printf("��2��%d�η�", i);
//	else
//		printf("����");
//}
//�ο����˵�  nΪ��������
//void ASS(int n)
//{
//	if ((n & (n - 1)) == 0)
//		printf("��2��n�η�");
//	else
//		printf("����2��n�η�");
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	ASS(n);
//	return 0;
//}


//�����ϰ3
//�Լ�д��
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
//�ο����˵�
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


//�����ϰ4
//int main()
//{
//	int n=  0;
//	scanf("%d",&n);
//	//ż��λ
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


//�����ϰ6
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