#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define MINES 10

#define ROWS ROW + 2
#define COLS COL + 2

void init_board(char board[ROWS][COLS], int rows, int cols, char n);
void display(char board[ROWS][COLS], int row, int col);
void set_mine(char board[ROWS][COLS], int row, int col, int mines);
char find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
char is_win(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
void move_mine(char mine[ROWS][COLS], int x, int y);
void open_show(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);