#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3


void Init_board(char board[ROW][COL], int row,  int col);
void Display_board(char board[ROW][COL], int row, int col);
void Player_Move(char board[ROW][COL], int row, int col);
void Computer_Move(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);