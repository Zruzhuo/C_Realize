#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	while (1)
	{
		double x = 0, y = 0, ret = 0;//�����������Լ����
		char operator;//���������
		printf("******************************\n");
		printf("��������ʽ��>");
		scanf("%lf%c%lf", &x, &operator, &y);//������ʽ
		switch (operator)//ͨ��switch case�����ƼӼ��˳�����
		{
		case '+':
			ret = x + y;//�ӷ�����
			break;
		case '-':
			ret = x - y;//��������
			break;
		case '*':
			ret = x * y;//�˷�����
			break;
		case '/':
			ret = x / y;//��������
			break;
		default:
			printf("����������������룡\n");
		}
		printf("%lf %c %lf = %lf\n", x, operator, y, ret);//������
	}
	system("pause");
	return 0;
}