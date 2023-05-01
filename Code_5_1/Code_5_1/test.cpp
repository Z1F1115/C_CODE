#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int main() {
//	FILE *pf =fopen("test.dat","w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main() {
//	FILE* pf = fopen("test.dat","w");
//	if (pf == NULL) {
//			perror("fopen");
//			return 1;
//	}
//
//	//写文件
//	fputc('b', pf);
//	fputc('c', pf);
//	fputc('d', pf);
//
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main() {
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//读文件
//	int ret = fgetc(pf);
//	if (ret == EOF) {
//		perror("fgetc");
//		return 1;
//	}
//	printf("%c\n",ret);
//	ret = fgetc(pf);
//	if (ret == EOF) {
//		perror("fgetc");
//		return 1;
//	}
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	if (ret == EOF) {
//		perror("fgetc");
//		return 1;
//	}
//	printf("%c\n", ret);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() {
//
//	//读文件
//	int ret = fgetc(stdin);
//	if (ret == EOF) {
//		perror("fgetc");
//		return 1;
//	}
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	if (ret == EOF) {
//		perror("fgetc");
//		return 1;
//	}
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	if (ret == EOF) {
//		perror("fgetc");
//		return 1;
//	}
//	printf("%c\n", ret);
//
//	return 0;
//}


//int main() {
//	FILE* pf = fopen("test.dat", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//写一行
//	fputs("qwer\n", pf);
//	fputs("asdf\n", pf);
//	fputs("zxcv\n", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main() {
//	char pa[10] = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//读一行(读n-1个)
//	int n = 5;
//	
//	fgets(pa, n, pf);
//	printf("%s\n",pa);
//
//	fgets(pa, n, pf);
//	printf("%s\n", pa);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//struct S {
//	char arr[10];
//	int num;
//	float sc;
//};

//int main() {
//	struct S s = { "abcdef",10,5.5f };
//	FILE* pf = fopen("test.dat", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fprintf(pf, "%s %d %f", s.arr, s.num, s.sc);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main() {
//	struct S s = {0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	fscanf(pf,"%s %d %f",s.arr,&s.num,&s.sc);
//
//	//打印
//	printf("%s %d %f\n", s.arr, s.num, s.sc);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main() {
//	struct S s = { "abcdef",10,5.5f };
//	FILE* pf = fopen("test.dat", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//写文件 - 二进制
//	fwrite(&s,sizeof(struct S),1,pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main() {
//	struct S s = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//读文件 - 二进制
//	fread(&s,sizeof(struct S),1,pf);
//
//	//打印
//	printf("%s %d %f\n", s.arr, s.num, s.sc);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//struct S {
//	char arr[10];
//	int age;
//	float f;
//};
//
//int main() {
//	struct S s = { "hello", 20, 5.5f };
//	struct S tmp = { 0 };
//	char buf[100] = { 0 };
//
//	//sprintf 把一个格式化的数组，转换成字符串
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.f);
//
//	printf("%s\n",buf);
//
//	sscanf(buf,"%s %d %f", tmp.arr,&tmp.age,&tmp.f);
//
//	printf("%s %d %f\n", tmp.arr, tmp.age, tmp.f);
//	return 0;
//}


//写代码吧test.txt文件拷贝一份，生成test2.txt
int main() {
	FILE* pfread = fopen("test.txt","r");
	if (pfread == NULL) {
		return 0;
	}
	FILE* pfwrite = fopen("test2.txt", "w");
	if (pfwrite == NULL) {
		fclose(pfread);
		pfread = NULL;
		return 0;
	}
	//文件打开成功
	//读写文件
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF) {
		fputc(ch, pfwrite);
	}

	if (feof(pfread)){
		printf("遇到文件结束标志，文件正常结束\n");
	}
	else if (ferror(pfread)) {
		printf("文件读取失败结束\n");
	}

	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;

	return 0;
}