#include"game.h"

void init(char map[ROW][COL], int row, int col)//初始化地图为九个空格
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			map[i][j] = ' ';
		}
	}
}
void display(char map[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{	
		for (j = 0; j < col; j++)
		{
			printf(" %c ", map[i][j]);
			if (j < col - 1)
			{
				printf(" |");
			}			
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col)
				{
					printf(" --- ");
				}				
			}
			printf("\n");		
		}
	}
}
void player_move(char map[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家走：");	
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (map[x - 1][y - 1] == ' ')
			{
				map[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已经被占用，请重新输入！");
			}
		}
		else
		{
			printf("输入错误，请重新输入！");
		}
	}
}
void computer_move(char map[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % 3 ;
		y = rand() % 3 ;
		if (map[1][1] == ' ')
		{
			map[1][1] = '#';
			break;
		}
		else if(map[x][y] == ' ')
		{
			map[x][y] = '#';
			break;
		}
	}
}
char is_full(char map[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	int count = row * col;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (map[i][j] == '*' || map[i][j] == '#')
			{
				count--;
			}
		}
	}
	if (count == 0)
	{
		return '1';
	}
}
char is_win(char map[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	char ret = 0;
	ret = is_full(map, ROW, COL);
	for (i = 0; i < row; i++)
	{
		if (map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][0] != ' ')
		{
			return map[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{
		if (map[0][j] == map[1][j] && map[1][j] == map[2][j] && map[0][j] != ' ')
		{
			return map[0][j];
		}
	}
	if (map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[0][0] != ' ')
	{
		return map[0][0];
	}
	if (map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[0][0] != ' ')
	{
		return map[0][2];
	}
	if (ret == '1')
	{
		return 'p';
	}
}