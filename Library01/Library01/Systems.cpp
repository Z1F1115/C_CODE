#include "Library.h"

void menu3() {
	printf("----------------------------\n");
	printf("|        管理员系统        |\n");
	printf("|        1.查看所有书本    |\n");
	printf("|        2.添加书本        |\n");
	printf("|        3.删除书本        |\n");
	printf("|        4.查看已借走书本  |\n");
	printf("|        5.查看未借走书本  |\n");
	printf("|        6.输入书名查找书本|\n");
	printf("|        7.修改书本信息    |\n");
	printf("|        8.查看学生账号    |\n");
	printf("|        9.删除学生账号    |\n");
	printf("|     10.修改学生账号的密码|\n");
	printf("|        0.退出管理员系统  |\n");
	printf("----------------------------\n");
}

void menu4() {
	printf("----------------------------\n");
	printf("|        学生系统          |\n");
	printf("|        1.查看所有书本    |\n");
	printf("|        2.查看未借书本    |\n");
	printf("|        3.输入书名查找书本|\n");
	printf("|        4.借书本          |\n");
	printf("|        5.还书本          |\n");
	printf("|        0.退出学生系统    |\n");
	printf("----------------------------\n");
}

void menu5() {
	printf("------------------------------\n");
	printf("|        1.修改书本的书号    |\n");
	printf("|        2.修改书本的书名    |\n");
	printf("|        3.修改书本的是否被借|\n");
	printf("|        4.修改借书人信息    |\n");
	printf("|        0.退出修改          |\n");
	printf("------------------------------\n");
}

//管理员功能区---------------------------------------
void CheckCapacity1(BookLibrary* pa) {
	if (pa->size == pa->Max_Book) {
		Book* ptr = (Book*)realloc(pa->bookdata,(pa->Max_Book + INC_SZ) * sizeof(Book));
		if (ptr != NULL) {
			pa->bookdata = ptr;
			pa->Max_Book += INC_SZ;
		}
		else {
			perror("AddBook");
			printf("增加结构体容量失败\n");
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
	//读文件
	Book tmp = { 0 };
	while (fread(&tmp, sizeof(Book), 1, pf)) {
		//是否需要增容
		CheckCapacity1(pa);
		//储存
		pa->bookdata[pa->size] = tmp;
		pa->size++;
	}

	//关闭文件
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

	//加载文件内容
	LoadBook(pa);
}

void AddBook(BookLibrary* pa) {
	int i = 0;
	Book n = {0};

	CheckCapacity1(pa);
	//添加书本信息
	printf("输入书号：");
	scanf("%d",&n.number);
	for (i = 0; i < pa->size;i++) {
		if (n.number == pa->bookdata[i].number) {
			printf("书号已经存在!\n");
			return;
		}
	}
	printf("输入书名：");
	scanf("%s", n.name);
	for (i = 0; i < pa->size; i++) {
		if (0 == strcmp(n.name,pa->bookdata[i].name)) {
			printf("书名已经存在!\n");
			return;
		}
	}
	if (i == pa->size) {
		pa->bookdata[i] = n;
	}

	pa->size++;
	printf("添加书本成功！\n");
}

void MLookBooks(BookLibrary* pa) {
	if (0 == pa->size) {
		printf("书库为空\n");
		return;
	}
	int i = 0;
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
			"书号", "书名","是否被借","借书账号");

	for (i = 0; i < pa->size; i++) {
		printf("%-6d\t《%-8s》\t %-9d\t %-8s\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode,
				pa->bookdata[i].information);
	}
	printf("现在一共有%d本书\n",pa->size);
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
		printf("书库为空，无法删除\n");
		return;
	}

	printf("请输入要删除书的名字：");
	scanf("%s",name);

	//查找要删除的书；有或没有
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("要删除的书不存在\n");
		return;
	}

	//删除
	for (i = pos; i < pa->size - 1;i++) {
		pa->bookdata[i] = pa->bookdata[i + 1];
	}
	pa->size--;
	printf("删除成功!\n");
}

void YLookBooks(BookLibrary* pa) {
	if (pa->size == 0) {
		printf("书库为空\n");
		return;
	}

	int i = 0,j = 0;
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
		"书号", "书名", "是否被借", "借书账号");

	for (i = 0; i < pa->size;i++) {
		if (1 == pa->bookdata[i].mode) {
			printf("%-6d\t《%-8s》\t %-9d\t %-8s\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode,
				pa->bookdata[i].information);
			j++;
		}
	}
	printf("有%d本被借了\n",j);
}

