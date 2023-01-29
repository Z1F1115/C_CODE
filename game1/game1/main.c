#include "game.h"

void mune()
{
	printf("**********************\n");
	printf("**********************\n");
	printf("*****   1.paly   *****\n");
	printf("*****   0.exit   *****\n");
	printf("**********************\n");
	printf("**********************\n");
}

void game()
{
	//�����������ݵ�����
	char board[ROW][COL];
	//��ʼ������ 
	Init_board(board, ROW, COL);
	//������
	Display_board(board, ROW, COL);
	char ret = 'C';
	while (1)
	{
		//���
		Player_Move(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//����
		Computer_Move(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	Display_board(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	do
	{
		mune();
		printf("������:>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��Ŀδ������������ѡ��\n");
			break;
		}
	} while (n);
	return 0;
}