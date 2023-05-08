#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_SZ 3 //��ʼ����Ĵ�С
#define INC_SZ 2     //���ӱ������
#define MAX_NAME 20  //�������

//����Ա�˺ź�����
#define ACCOUNTS "987654321"
#define PASSWORD "987654321"

//ѧ���˺�---------------------
typedef struct {
	char accounts[10];//�˺�
	char password[16];//����
}Student_Account;

typedef struct {
	Student_Account* data;
	int sz;//�˺�����
	int Max_Account;
}Account;
//-----------------------------

//�鱾��Ϣ---------------------
typedef struct {
	int number;//���
	char name[MAX_NAME];//����
	int mode;//���״̬
	char information[10];//�����˺�
}Book;

typedef struct {
	Book* bookdata;
	int size;//�鱾����
	int Max_Book;//����
}BookLibrary;
//-----------------------------

//����ϵͳ
void Library();

//ѧ����½
void Student(Account* con);

//����Ա��¼
void Manager(Account* con);

//��ʼ��ѧ���˺ű����ļ����˺���Ϣ�������
void InitAccount(Account* pc);

//����ѧ���˺ŵ��ļ�
void SaveAccount(Account* pc);

//ѧ��ϵͳ
void StudentSystems(Account* con, char* acc);

//����Աϵͳ
void ManagerSystems(Account *con);

