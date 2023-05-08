#include "Library.h"

void menu2() {

	printf("--------------------------\n");
	printf("|        ��¼ѡ��        |\n");
	printf("|        1.�Ѿ����˺�    |\n");
	printf("|        2.ע���˺�      |\n");
	printf("|        0.�˳�ѧ����½  |\n");
	printf("--------------------------\n");
}

void CheckCapacity(Account* pc) {
	if (pc->sz == pc->Max_Account) {
		Student_Account* ptr = (Student_Account*)realloc(pc->data,(pc->Max_Account + INC_SZ) * sizeof(Student_Account));
		if (NULL == ptr) {
			pc->data = ptr;
			pc->Max_Account += INC_SZ;
		}
		else {
			perror("AddAccount");
			printf("���ӽṹ������ʧ��\n");
			return;
		}
	}
}

void LoadAccount(Account *pc) {
	FILE* pf = fopen("account.txt","r");
	if (NULL == pf) {
		perror("LoadAccount");
		return;
	}

	//��ȡ�ļ�����
	Student_Account tmp = { 0 };
	while (fread(&tmp, sizeof(Student_Account), 1, pf)) {
		//�Ƿ���Ҫ��������
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

void InitAccount(Account *pc) {
	pc->data = (Student_Account*)malloc(DEFAULT_SZ * sizeof(Student_Account));
	if (NULL == pc->data) {
		perror("InitAccount");
		return;
	}
	pc->sz = 0;
	pc->Max_Account = DEFAULT_SZ;

	//�����ļ�����
	LoadAccount(pc);
}

void SaveAccount(Account* pc) {
	FILE *pf = fopen("account.txt","w");
	if (NULL == pf) {
		perror("SaveAccount");
		return;
	}

	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz;i++) {
		fwrite((pc->data + i), sizeof(Student_Account), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

void Student_Login(Account* pc) {
	int i = 0;
	Student_Account n = { 0 };
	printf("����ѧ�����˺ţ�");
	scanf("%s", n.accounts);
	for (i = 0; i < pc->sz; i++) {
		if (0 == (strcmp(n.accounts, pc->data[i].accounts))) {
			break;
		}
	}
	if (i == pc->sz) {
		printf("�˺Ų����ڣ�\n");
		return;
	}
	printf("����ѧ�����˺����룺");
	scanf("%s", n.password);
	if ((strcmp(n.password, pc->data[i].password)) != 0) {
		printf("�������\n");
		return;
	}
	else {
		system("cls");
		printf("����ѧ��ϵͳ��\n");
		StudentSystems(pc, n.accounts);
	}
}

void Student_Enroll(Account* pc) {
	int i = 0;
	Student_Account n = {0};
	CheckCapacity(pc);
	printf("�˺����10λ���������16λ\n");
	printf("������ע����˺ţ�");
	scanf("%s", n.accounts);
	for (i = 0; i < pc->sz; i++) {
		if (0 == (strcmp(n.accounts,pc->data[i].accounts))) {
			printf("�˺��Ѿ����ڣ�\n");
			return;
		}
	}
	if (i == pc->sz)
		strcpy(pc->data[i].accounts, n.accounts);
	printf("������ע������룺");
	scanf("%s", pc->data[i].password);

	pc->sz++;
	printf("�˺Ŵ����ɹ���\n");
}


void Student(Account *con) {
	int input2 = 0;
	
	do {
		menu2();
		printf("��ѡ��:>");
		scanf("%d", &input2);
		switch (input2) {
		case 1://�Ѿ����˺�
			Student_Login(con);
			break;
		case 2://ע���˺�
			Student_Enroll(con);
			break;
		case 0:
			printf("�˳�ѧ����½\n");
			break;
		default:
			printf("û�����ѡ��������ѡ��\n");
			break;
		}
	} while (input2);

}