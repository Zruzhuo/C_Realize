#ifndef  _GAME_H__
#define  _GAME_H__
#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 3
#define COL 3

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void init(char map[ROW][COL], int row, int col);
void display(char map[ROW][COL], int row, int col);
void computer_move(char map[ROW][COL], int row, int col);
void player_move(char map[ROW][COL], int row, int col);
char is_full(char map[ROW][COL], int row, int col);
char is_win(char map[ROW][COL], int row, int col);
#endif