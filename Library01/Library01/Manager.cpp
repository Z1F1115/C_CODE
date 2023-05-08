#include "Library.h"

void Manager(Account* con) {
	int input3 = 0;
	Student_Account n = { 0 };
	printf("输入管理员账号：");
	scanf("%s", n.accounts);
	if (0 != strcmp(ACCOUNTS, n.accounts)) {
		printf("管理员账号不对！\n");
		return;
	}
	printf("输入管理员账号密码：");
	scanf("%s", n.password);
	if (0 != strcmp(PASSWORD, n.password)) {
		printf("管理员账号密码不对！\n");
		return;
	}

	system("cls");
	printf("进入管理员系统！\n");
	ManagerSystems(con);
}