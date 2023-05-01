#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_NAME  20
#define MAX_SEX   10
#define MAX_TELE  12
#define MAX_ADDR  30

#define DEFAULT_SZ 3
#define INC_SZ 2


//���͵Ķ���
typedef struct {
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼
typedef struct {
	PeoInfo* data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//ͨѶ¼�е�ǰ�ܹ��м���
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;

void InitContact(Contact* pc) {
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
}

void DestoryContact(Contact*& pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void AddContact(Contact*& pc) {
	if (pc->sz == pc->capacity) {
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL) {
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ���\n");
		}
		else {
			perror("AddContact");
			printf("������ϵ��ʧ��!\n");
			return;
		}
	}
	//����һ���˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ���\n");
}

void PrintContact(Contact*& pc) {
	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	int i = 0;
	printf("%-6s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	for (i = 0; i < pc->sz; i++) {
		printf("%-6s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int FindByName(Contact*& pc, char name[]) {
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}


void DelContact(Contact*& pc) {

	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}

	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);

	//1.����Ҫɾ������
	//��/û��
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫɾ�����˲�����\n");
		return;
	}

	//2.ɾ��
	for (i = pos; i < pc->sz - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�!\n");
}

void SearchContact(Contact*& pc) {
	char name[MAX_NAME] = { 0 };

	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else {
		printf("%-6s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//��ӡ����
		printf("%-6s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

void ModifyContact(Contact*& pc) {
	char name[MAX_NAME] = { 0 };

	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else {
		printf("����������:>");
		scanf("%s", pc->data[pos].name);
		printf("����������:>");
		scanf("%d", &pc->data[pos].age);
		printf("�������Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ���\n");
	}
}

//ͨѶ¼-��̬����
//1.ͨѶ¼��ʼ�����ܷ�3������Ϣ
// 1.2�����ǿռ�Ĵ����������2������Ϣ
//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼��Ϣ
//

void menu() {
	printf("**************************\n");
	printf("*** 1.add     2.del    ***\n");
	printf("*** 3.search  4.modify ***\n");
	printf("*** 5.sort    6.print  ***\n");
	printf("*** 0.exit             ***\n");
	printf("**************************\n");
}

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODUFY,
	SORT,
	PRINT
};

int main() {
	int input = 0;

	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	//��data����һ�������Ŀռ��ڶ�����
	//sz = 0
	//capacity��ʼ��Ϊ��ǰ���������
	InitContact(&con);
	Contact* c = &con;

	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(c);
			break;
		case DEL:
			DelContact(c);
			break;
		case SEARCH:
			SearchContact(c);
			break;
		case MODUFY:
			ModifyContact(c);
			break;
		case SORT:
			printf("�����ӹ���\n");
			break;
		case PRINT:
			PrintContact(c);
			break;
		case EXIT:
			//����ͨѶ¼
			DestoryContact(c);
			printf("�˳�ͨѶ¼!\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}