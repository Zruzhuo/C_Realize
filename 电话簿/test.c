#include"contact.h"

void menu()
{
	printf("***************************************\n");
	printf("*****        1.�����ϵ��         *****\n");
	printf("*****        2.ɾ����ϵ��         *****\n");
	printf("*****        3.������ϵ��         *****\n");
	printf("*****        0.�˳�����           *****\n");
	printf("***************************************\n");
}
int main()
{
	Contact_Book s;
	Contact_Book_Init(&s);
	Contact con;
	Contact* cons = NULL;
	char* name = (char*)malloc(12);
	if (name == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������ϵ��������");
			scanf("%s", con._name);
			printf("��������ϵ�˵绰��");
			scanf("%s", con._tel);
			printf("��������ϵ�˵�ַ��");
			scanf("%s", con._address);
			printf("��������ϵ�����䣺");
			scanf("%d", &con._age);
			Contact_Book_Append(&s, &con);
			Contact_Print(s);
			Contact_Book_Save(&s, "ass.txt");
			Contact_Book_Load(&s, "ass.txt");
			break;
		case 2:
			printf("������Ҫɾ������ϵ��������");
			scanf("%s", name);
			Contact_Book_Delete(&s, name);
			Contact_Book_Save(&s, "ass.txt");
			Contact_Book_Load(&s, "ass.txt");
			break;
		case 3:
			printf("������Ҫ���ҵ���ϵ��������");
			scanf("%s", name);
			cons = Contact_Book_Find(&s, name);
			s._con_array = cons;
			Contact_Print(s);
			break;
		default:
			printf("��������\n");
			break;
		}		
	} while (input);
	Contact_Book_Destory(&s);
	system("pause");
	return  0;
}