void NLookBooks(BookLibrary* pa) {
	if (pa->size == 0) {
		printf("书库为空\n");
		return;
	}

	int i = 0, j = 0;
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
		"书号", "书名", "是否被借", "借书账号");

	for (i = 0; i < pa->size; i++) {
		if (0 == pa->bookdata[i].mode) {
			printf("%-6d\t《%-8s》\t %-9d\t %-8s\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode,
				pa->bookdata[i].information);
			j++;
		}
	}
	printf("还有%d本没有被借了\n", j);
}

void InputNameByBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("书库为空，无法查找\n");
		return;
	}

	printf("请输入要查找书的名字:");
	scanf("%s", name);

	//查找要的书；有或没有
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("书不存在\n");
		return;
	}

	//打印出来
	printf("%-6s\t %-8s\t %-2s\t %-8s\n",
		"书号", "书名", "是否被借", "借书账号");
	printf("%-6d\t《%-8s》\t %-9d\t %-8s\n",
		pa->bookdata[pos].number,
		pa->bookdata[pos].name,
		pa->bookdata[pos].mode,
		pa->bookdata[pos].information);
}

//修改-----------------------
void ModifyNumber(BookLibrary* pa, int pos) {
	printf("请输入新书号:");
	scanf("%d", &pa->bookdata[pos].number);
}

void ModifyName(BookLibrary* pa, int pos) {
	printf("请输入新书名:");
	scanf("%s", pa->bookdata[pos].name);
}

void ModifyMode(BookLibrary* pa, int pos) {
	printf("请输入书的新状态:");
	scanf("%d", &pa->bookdata[pos].mode);
}

void ModifyInformation(BookLibrary* pa, int pos) {
	printf("请输入新的借书账号:");
	scanf("%s", pa->bookdata[pos].information);
}
//---------------------------
void ModifyBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("书库为空，无书本可以修改\n");
		return;
	}

	printf("请输入要修改书本的名字:");
	scanf("%s", name);

	//查找要的书；有或没有
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("书不存在\n");
		return;
	}

	//修改信息
	int input5 = 0;
	do {
		menu5();
		printf("请选择:>");
		scanf("%d", &input5);
		switch (input5) {
		case 1://修改书本的书号
			ModifyNumber(pa,pos);
			break;
		case 2://修改书本的书名
			ModifyName(pa, pos);
			break;
		case 3://修改书本的是否被借
			ModifyMode(pa, pos);
			break;
		case 4://修改借书人信息
			ModifyInformation(pa, pos);
			break;
		case 0:
			printf("退出修改\n");
			break;
		default:
			printf("没有这个选择，请重新选择！\n");
			break;
		}
	} while (input5);
}

void LookStudent(Account* pc) {
	if (pc->sz == 0) {
		printf("学生账号为空\n");
		return;
	}

	int i = 0;
	printf("%-11s\t%-17s\n",
		"账号", "密码");
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
		printf("没有学生账号，无需删除\n");
		return;
	}

	printf("请输入要删除的账号:");
	scanf("%s", accounts);


	int pos = FindByAccounts(pc, accounts);
	if (pos == -1) {
		printf("要删除的人不存在\n");
		return;
	}

	for (i = pos; i < pc->sz - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功!\n");

}

void ModifyPassword(Account* pc) {
	char accounts[10] = { 0 };
	int i = 0;

	if (pc->sz == 0) {
		printf("没有学生账号，无法修改\n");
		return;
	}

	printf("请输入要修改的账号:");
	scanf("%s", accounts);

	int pos = FindByAccounts(pc, accounts);
	if (pos == -1) {
		printf("要删除的人不存在\n");
		return;
	}
	else {
		printf("输入新密码：");
		scanf("%s",pc->data[pos].password);
		printf("修改密码成功！\n");
	}
}

void DestoryLibrary(BookLibrary* pa) {
	free(pa->bookdata);
	pa->bookdata = NULL;
	pa->size = 0;
	pa->Max_Book = 0;
}

