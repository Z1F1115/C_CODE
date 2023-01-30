#include "game.h"

//��ʼ������
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

//��ӡ����
void DisPlay_Board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------ɨ��---------\n");
	printf("-------��%d����-------\n",EASILY);
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
	printf("---------ɨ��---------\n");
}

//������
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

//���㸽���ж�����
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
//�Ż�����ģ����㸽���ж��ٸ��ף�������ʧ�� �㲻����
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

//����
int Player(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int m = 0;
	int o = 0;
	while (1)
	{
		printf("������Ҫ���׵�x��y����:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == SHOW)
			{
				if (mine[x][y] == '1')
				{
					printf("�Բ������ŵ�����\n");
					return 0;
				}
				else
				{
					//m = Count_Mine(mine, x, y);
					//show[x][y] = m;
					//�ݹ飬���㲻����
					Count_Mine2(mine, show, x, y);
					
					DisPlay_Board(show, ROW, COL);
					o = Win(show, ROW, COL);
				}
			}
			else
			{
				printf("�����ظ������������롣\n");
			}
		}
		else
		{
			printf("�������ޣ�����������\n");
		}
		if (o == EASILY)
		{
			printf("��ϲ�㣬�ױ���������\n");
			return 0;
		}
	}
}
