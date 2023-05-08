#include "Library.h"

void menu3() {
	printf("----------------------------\n");
	printf("|        ����Աϵͳ        |\n");
	printf("|        1.�鿴�����鱾    |\n");
	printf("|        2.����鱾        |\n");
	printf("|        3.ɾ���鱾        |\n");
	printf("|        4.�鿴�ѽ����鱾  |\n");
	printf("|        5.�鿴δ�����鱾  |\n");
	printf("|        6.�������������鱾|\n");
	printf("|        7.�޸��鱾��Ϣ    |\n");
	printf("|        8.�鿴ѧ���˺�    |\n");
	printf("|        9.ɾ��ѧ���˺�    |\n");
	printf("|     10.�޸�ѧ���˺ŵ�����|\n");
	printf("|        0.�˳�����Աϵͳ  |\n");
	printf("----------------------------\n");
}

void menu4() {
	printf("----------------------------\n");
	printf("|        ѧ��ϵͳ          |\n");
	printf("|        1.�鿴�����鱾    |\n");
	printf("|        2.�鿴δ���鱾    |\n");
	printf("|        3.�������������鱾|\n");
	printf("|        4.���鱾          |\n");
	printf("|        5.���鱾          |\n");
	printf("|        0.�˳�ѧ��ϵͳ    |\n");
	printf("----------------------------\n");
}

void menu5() {
	printf("------------------------------\n");
	printf("|        1.�޸��鱾�����    |\n");
	printf("|        2.�޸��鱾������    |\n");
	printf("|        3.�޸��鱾���Ƿ񱻽�|\n");
	printf("|        4.�޸Ľ�������Ϣ    |\n");
	printf("|        0.�˳��޸�          |\n");
	printf("------------------------------\n");
}

//����Ա������---------------------------------------
void CheckCapacity1(BookLibrary* pa) {
	if (pa->size == pa->Max_Book) {
		Book* ptr = (Book*)realloc(pa->bookdata,(pa->Max_Book + INC_SZ) * sizeof(Book));
		if (ptr != NULL) {
			pa->bookdata = ptr;
			pa->Max_Book += INC_SZ;
		}
		else {
			perror("AddBook");
			printf("���ӽṹ������ʧ��\n");
			return;
		}
	}
}

void LoadBook(BookLibrary* pa) {
	FILE* pf = fopen("bookdata.txt","r");
	if (NULL == pf) {
		perror("LoadBook");
		return;
	}
	//���ļ�
	Book tmp = { 0 };
	while (fread(&tmp, sizeof(Book), 1, pf)) {
		//�Ƿ���Ҫ����
		CheckCapacity1(pa);
		//����
		pa->bookdata[pa->size] = tmp;
		pa->size++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

void InitLibrary(BookLibrary *pa) {
	pa->bookdata = (Book*)malloc(DEFAULT_SZ * sizeof(Book));
	if (NULL == pa->bookdata) {
		perror("InitLibrary");
		return;
	}
	pa->size = 0;
	pa->Max_Book = DEFAULT_SZ;

	//�����ļ�����
	LoadBook(pa);
}

void AddBook(BookLibrary* pa) {
	int i = 0;
	Book n = {0};

	CheckCapacity1(pa);
	//����鱾��Ϣ
	printf("������ţ�");
	scanf("%d",&n.number);
	for (i = 0; i < pa->size;i++) {
		if (n.number == pa->bookdata[i].number) {
			printf("����Ѿ�����!\n");
			return;
		}
	}
	printf("����������");
	scanf("%s", n.name);
	for (i = 0; i < pa->size; i++) {
		if (0 == strcmp(n.name,pa->bookdata[i].name)) {
			printf("�����Ѿ�����!\n");
			return;
		}
	}
	if (i == pa->size) {
		pa->bookdata[i] = n;
	}

	pa->size++;
	printf("����鱾�ɹ���\n");
}

void MLookBooks(BookLibrary* pa) {
	if (0 == pa->size) {
		printf("���Ϊ��\n");
		return;
	}
	int i = 0;
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
			"���", "����","�Ƿ񱻽�","�����˺�");

	for (i = 0; i < pa->size; i++) {
		printf("%-6d\t��%-8s��\t %-9d\t %-8s\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode,
				pa->bookdata[i].information);
	}
	printf("����һ����%d����\n",pa->size);
}

int FindByName(BookLibrary* pa, char name[]) {
	int i = 0;
	for (i = 0; i < pa->size; i++) {
		if (0 == strcmp(pa->bookdata[i].name,name)) {
			return i;
		}
	}
	return -1;
}

void DelBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("���Ϊ�գ��޷�ɾ��\n");
		return;
	}

	printf("������Ҫɾ��������֣�");
	scanf("%s",name);

	//����Ҫɾ�����飻�л�û��
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("Ҫɾ�����鲻����\n");
		return;
	}

	//ɾ��
	for (i = pos; i < pa->size - 1;i++) {
		pa->bookdata[i] = pa->bookdata[i + 1];
	}
	pa->size--;
	printf("ɾ���ɹ�!\n");
}

