#include "Library.h"

void menu1() {
	printf("����Ա�˺ţ�987654321\n");
	printf("����Ա���룺987654321\n");
	printf("--------------------------\n");
	printf("|        ��¼ѡ��        |\n");
	printf("|        1.ѧ����½      |\n");
	printf("|        2.����Ա��¼    |\n");
	printf("|        0.�˳�          |\n");
	printf("--------------------------\n");
}

enum Option1 {
	QUIT,
	STUDENT,
	MANAGER,
	
};

void Library() {
	int input1 = 0;

	//����ѧ���˺ű�
	Account student;

	//��ʼ��ѧ���˺ű����ļ����˺���Ϣ�������
	InitAccount(&student);




	do {
		menu1();
		printf("��ѡ��:>");
		scanf("%d", &input1);
		switch (input1) {
		case STUDENT:
			Student(&student);
			break;
		case MANAGER:
			Manager(&student);
			break;
		case QUIT:
			//����ѧ���˺���Ϣ���ļ�
			SaveAccount(&student);
			//����ͼ����鱾
			
			//����

			printf("�˳�ϵͳ\n");
			break;
		default:
			printf("û�����ѡ��������ѡ��\n");
			break;
		}
	} while (input1);
}