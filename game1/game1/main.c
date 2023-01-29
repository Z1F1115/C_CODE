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
	//创建储存数据的数组
	char board[ROW][COL];
	//初始化数组 
	Init_board(board, ROW, COL);
	//画棋盘
	Display_board(board, ROW, COL);
	char ret = 'C';
	while (1)
	{
		//玩家
		Player_Move(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑
		Computer_Move(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
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
		printf("请输入:>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("项目未开发，请重新选择\n");
			break;
		}
	} while (n);
	return 0;
}