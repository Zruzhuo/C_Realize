#include"game.h"

void menu()//��ӡ�˵�
{
	printf("****************************\n");
	printf("*****    ��������Ϸ    *****\n");
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
			printf("���ʤ��(*^��^*)\n");
			break;
		}
		if (ret == '#')
		{
			printf("����ʤ��o(�i�n�i)o\n");
			break;
		}
		if (ret == 'p')
		{
			printf("ƽ�֨r(�s���t)�q\n");
			break;
		}
		player_move(map, ROW, COL);
		system("cls");
		display(map, ROW, COL);
		ret = is_win(map, ROW, COL);
		if (ret == '*')
		{
			printf("���ʤ��(*^��^*)\n");
			break;
		}
		if (ret == '#')
		{
			printf("����ʤ��o(�i�n�i)o\n");
			break;
		}
		if (ret == 'p')
		{
			printf("ƽ�֨r(�s���t)�q\n");
			break;
		}
	}
}
int main()//������
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play_game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}