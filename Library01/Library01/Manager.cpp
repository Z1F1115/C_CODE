#include "Library.h"

void Manager(Account* con) {
	int input3 = 0;
	Student_Account n = { 0 };
	printf("�������Ա�˺ţ�");
	scanf("%s", n.accounts);
	if (0 != strcmp(ACCOUNTS, n.accounts)) {
		printf("����Ա�˺Ų��ԣ�\n");
		return;
	}
	printf("�������Ա�˺����룺");
	scanf("%s", n.password);
	if (0 != strcmp(PASSWORD, n.password)) {
		printf("����Ա�˺����벻�ԣ�\n");
		return;
	}

	system("cls");
	printf("�������Աϵͳ��\n");
	ManagerSystems(con);
}