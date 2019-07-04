#include"game.h"

void menu()
{
	printf("************************************\n");
	printf("************    扫雷    ************\n");
	printf("************ 1.开始游戏 ************\n");
	printf("************ 0.退出游戏 ************\n");
	printf("************************************\n");
}

void game()
{
	int x = 0;
	int y = 0;
	int count = 0;
	char ret;
	char mine[ROWS][COLS] = { 0 };//用于放置雷的数组
	char show[ROWS][COLS] = { 0 };//用于放置周围雷的信息的数组
	//初始化棋盘
	init_board(mine, ROWS, COLS,'0');
	init_board(show, ROWS, COLS,'*');
	//打印棋盘
	display(show, ROW, COL);
	//安放雷
	set_mine(mine, ROW, COL, MINES);
	
	//排查雷
	while(1)
	{ 
		printf("请输入坐标：>");
		scanf("%d%d", &x, &y);
		if (x <= ROW && x >= 1 && y <= COL && y >= 1)
		{
			if (mine[x][y] == '1' && count == 0)
			{
				move_mine(mine, x, y);
			}
			ret = is_win(mine, show, ROW, COL, x, y);
			if (ret == '*')
			{
				display(mine, ROW, COL);
				printf("你被炸死了，哈哈哈哈！！！\n");
				break;
			}
			if (ret == 'w')
			{
				display(mine, ROW, COL);
				printf("恭喜你取得了胜利！！！\n");
				break;
			}
			else
			{
				display(show, ROW, COL);
				printf("\n");
				count++;
			}
		}
		else
		{
			printf("坐标超出界限，请重新输入！\n");
		}
	}
}

void test()
{
	int input = 0;
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}