#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASILY 10
#define SHOW '*'

//≥ı ºªØ∆Â≈Ã
void Init_Board(char board[ROWS][COLS], int row, int col, char str);
//¥Ú”°∆Â≈Ã
void DisPlay_Board(char board[ROWS][COLS], int row, int col);
//…Ë÷√¿◊
void Set_Mine(char mine[ROWS][COLS], int row, int col, int number);
//≈≈¿◊
int Player(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
