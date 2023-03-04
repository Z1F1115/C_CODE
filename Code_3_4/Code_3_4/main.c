#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int find_num(int arr[10][10], int *px, int *py ,int k) {
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0) {
		if (arr[x][y] < k) {
			x++;
		}
		else if (arr[x][y] > k) {
			y--;
		}
		else {
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

//编程题10
//int main()
//{
//	int a[10][10] = { 0 };
//	int i = 0, j = 0;
//	int n = 1;
//	for (i = 0; i < 10; i++) {
//		n = 1;
//		for (j = 0; j < 10; j++) {
//			a[i][j] = n+i;
//			n++;
//		}
//	}
//	int k = 12;
//	int x = 10;
//	int y = 10;
//	int ret = find_num(a, &x, &y, k);
//	if (ret) {
//		printf("%d存在矩阵中\n", k);
//	}
//	else {
//		printf("%d不存在矩阵中\n", x);
//	}
//
//
//	//不符合要求
//	/*for (i = 0; i < 10; i++) {
//		if (a[i][0] <= x && a[i][9] >= x) {
//			printf("%d存在矩阵中\n",x);
//			b = 0;
//			break;
//		}
//	}
//	if (b) {
//		printf("%d不存在矩阵中\n", x);
//	}*/
//
//	return 0;
//}

//编程5方法一
//void string_cotate(char *arr, int k,int s)
//{
//	int i = 0;
//	for (i = 0; i < k; i++) {
//		int j = 0;
//		char tmp = *arr;
//		for (j = 0; j < s - 1;j++) {
//			*(arr + j) = *(arr + j + 1);
//		}
//		*(arr + j) = tmp;
//	}
//}
// 
//方法二 ,三部翻转法
#include <assert.h>
void reverse(char* left, char* right) {
	assert(left);
	assert(right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void string_cotate(char* arr, int k, int s) {
	assert(arr);
	reverse(arr,arr+k-1);

	reverse(arr+k,arr+s-1);

	reverse(arr ,arr+s-1);

}
//编程5
//#include <string.h>
//int main()
//{
//	char arr[] = "ABCDEF";
//	unsigned int sz = (int)strlen(arr);
//	int n = 0;
//	int y = 0;
//	printf("旋转几个字符:>");
//	scanf("%d",&n);
//	if(y = n % sz ) string_cotate(arr,y,sz);
//	printf("%s\n",arr);
//
//	return 0;
//}

#include <string.h>
#include <assert.h>
int string_cmp(char s1[], char s2[], int* count) {
	int len = (int)strlen(s1);
	int i = 0;
	if (strcmp(s1, s2) != 0) {
		for (i = 0; i < len; i++) {
			char tmp = s1[0];
			int j = 0;
			for (j = 0; j < len - 1; j++) {
				s1[j] = s1[j + 1];
			}
			s1[j] = tmp;
			if (0 == strcmp(s1, s2)) {
				*count = i+1;
				return 1;
			}
		}
	}
	else{
		*count = i+1;
		return 1;
	}
	return 0;
}

//编程6
int main(){
	char s1[] = "AABCD";
	char s3[] = "AABCD";
	char s2[] = "BCDAA";
	//char s1[] = "ACBD";
	//char s2[] = "abcd";
	int count = 0;
	int ret = string_cmp(s1, s2,&count);
	if (ret) {
		printf("%s左旋%d个字符得到%s\n",s3,count,s2);
	}
	else {
		printf("不相等\n");
	}
	return 0;
}