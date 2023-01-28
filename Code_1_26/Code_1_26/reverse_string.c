#include <stdio.h>
#include "reverse_string.h"
#include "my_strlen.h"

//第一种
//void reverse_string(char* str)
//{
//	int left = 0;
//	int right = my_strlen(str)-1;
//	while (left < right)
//	{
//		char tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}

//第二种
//void reverse_string(char* str)
//{
//	int left = 0;
//	int right = my_strlen(str) - 1;
//	while (left < right)
//	{
//		char tmp = *(str+left);
//		*(str + left) = *(str+right);
//		*(str + right) = tmp;
//		left++;
//		right--;
//	}
//}

//第三种
void reverse_string(char* str)
{
	char tmp = *str;
	int len = my_strlen(str)-1;
	*str = *(str + len);
	*(str + len ) = '\0';
	if (my_strlen(str+1)>=2)
	{
		reverse_string(str + 1);
	}
	*(str + len) = tmp;
}