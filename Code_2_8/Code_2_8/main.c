
#include <stdio.h>

//int check_sys()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	//if (*p == 1)
//	//{
//	//	return 1;
//	//}
//	//else
//	//{
//	//	return 0;
//	//}
//	return *p;//返回1为小端，返回0为大端
//}
//
//int main()
//{
//	//写代码判断当前机器的字节序
//	int ret = check_sys();
//	
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	//10000000000000000000000010000000-原码
//	//11111111111111111111111101111111-反码
//	//11111111111111111111111110000000-补码
//	//10000000
//	//11111111111111111111111110000000-整型提升
//	printf("%u\n",a);
//	
//	char b = 128;
//	//10000000000000000000000010000000-原码
//	//11111111111111111111111101111111-反码
//	//11111111111111111111111110000000-补码
//	//10000000
//	//11111111111111111111111110000000-整型提升
//	printf("%u\n", b);
//
//	return 0;
//}

// -128-1=127
//1000000000000000000000010000000 -128-原码
//1111111111111111111111101111111 -128-反码
//1111111111111111111111110000000 -128-补码
//1000000000000000000000000000001 -1-原码
//1111111111111111111111111111110 -1-反码
//1111111111111111111111111111111 -1-补码
//-128的补码减去-1的补码
//1111111111111111111111110000000 -128-补码
//1111111111111111111111111111111 -1-补码
//结果，超出32位
//10000000000000000000000001111111
//取右边开始数到32位
//0000000000000000000000001111111 127-补码

int main()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n",n);//9
	printf("*pFloat的值为：%f\n", *pFloat);
	//0000 0000 0000 0000 0000 0000 0000 1001
	//0 00000000 0000000000000000001001
	//S=0   E=1-127  M=0.0000000000000000001001
	//0
	*pFloat = 9.0;
	printf("num的值为：%d\n", n);
	//1001.0
	//1.001*2^3
	//E=0  M=1.001  E=3+127=130
	//E=0  M=001    E=130
	//0 10000010 00100000000000000000000
	//1091457616
	printf("*pFloat的值为：%f\n", *pFloat);//9.0

	return 0;
}