#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_SZ 3 //初始化表的大小
#define INC_SZ 2     //增加表的容量
#define MAX_NAME 20  //最多书名

//管理员账号和密码
#define ACCOUNTS "987654321"
#define PASSWORD "987654321"

//学生账号---------------------
typedef struct {
	char accounts[10];//账号
	char password[16];//密码
}Student_Account;

typedef struct {
	Student_Account* data;
	int sz;//账号数量
	int Max_Account;
}Account;
//-----------------------------

//书本信息---------------------
typedef struct {
	int number;//书号
	char name[MAX_NAME];//书名
	int mode;//书的状态
	char information[10];//借书账号
}Book;

typedef struct {
	Book* bookdata;
	int size;//书本数量
	int Max_Book;//容量
}BookLibrary;
//-----------------------------

//进入系统
void Library();

//学生登陆
void Student(Account* con);

//管理员登录
void Manager(Account* con);

//初始化学生账号表并吧文件的账号信息存进表里
void InitAccount(Account* pc);

//保存学生账号到文件
void SaveAccount(Account* pc);

//学生系统
void StudentSystems(Account* con, char* acc);

//管理员系统
void ManagerSystems(Account *con);

