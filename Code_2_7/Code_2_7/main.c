#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�����1
//int main()
//{
//	unsigned int a = 0;
//	unsigned int b = 0;
//	scanf("%d %d",&a,&b);
//  //������
//	int i = 0;
//	for (i = 1;; i++)
//	{
//		if (a * i % b == 0)
//		{
//			printf("��С��������:%d\n", a*i);
//			break;
//		}
//	}
//  ////����һ
//	//int max = a > b ? a : b;
//	//while (1)
//	//{
//	//	if ((max % a) == 0 && (max % b) == 0)
//	//		break;
//	//	else
//	//		max++;
//	//}
//	//printf("��С��������:%d\n",max);
//	return 0;
//}


//�����2
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
	//scanf("%s",arr);//���������� 
	gets(arr);
	//������ת��
	//1.�ַ������巭ת
	int len = strlen(arr);
	reverse(arr, arr+len-1);
	//2.ÿ����������
	char* start = arr;
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		//���򵥴�
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