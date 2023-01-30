#include "game.h"

//初始化棋盘
void Init_Board(char board[ROWS][COLS], int row, int col, char str)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			board[i][j] = str;
		}
	}
}

//打印棋盘
void DisPlay_Board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------扫雷---------\n");
	printf("-------有%d个雷-------\n",EASILY);
	for (i = 0; i <= col; i++)
	{
		printf("%d ",i);
	}
	for (i = 0; i <= row; i++)
	{
		if (i != 0)
		{
			printf("%d", i);
		}
		for (j = 0; j <= col; j++)
		{
			char ret = board[i][j];
			printf("%c ",ret);
		}
		printf("\n");
	}
	printf("---------扫雷---------\n");
}

//设置雷
void Set_Mine(char mine[ROWS][COLS], int row, int col, int number)
{
	while (number > 0)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			number--;
		}
	}
}

//计算附近有多少雷
int Count_Mine(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 48;
	for (i = x-1; i <= x + 1; i++)
	{
		for (j = y-1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
//优化上面的，计算附近有多少个雷，，，，失败 算不出来
void Count_Mine2(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 48;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	show[x][y] = count;
	if (count == 48)
	{
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == SHOW)
				{
					Count_Mine2(mine, show, i, j);
				}
			}
		}
	}
	
}

int Win(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int num = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == SHOW)
			{
				num++;
			}
		}
	}
	return num;
}

//排雷
int Player(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int m = 0;
	int o = 0;
	while (1)
	{
		printf("请输入要排雷的x和y坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == SHOW)
			{
				if (mine[x][y] == '1')
				{
					printf("对不起，你排到雷了\n");
					return 0;
				}
				else
				{
					//m = Count_Mine(mine, x, y);
					//show[x][y] = m;
					//递归，但算不出来
					Count_Mine2(mine, show, x, y);
					
					DisPlay_Board(show, ROW, COL);
					o = Win(show, ROW, COL);
				}
			}
			else
			{
				printf("坐标重复，请重新输入。\n");
			}
		}
		else
		{
			printf("超出界限，请重新输入\n");
		}
		if (o == EASILY)
		{
			printf("恭喜你，雷被你排完了\n");
			return 0;
		}
	}
}
