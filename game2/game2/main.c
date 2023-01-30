#include "game.h"

void menu()
{
	printf("*********************\n");
	printf("*********************\n");
	printf("******* 1.play ******\n");
	printf("******* 0.exit ******\n");
	printf("*********************\n");
	printf("*********************\n");
}


void game()
{
	int ret = 1;
	//���������������ݵ�����
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	
	//��ʼ����������
	Init_Board(mine, ROW, COL, '0');
	Init_Board(show, ROW, COL, SHOW);

	//��ӡ����
	DisPlay_Board(show, ROW, COL);

	//������
	Set_Mine(mine, ROW, COL, EASILY);
	//DisPlay_Board(mine, ROW, COL);//��ʾ�׵�λ��

	while (ret)
	{
		//����
		ret = Player(mine,show,ROW,COL);
	}
	DisPlay_Board(mine, ROW, COL);
	
}

int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&n);
		switch (n)
		{
		case 1:
			printf("ɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default :
			printf("��Ϸδ������������ѡ��\n");
			break;
		}

	} while (n);


	return 0;
}