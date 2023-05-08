#include "Library.h"

void menu1() {
	printf("管理员账号：987654321\n");
	printf("管理员密码：987654321\n");
	printf("--------------------------\n");
	printf("|        登录选择        |\n");
	printf("|        1.学生登陆      |\n");
	printf("|        2.管理员登录    |\n");
	printf("|        0.退出          |\n");
	printf("--------------------------\n");
}

enum Option1 {
	QUIT,
	STUDENT,
	MANAGER,
	
};

void Library() {
	int input1 = 0;

	//创建学生账号表
	Account student;

	//初始化学生账号表并吧文件的账号信息存进表里
	InitAccount(&student);




	do {
		menu1();
		printf("请选择:>");
		scanf("%d", &input1);
		switch (input1) {
		case STUDENT:
			Student(&student);
			break;
		case MANAGER:
			Manager(&student);
			break;
		case QUIT:
			//保存学生账号信息到文件
			SaveAccount(&student);
			//保存图书馆书本
			
			//销毁

			printf("退出系统\n");
			break;
		default:
			printf("没有这个选择，请重新选择！\n");
			break;
		}
	} while (input1);
}