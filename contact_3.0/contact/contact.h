#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_NAME  20
#define MAX_SEX   10
#define MAX_TELE  12
#define MAX_ADDR  30

#define DEFAULT_SZ 3
#define INC_SZ 2


//���͵Ķ���
typedef struct {
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼
typedef struct {
	PeoInfo *data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//ͨѶ¼�е�ǰ�ܹ��м���
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact *pc);

//������ϵ��
void AddContact(Contact *pc);

//��ӡ��ϵ����Ϣ
void PrintContact(const Contact *pc);

//ɾ����ϵ����Ϣ
void DelContact(Contact *pc);

//����ָ����ϵ��
void SearchContact(Contact *pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact *pc);

//����ͨѶ¼
void DestoryContact(Contact *pc);

//����ͨ��¼��Ϣ���ļ�
void SaveContact(Contact *pc);

//�����ļ���������
void LoadContact(Contact* pc);

//������ݵ�����
void CheckCapacity(Contact* pc);