void SaveBooks(BookLibrary* pa) {
	//打开文件
	FILE* pf = fopen("bookdata.txt", "w");
	if (pf == NULL) {
		perror("SaveBooks");
		return;
	}

	//写文件
	int i = 0;
	for (i = 0; i < pa->size;i++) {
		fwrite(pa->bookdata+i,sizeof(Book),1,pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}
//---------------------------------------------------

//学生功能区-----------------------------------------
void SMLookBooks(BookLibrary* pa) {
	if (0 == pa->size) {
		printf("书库为空\n");
		return;
	}
	int i = 0;
	printf("%-6s\t %-8s\t %-2s\n",
		"书号", "书名", "是否被借");

	for (i = 0; i < pa->size; i++) {
		printf("%-6d\t《%-8s》\t %-9d\n",
			pa->bookdata[i].number,
			pa->bookdata[i].name,
			pa->bookdata[i].mode);
	}
	printf("现在一共有%d本书\n", pa->size);
}

void SNLookBooks(BookLibrary* pa) {
	if (pa->size == 0) {
		printf("书库为空\n");
		return;
	}

	int i = 0, j = 0;
	printf("%-6s\t %-8s\t %-2s\n",
		"书号", "书名", "是否被借");

	for (i = 0; i < pa->size; i++) {
		if (0 == pa->bookdata[i].mode) {
			printf("%-6d\t《%-8s》\t %-9d\n",
				pa->bookdata[i].number,
				pa->bookdata[i].name,
				pa->bookdata[i].mode);
			j++;
		}
	}
	printf("还有%d本没有被借了\n", j);
}

void SInputNameByBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("书库为空，无法查找\n");
		return;
	}

	printf("请输入要查找书的名字:");
	scanf("%s", name);

	//查找要的书；有或没有
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("书不存在\n");
		return;
	}

	//打印出来
	printf("%-6s\t %-8s\t %-2s\n",
		"书号", "书名", "是否被借");
	printf("%-6d\t《%-8s》\t %-9d\n",
		pa->bookdata[pos].number,
		pa->bookdata[pos].name,
		pa->bookdata[pos].mode);
}

void BorrowBook(BookLibrary* pa,char *acc) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("书库为空，无法借\n");
		return;
	}

	printf("请输入要借书的名字:");
	scanf("%s", name);

	//查找要的书；有或没有
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("书不存在\n");
		return;
	}
	else {
		pa->bookdata[pos].mode = 1;
		strcpy(pa->bookdata[pos].information , acc);
		printf("借书成功！\n");
	}
}

void AlsoBook(BookLibrary* pa) {
	char name[MAX_NAME] = { 0 };
	int i = 0;

	if (pa->size == 0) {
		printf("书库为空，无法还\n");
		return;
	}

	printf("请输入要还书的名字:");
	scanf("%s", name);

	//查找要的书；有或没有
	int pos = FindByName(pa, name);
	if (pos == -1) {
		printf("书不存在\n");
		return;
	}
	else {
		pa->bookdata[pos].mode = 0;
		strcpy(pa->bookdata[pos].information, "0");
		printf("还书成功！\n");
	}
}

//---------------------------------------------------

void ManagerSystems(Account* con) {
	int input4 = 0;
	//创建书库表
	BookLibrary ang;
	//初始化
	InitLibrary(&ang);

	do {
		menu3();
		printf("请选择:>");
		scanf("%d", &input4);
		switch (input4) {
		case 1:
			//查看书本
			MLookBooks(&ang);
			break;
		case 2:
			//添加书本
			AddBook(&ang);
			break;
		case 3:
			//删除书本
			DelBook(&ang);
			break;
		case 4:
			//查看已借走书本
			YLookBooks(&ang);
			break;
		case 5:
			//查看未借走书本
			NLookBooks(&ang);
			break;
		case 6:
			//输入书名查找书本
			InputNameByBook(&ang);
			break;
		case 7:
			//修改书本状态
			ModifyBook(&ang);
			break;
		case 8:
			//查看学生账号
			LookStudent(con);
			break;
		case 9:
			//删除学生账号
			DelStudent(con);
			break;
		case 10:
			//修改学生账号密码
			ModifyPassword(con);
			break;
		case 0:
			//保存书本信息到文件
			SaveBooks(&ang);
			//销毁
			DestoryLibrary(&ang);
			printf("退出管理员系统\n");
			break;
		default:
			printf("没有这个选择，请重新选择！\n");
			break;
		}
	} while (input4);

}

void StudentSystems(Account* con,char *acc) {
	int input5 = 0;

	//创建书库表
	BookLibrary ang;
	//初始化
	InitLibrary(&ang);

	do {
		menu4();
		printf("请选择:>");
		scanf("%d", &input5);
		switch (input5) {
		case 1://查看所有书本
			SMLookBooks(&ang);
			break;
		case 2://查看未借书本
			SNLookBooks(&ang);
			break;
		case 3://输入书名查找书本
			SInputNameByBook(&ang);
			break;
		case 4://借书本
			BorrowBook(&ang,acc);
			break;
		case 5://还书本
			AlsoBook(&ang);
			break;
		case 0:
			SaveBooks(&ang);
			DestoryLibrary(&ang);
			printf("退出学生系统\n");
			break;
		default:
			printf("没有这个选择，请重新选择！\n");
			break;
		}
	} while (input5);
}