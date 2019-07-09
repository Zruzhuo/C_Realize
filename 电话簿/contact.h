#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Contact
{
	char _name[24];//姓名
	char _tel[16];//电话
	char _address[64];//地址
	size_t _age;//年龄
}Contact;

//通讯录
typedef struct Contact_Book
{
	Contact* _con_array;
	size_t _size;//联系人个数
	size_t _capacity;//容量
}Contact_Book;

void Contact_Book_Init(Contact_Book* s);
void Contact_Book_Destory(Contact_Book* s);
void Contact_Book_Append(Contact_Book* s, Contact* con);
void Contact_Book_Delete(Contact_Book* s, const char* name);
Contact* Contact_Book_Find(Contact_Book* s, const char* name);
void Contact_Book_Save(Contact_Book* s, const char* file);
void Contact_Book_Load(Contact_Book* s, const char* file);
void Contact_Print(Contact_Book s);


