#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int main() {
//	FILE *pf =fopen("test.dat","w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//
//	//�ر��ļ�
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
//	//д�ļ�
//	fputc('b', pf);
//	fputc('c', pf);
//	fputc('d', pf);
//
//
//
//	//�ر��ļ�
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
//	//���ļ�
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
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() {
//
//	//���ļ�
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
//	//дһ��
//	fputs("qwer\n", pf);
//	fputs("asdf\n", pf);
//	fputs("zxcv\n", pf);
//
//	//�ر��ļ�
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
//	//��һ��(��n-1��)
//	int n = 5;
//	
//	fgets(pa, n, pf);
//	printf("%s\n",pa);
//
//	fgets(pa, n, pf);
//	printf("%s\n", pa);
//
//	//�ر��ļ�
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
//	//д�ļ�
//	fprintf(pf, "%s %d %f", s.arr, s.num, s.sc);
//
//	//�ر��ļ�
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
//	//���ļ�
//	fscanf(pf,"%s %d %f",s.arr,&s.num,&s.sc);
//
//	//��ӡ
//	printf("%s %d %f\n", s.arr, s.num, s.sc);
//
//	//�ر��ļ�
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
//	//д�ļ� - ������
//	fwrite(&s,sizeof(struct S),1,pf);
//
//	//�ر��ļ�
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
//	//���ļ� - ������
//	fread(&s,sizeof(struct S),1,pf);
//
//	//��ӡ
//	printf("%s %d %f\n", s.arr, s.num, s.sc);
//
//	//�ر��ļ�
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
//	//sprintf ��һ����ʽ�������飬ת�����ַ���
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.f);
//
//	printf("%s\n",buf);
//
//	sscanf(buf,"%s %d %f", tmp.arr,&tmp.age,&tmp.f);
//
//	printf("%s %d %f\n", tmp.arr, tmp.age, tmp.f);
//	return 0;
//}


//д�����test.txt�ļ�����һ�ݣ�����test2.txt
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
	//�ļ��򿪳ɹ�
	//��д�ļ�
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF) {
		fputc(ch, pfwrite);
	}

	if (feof(pfread)){
		printf("�����ļ�������־���ļ���������\n");
	}
	else if (ferror(pfread)) {
		printf("�ļ���ȡʧ�ܽ���\n");
	}

	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;

	return 0;
}