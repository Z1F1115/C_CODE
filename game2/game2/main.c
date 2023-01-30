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
	//创建两个储存数据的数组
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	
	//初始化两个数组
	Init_Board(mine, ROW, COL, '0');
	Init_Board(show, ROW, COL, SHOW);

	//打印棋盘
	DisPlay_Board(show, ROW, COL);

	//设置雷
	Set_Mine(mine, ROW, COL, EASILY);
	//DisPlay_Board(mine, ROW, COL);//显示雷的位置

	while (ret)
	{
		//排雷
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
		printf("请选择:>");
		scanf("%d",&n);
		switch (n)
		{
		case 1:
			printf("扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			printf("游戏未开发，请重新选择。\n");
			break;
		}

	} while (n);


	return 0;
}