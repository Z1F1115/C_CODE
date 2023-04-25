#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//157  第一题改正
//void GetMemory(char *&p) {
//	p = (char*)malloc(100);
//}
//
//void Test(void) {
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str); 
//	free(str);
//	str = NULL;
//}
//
//int main() {
//	Test();
//	return 0;
//}


//第二题改
//char* GetMemory(void) {
//	static char p[] = "hello world";
//	return p;
//}
//
//void Test(void) {
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main() {
//	Test();
//	return 0;
//}


//第三题没有释放堆空间（动态内存）
//void GetMemory(char** p, int num) {
//	*p = (char*)malloc(num);
//}
//
//void Test() {
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str,"hello world");
//	printf(str);
//}
//
//int main() {
//	Test();
//	return 0;
//}


//非法访问，free已经释放了。
//void Test() {
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	//改正
//	//str = NULL;
//	if (str != NULL) {
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main() {
//	Test();
//	return 0;
//}

//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;
//int_ptr c, d;
////上面定义b变量不是指针类型
////因为#define是替换        int *a,b;
////而typedef是类型重新定义  int *c,*d;


//柔性数组
////第一种
////struct S{
////	int n;
////	int arr[];//大小是未知
////};
//
////第二种
//struct S {
//	int n;
//	int arr[0];//大小是未知
//};
//
//int main() {
//	//错误的创建
//	//struct S s = { 0 };
//	//printf("%d\n", sizeof(s));
//
//
//	//正确
//	struct S *ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		ps->arr[i] = i;
//	}
//	//增加空间
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL) {
//		ps = ptr;
//	}
//	//使用
//
//	//释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}


//struct S {
//	int n;
//	int* arr;
//};
//
//int main() {
//	struct S *ps = (struct S*)malloc(sizeof(struct S));
//	if (ps == NULL) {
//		return 1;
//	}
//	ps->n = 10;
//	ps->arr = (int *)malloc(10 * sizeof(int));
//	if (ps->arr == NULL) {
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		ps->arr[i] = i;
//	}
//	//增加
//	int * ptr = (int *)realloc(ps->arr, 20 * sizeof(int));
//	if (ptr !=NULL) {
//		ps->arr = ptr;
//	}
//
//	//使用
//
//	//释放
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}


//作业 x形图案
//int main() {
//	int n = 0;
//	int i = 0,j = 0;
//	printf("输入x形图案的高度(高度大于2并且小于20):>");
//	scanf("%d", &n);
//	if (n >= 2 && n <= 20) {
//		for (i = 0; i < n; i++) {
//			for (j = 0; j < n; j++) {
//				if (j == i)
//					printf("*");
//				else if (n - 1 == j + i)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//作业 公务员面试 自己想的
//int main() {
//	int i = 0,j = 0;
//	int sum = 0;
//	int arr[7] = { 0 };
//
//	//输入7个成绩
//	printf("输入:");
//	scanf("%d %d %d %d %d %d %d", &arr[0],
//								  &arr[1],
//								  &arr[2],
//								  &arr[3],
//								  &arr[4],
//								  &arr[5],
//								  &arr[6]);
//	
//	
//	//冒泡排序
//	for (i = 0; i < 7; i++) {
//		for (j = i + 1; j < 7;j++) {
//			if (arr[i] < arr[j]) {
//				int tmp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//
//	for (i = 1; i < 7 - 1; i++) {
//		sum += arr[i];
//	}
//
//	printf("输出：%.2f\n", sum / 5.0);
//
//	return 0;
//}

//上面的公务员题目 参考别人优化过的
//int main() {
//	int arr = 0;
//	int sum = 0;
//	int i = 0;
//	int max = 0;
//	int min = 100;
//
//	for (i = 0; i < 7; i++) {
//		scanf("%d", &arr);
//		sum += arr;
//		if (arr > max)
//			max = arr;
//		if (arr < min)
//			min = arr;
//	}
//
//	printf("输出：%.2f\n", (sum - max - min) / 5.0);
//
//	return 0;
//}


//作业 获得月份天数
//int main() {
//	int month = 0,year = 0;
//	int count = 0;
//	printf("输入年份和月份:>");
//	scanf("%d %d",&year,&month);
//	if (month >= 1 && month <= 12) {
//		switch (month) {
//		case 2:
//			if (year % 4 == 0){
//				if(year % 100 != 0 
//				|| year % 400 == 0)
//					count = 29;
//			}
//			else
//				count = 28;
//			break;
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			count = 31;
//			break;
//		default:
//			count = 30;
//			break;
//		}
//	}
//		
//	printf("有%d天", count);
//
//	return 0;
//}

//作业 获得月份天数 参考别人的
int main() {
	int y = 0;
	int m = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	while (scanf("%d %d", &y, &m) != EOF) {
		int day = days[m];

		if (m == 2) {
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
				day += 1;
			}
		}
		
		printf("%d\n",day);
	}

	return 0;
}