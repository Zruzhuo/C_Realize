#include"game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = n;
		}
	}
}

void display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");
}

void set_mine(char board[ROWS][COLS], int row, int col, int mines)
{
	srand((unsigned)time(NULL));
	int a = 0;
	int b = 0;
	while(mines)
	{
		a = rand() % row + 1;
		b = rand() % col + 1;
		if (board[a][b] == '0')
		{
			board[a][b] = '1';
			mines--;
		}
	}
}
char find_mine(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	char count = '0';
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (i <= ROW && i >= 1 && j <= COL && j >= 1)
			{
				if (mine[i][j] == '1')
				{
					count++;
				}
			}
		}
	}
	return count;
}
char is_win(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int count = 0;
	if (mine[x][y] == '0')
	{
		open_show(mine, show, x, y);
	}
	else
	{
		return '*';
	}
	for (x = 1; x <= row; x++)
	{
		for (y = 1; y <= col; y++)
		{
			if (show[x][y] == '*')
			{
				count++;
			}
		}
	}
	if (count == MINES)
	{
		return 'w';
	}
	return 0;
}

void move_mine(char mine[ROWS][COLS], int x, int y)
{
	mine[x][y] = '0';
	while (1)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			break;
		}
	}
}

void open_show(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	char count = find_mine(mine, x, y);
	show[x][y] = count;
	if (count == '0')
	{
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (i <= ROW && i >= 1 && j <= COL && j >= 1)
				{
					if (show[i][j] == '*'&&mine[i][j]!='1')
					{
						
						show[i][j] = find_mine(mine, i, j);
						if (show[i][j] == '0')
						{
							open_show(mine, show, i, j);
						}
					}
				}
			}
		}
	}
}