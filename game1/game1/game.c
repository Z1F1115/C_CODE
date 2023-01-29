#include "game.h"

//初始化
void Init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//画棋盘
void Display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < row - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

//玩家
void Player_Move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家下:>\n");
	printf("输入棋盘的x和y坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (' ' == board[x - 1][y - 1] )
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("里面有棋子，请重新输入x和y坐标:>");
			}
		}
		else
		{
			printf("超出棋盘范围，请重新输入x和y坐标:>");
		}
	}
}

//电脑
void Computer_Move(char board[ROW][COL], int row, int col)
{
	
	printf("电脑下:>\n");
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (' ' == board[x][y])
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断棋盘是否满
int InFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	//判断三行
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断三列
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j][i] != ' ')
			{
				return board[j][i];
			}
		}
	}
	//判断对角线
	for (i = 0; i < row-2; i++)
	{
		for (j = 0; j < col; j++)
		{                                           
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row-2; i++)
	{
		for (j = col-1; j >= 2; j--)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断棋盘是否满了
	if (InFull(board, ROW, COL) == 0)
	{
		return 'Q';
	}

	return 'C';
}