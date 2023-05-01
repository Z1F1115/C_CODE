#include "contact.h"

//通讯录-动态增长-文件保存
//1.通讯录初始化后，能放3个人信息
// 1.2当我们空间的存放满后，增加2个人信息
//每个人的信息：
//名字+年龄+性别+电话+地址
//2.增加人的信息
//3.删除指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录信息
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

	//创建通讯录
	Contact con;
	//初始化通讯录
	//给data申请一块连续的空间在堆区上
	//sz = 0
	//capacity初始化为当前的最大容量
	InitContact(&con);

	do {
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input) {
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODUFY:
			ModifyContact(&con);
			break;
		case SORT:
			printf("待添加功能\n");
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			//保存信息到文件
			SaveContact(&con);
			//销毁通讯录
			DestoryContact(&con);
			printf("退出通讯录!\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);

	return 0;
}
