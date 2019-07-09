#include"contact.h"

void menu()
{
	printf("***************************************\n");
	printf("*****        1.添加联系人         *****\n");
	printf("*****        2.删除联系人         *****\n");
	printf("*****        3.查找联系人         *****\n");
	printf("*****        0.退出程序           *****\n");
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
			printf("请输入联系人姓名：");
			scanf("%s", con._name);
			printf("请输入联系人电话：");
			scanf("%s", con._tel);
			printf("请输入联系人地址：");
			scanf("%s", con._address);
			printf("请输入联系人年龄：");
			scanf("%d", &con._age);
			Contact_Book_Append(&s, &con);
			Contact_Print(s);
			Contact_Book_Save(&s, "ass.txt");
			Contact_Book_Load(&s, "ass.txt");
			break;
		case 2:
			printf("请输入要删除的联系人姓名：");
			scanf("%s", name);
			Contact_Book_Delete(&s, name);
			Contact_Book_Save(&s, "ass.txt");
			Contact_Book_Load(&s, "ass.txt");
			break;
		case 3:
			printf("请输入要查找的联系人姓名：");
			scanf("%s", name);
			cons = Contact_Book_Find(&s, name);
			s._con_array = cons;
			Contact_Print(s);
			break;
		default:
			printf("输入有误！\n");
			break;
		}		
	} while (input);
	Contact_Book_Destory(&s);
	system("pause");
	return  0;
}