void YLookBooks(BookLibrary* pa) {
	if (pa->size == 0) {
		printf("���Ϊ��\n");
		return;
	}

	int i = 0,j = 0;
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
		"���", "����", "�Ƿ񱻽�", "�����˺�");

	for (i = 0; i < pa->size;i++) {
		if (1 == pa->bookdata[i].mode) {
			printf("%-6d\t��%-8s��\t %-9d\t %-8s\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode,
				pa->bookdata[i].information);
			j++;
		}
	}
	printf("��%d��������\n",j);
}

void NLookBooks(BookLibrary* pa) {
	if (pa->size == 0) {
		printf("���Ϊ��\n");
		return;
	}

	int i = 0, j = 0;
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
		"���", "����", "�Ƿ񱻽�", "�����˺�");

	for (i = 0; i < pa->size; i++) {
		if (0 == pa->bookdata[i].mode) {
			printf("%-6d\t��%-8s��\t %-9d\t %-8s\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode,
				pa->bookdata[i].information);
			j++;
		}
	}
	printf("����%d��û�б�����\n", j);
}

void InputNameByBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("���Ϊ�գ��޷�����\n");
		return;
	}

	printf("������Ҫ�����������:");
	scanf("%s", name);

	//����Ҫ���飻�л�û��
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("�鲻����\n");
		return;
	}

	//��ӡ����
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
		"���", "����", "�Ƿ񱻽�", "�����˺�");
	printf("%-6d\t��%-8s��\t %-9d\t %-8s\n",
		pa->bookdata[pos].number,
		pa->bookdata[pos].name,
		pa->bookdata[pos].mode,
		pa->bookdata[pos].information);
}

//�޸�-----------------------
void ModifyNumber(BookLibrary* pa, int pos) {
	printf("�����������:");
	scanf("%d", &pa->bookdata[pos].number);
}

void ModifyName(BookLibrary* pa, int pos) {
	printf("������������:");
	scanf("%s", pa->bookdata[pos].name);
}

void ModifyMode(BookLibrary* pa, int pos) {
	printf("�����������״̬:");
	scanf("%d", &pa->bookdata[pos].mode);
}

