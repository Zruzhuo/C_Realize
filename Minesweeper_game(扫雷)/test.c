#include"game.h"

void menu()
{
	printf("************************************\n");
	printf("************    ɨ��    ************\n");
	printf("************ 1.��ʼ��Ϸ ************\n");
	printf("************ 0.�˳���Ϸ ************\n");
	printf("************************************\n");
}

void game()
{
	int x = 0;
	int y = 0;
	int count = 0;
	char ret;
	char mine[ROWS][COLS] = { 0 };//���ڷ����׵�����
	char show[ROWS][COLS] = { 0 };//���ڷ�����Χ�׵���Ϣ������
	//��ʼ������
	init_board(mine, ROWS, COLS,'0');
	init_board(show, ROWS, COLS,'*');
	//��ӡ����
	display(show, ROW, COL);
	//������
	set_mine(mine, ROW, COL, MINES);
	
	//�Ų���
	while(1)
	{ 
		printf("���������꣺>");
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
				printf("�㱻ը���ˣ���������������\n");
				break;
			}
			if (ret == 'w')
			{
				display(mine, ROW, COL);
				printf("��ϲ��ȡ����ʤ��������\n");
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
			printf("���곬�����ޣ����������룡\n");
		}
	}
}

void test()
{
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
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