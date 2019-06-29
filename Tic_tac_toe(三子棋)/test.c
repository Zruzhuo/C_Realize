#include"game.h"

void menu()//打印菜单
{
	printf("****************************\n");
	printf("*****    三子棋游戏    *****\n");
	printf("*****      1.play      *****\n");
	printf("*****      0.exit      *****\n");
	printf("****************************\n");
}
void play_game()
{
	char ret = 0;
	char map[ROW][COL] = { 0 };
	init(map, ROW, COL);
	while (1)
	{
		computer_move(map, ROW, COL);
		display(map, ROW, COL);
		ret = is_win(map, ROW, COL);
		if (ret == '*')
		{
			printf("玩家胜利(*^▽^*)\n");
			break;
		}
		if (ret == '#')
		{
			printf("电脑胜利o(╥﹏╥)o\n");
			break;
		}
		if (ret == 'p')
		{
			printf("平局╮(╯▽╰)╭\n");
			break;
		}
		player_move(map, ROW, COL);
		system("cls");
		display(map, ROW, COL);
		ret = is_win(map, ROW, COL);
		if (ret == '*')
		{
			printf("玩家胜利(*^▽^*)\n");
			break;
		}
		if (ret == '#')
		{
			printf("电脑胜利o(╥﹏╥)o\n");
			break;
		}
		if (ret == 'p')
		{
			printf("平局╮(╯▽╰)╭\n");
			break;
		}
	}
}
int main()//主函数
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play_game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}