#include "Library.h"

void menu2() {

	printf("--------------------------\n");
	printf("|        登录选择        |\n");
	printf("|        1.已经有账号    |\n");
	printf("|        2.注册账号      |\n");
	printf("|        0.退出学生登陆  |\n");
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
			printf("增加结构体容量失败\n");
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

	//读取文件内容
	Student_Account tmp = { 0 };
	while (fread(&tmp, sizeof(Student_Account), 1, pf)) {
		//是否需要增加容量
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
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

	//加载文件内容
	LoadAccount(pc);
}

void SaveAccount(Account* pc) {
	FILE *pf = fopen("account.txt","w");
	if (NULL == pf) {
		perror("SaveAccount");
		return;
	}

	//写文件
	int i = 0;
	for (i = 0; i < pc->sz;i++) {
		fwrite((pc->data + i), sizeof(Student_Account), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

void Student_Login(Account* pc) {
	int i = 0;
	Student_Account n = { 0 };
	printf("输入学生的账号：");
	scanf("%s", n.accounts);
	for (i = 0; i < pc->sz; i++) {
		if (0 == (strcmp(n.accounts, pc->data[i].accounts))) {
			break;
		}
	}
	if (i == pc->sz) {
		printf("账号不存在！\n");
		return;
	}
	printf("输入学生的账号密码：");
	scanf("%s", n.password);
	if ((strcmp(n.password, pc->data[i].password)) != 0) {
		printf("密码错误！\n");
		return;
	}
	else {
		system("cls");
		printf("进入学生系统！\n");
		StudentSystems(pc, n.accounts);
	}
}

void Student_Enroll(Account* pc) {
	int i = 0;
	Student_Account n = {0};
	CheckCapacity(pc);
	printf("账号最多10位，密码最多16位\n");
	printf("输入新注册的账号：");
	scanf("%s", n.accounts);
	for (i = 0; i < pc->sz; i++) {
		if (0 == (strcmp(n.accounts,pc->data[i].accounts))) {
			printf("账号已经存在！\n");
			return;
		}
	}
	if (i == pc->sz)
		strcpy(pc->data[i].accounts, n.accounts);
	printf("输入新注册的密码：");
	scanf("%s", pc->data[i].password);

	pc->sz++;
	printf("账号创建成功！\n");
}


void Student(Account *con) {
	int input2 = 0;
	
	do {
		menu2();
		printf("请选择:>");
		scanf("%d", &input2);
		switch (input2) {
		case 1://已经有账号
			Student_Login(con);
			break;
		case 2://注册账号
			Student_Enroll(con);
			break;
		case 0:
			printf("退出学生登陆\n");
			break;
		default:
			printf("没有这个选择，请重新选择！\n");
			break;
		}
	} while (input2);

}