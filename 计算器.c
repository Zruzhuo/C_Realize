#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	while (1)
	{
		double x = 0, y = 0, ret = 0;//定义运算量以及结果
		char operator;//定义运算符
		printf("******************************\n");
		printf("请输入算式：>");
		scanf("%lf%c%lf", &x, &operator, &y);//输入算式
		switch (operator)//通过switch case语句控制加减乘除运算
		{
		case '+':
			ret = x + y;//加法运算
			break;
		case '-':
			ret = x - y;//减法运算
			break;
		case '*':
			ret = x * y;//乘法运算
			break;
		case '/':
			ret = x / y;//除法运算
			break;
		default:
			printf("输入错误，请重新输入！\n");
		}
		printf("%lf %c %lf = %lf\n", x, operator, y, ret);//输出结果
	}
	system("pause");
	return 0;
}