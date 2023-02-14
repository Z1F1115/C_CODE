#include <stdio.h>


//Õâ¸öÃ°ÅİÅÅĞò±È½ÏËÀ°å
//void bubble_sort(int * arr, int sz)
//{
//	int i = 0;
//	for (i=0;i<sz-1;i++)
//	{
//		int j = 0;
//		for (j=0;j<sz-1-i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = *(arr + j);
//				*(arr + j) = *(arr + j + 1);
//				*(arr + j + 1) = tmp;
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	int  arr[10] = { 9,8,7,6,50,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//
//	return 0;
//}

#include <stdlib.h>
int cmp_int(const void * e1 ,const void * e2)
{
	return (*(int*)e1 - *(int*)e2);//ÉıĞò
}
int main()
{
	int arr[10] = { 9,8,7,6,50,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz,sizeof(arr[0]), cmp_int);

	return 0;
}