void ModifyInformation(BookLibrary* pa, int pos) {
	printf("�������µĽ����˺�:");
	scanf("%s", pa->bookdata[pos].information);
}
//---------------------------
void ModifyBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("���Ϊ�գ����鱾�����޸�\n");
		return;
	}

	printf("������Ҫ�޸��鱾������:");
	scanf("%s", name);

	//����Ҫ���飻�л�û��
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("�鲻����\n");
		return;
	}

	//�޸���Ϣ
	int input5 = 0;
	do {
		menu5();
		printf("��ѡ��:>");
		scanf("%d", &input5);
		switch (input5) {
		case 1://�޸��鱾�����
			ModifyNumber(pa,pos);
			break;
		case 2://�޸��鱾������
			ModifyName(pa, pos);
			break;
		case 3://�޸��鱾���Ƿ񱻽�
			ModifyMode(pa, pos);
			break;
		case 4://�޸Ľ�������Ϣ
			ModifyInformation(pa, pos);
			break;
		case 0:
			printf("�˳��޸�\n");
			break;
		default:
			printf("û�����ѡ��������ѡ��\n");
			break;
		}
	} while (input5);
}

void LookStudent(Account* pc) {
	if (pc->sz == 0) {
		printf("ѧ���˺�Ϊ��\n");
		return;
	}

	int i = 0;
	printf("%-11s\t%-17s\n",
		"�˺�", "����");
	for (i = 0; i < pc->sz; i++) {
		printf("%-11s\t%-17s\n",
			pc->data[i].accounts,
			pc->data[i].password);
	}
}

int FindByAccounts(Account* pc,char accounts[]) {
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].accounts, accounts) == 0) {
			return i;
		}
	}
	return -1;
}

void DelStudent(Account* pc) {
	char accounts[10] = { 0 };
	int i = 0;

	if (pc->sz == 0) {
		printf("û��ѧ���˺ţ�����ɾ��\n");
		return;
	}

	printf("������Ҫɾ�����˺�:");
	scanf("%s", accounts);


	int pos = FindByAccounts(pc, accounts);
	if (pos == -1) {
		printf("Ҫɾ�����˲�����\n");
		return;
	}

	for (i = pos; i < pc->sz - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�!\n");

}

void ModifyPassword(Account* pc) {
	char accounts[10] = { 0 };
	int i = 0;

	if (pc->sz == 0) {
		printf("û��ѧ���˺ţ��޷��޸�\n");
		return;
	}

	printf("������Ҫ�޸ĵ��˺�:");
	scanf("%s", accounts);

	int pos = FindByAccounts(pc, accounts);
	if (pos == -1) {
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else {
		printf("���������룺");
		scanf("%s",pc->data[pos].password);
		printf("�޸�����ɹ���\n");
	}
}

void DestoryLibrary(BookLibrary* pa) {
	free(pa->bookdata);
	pa->bookdata = NULL;
	pa->size = 0;
	pa->Max_Book = 0;
}

void SaveBooks(BookLibrary* pa) {
	//���ļ�
	FILE* pf = fopen("bookdata.txt", "w");
	if (pf == NULL) {
		perror("SaveBooks");
		return;
	}

	//д�ļ�
	int i = 0;
	for (i = 0; i < pa->size;i++) {
		fwrite(pa->bookdata+i,sizeof(Book),1,pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
//---------------------------------------------------

//ѧ��������-----------------------------------------
void SMLookBooks(BookLibrary* pa) {
	if (0 == pa->size) {
		printf("���Ϊ��\n");
		return;
	}
	int i = 0;
	printf("%-6s\t %-8s\t %-2s\n",
		"���", "����", "�Ƿ񱻽�");

	for (i = 0; i < pa->size; i++) {
		printf("%-6d\t��%-8s��\t %-9d\n",
			pa->bookdata[i].number,
			pa->bookdata[i].name,
			pa->bookdata[i].mode);
	}
	printf("����һ����%d����\n", pa->size);
}

void SNLookBooks(BookLibrary* pa) {
	if (pa->size == 0) {
		printf("���Ϊ��\n");
		return;
	}

	int i = 0, j = 0;
	printf("%-6s\t %-8s\t %-2s\n",
		"���", "����", "�Ƿ񱻽�");

	for (i = 0; i < pa->size; i++) {
		if (0 == pa->bookdata[i].mode) {
			printf("%-6d\t��%-8s��\t %-9d\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode);
			j++;
		}
	}
	printf("����%d��û�б�����\n", j);
}

void SInputNameByBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("���Ϊ�գ��޷�����\n");
		return;
	}

	printf("������Ҫ�����������:");
	scanf("%s", name);

	//����Ҫ���飻�л�û��
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("�鲻����\n");
		return;
	}

	//��ӡ����
	printf("%-6s\t %-8s\t %-2s\n",
		"���", "����", "�Ƿ񱻽�");
	printf("%-6d\t��%-8s��\t %-9d\n",
		pa->bookdata[pos].number,
		pa->bookdata[pos].name,
		pa->bookdata[pos].mode);
}

void BorrowBook(BookLibrary* pa,char *acc) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("���Ϊ�գ��޷���\n");
		return;
	}

	printf("������Ҫ���������:");
	scanf("%s", name);

	//����Ҫ���飻�л�û��
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("�鲻����\n");
		return;
	}
	else {
		pa->bookdata[pos].mode = 1;
		strcpy(pa->bookdata[pos].information , acc);
		printf("����ɹ���\n");
	}
}

void AlsoBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("���Ϊ�գ��޷���\n");
		return;
	}

	printf("������Ҫ���������:");
	scanf("%s", name);

	//����Ҫ���飻�л�û��
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("�鲻����\n");
		return;
	}
	else {
		pa->bookdata[pos].mode = 0;
		strcpy(pa->bookdata[pos].information, "0");
		printf("����ɹ���\n");
	}
}

//---------------------------------------------------

void ManagerSystems(Account* con) {
	int input4 = 0;
	//��������
	BookLibrary ang;
	//��ʼ��
	InitLibrary(&ang);

	do {
		menu3();
		printf("��ѡ��:>");
		scanf("%d", &input4);
		switch (input4) {
		case 1:
			//�鿴�鱾
			MLookBooks(&ang);
			break;
		case 2:
			//����鱾
			AddBook(&ang);
			break;
		case 3:
			//ɾ���鱾
			DelBook(&ang);
			break;
		case 4:
			//�鿴�ѽ����鱾
			YLookBooks(&ang);
			break;
		case 5:
			//�鿴δ�����鱾
			NLookBooks(&ang);
			break;
		case 6:
			//�������������鱾
			InputNameByBook(&ang);
			break;
		case 7:
			//�޸��鱾״̬
			ModifyBook(&ang);
			break;
		case 8:
			//�鿴ѧ���˺�
			LookStudent(con);
			break;
		case 9:
			//ɾ��ѧ���˺�
			DelStudent(con);
			break;
		case 10:
			//�޸�ѧ���˺�����
			ModifyPassword(con);
			break;
		case 0:
			//�����鱾��Ϣ���ļ�
			SaveBooks(&ang);
			//����
			DestoryLibrary(&ang);
			printf("�˳�����Աϵͳ\n");
			break;
		default:
			printf("û�����ѡ��������ѡ��\n");
			break;
		}
	} while (input4);

}

void StudentSystems(Account* con,char *acc) {
	int input5 = 0;

	//��������
	BookLibrary ang;
	//��ʼ��
	InitLibrary(&ang);

	do {
		menu4();
		printf("��ѡ��:>");
		scanf("%d", &input5);
		switch (input5) {
		case 1://�鿴�����鱾
			SMLookBooks(&ang);
			break;
		case 2://�鿴δ���鱾
			SNLookBooks(&ang);
			break;
		case 3://�������������鱾
			SInputNameByBook(&ang);
			break;
		case 4://���鱾
			BorrowBook(&ang,acc);
			break;
		case 5://���鱾
			AlsoBook(&ang);
			break;
		case 0:
			SaveBooks(&ang);
			DestoryLibrary(&ang);
			printf("�˳�ѧ��ϵͳ\n");
			break;
		default:
			printf("û�����ѡ��������ѡ��\n");
			break;
		}
	} while (input5);
}