#include"contact.h"

void Contact_Book_Init(Contact_Book* s)
{
	assert(s);
	s->_con_array = (Contact*)malloc(sizeof(Contact) * 8);//初始化s->_con_array,申请动态内存空间，大小为8个Contact大小
	if (s->_con_array == NULL)//判断malloc是否执行成功
	{
		printf("malloc error\n");
		exit(-1);//退出程序，返回-1
	}
	s->_size = 0;
	s->_capacity = 8;
}
void Contact_Book_Destory(Contact_Book* s)
{
	assert(s);
	free(s->_con_array);//释放动态内存
	s->_con_array = NULL;//置空指针，防止野指针
	s->_size = s->_capacity = 0;
}
void Contact_Book_Append(Contact_Book* s, Contact* con)
{
	assert(s && con);
	if (s->_size >= s->_capacity)//判断丛台内存是否足够
	{
		s->_capacity *= 2;//动态内存不够，容量*2
		Contact* newarray = (Contact*)realloc(s->_con_array, sizeof(Contact*) * s->_capacity);
		//修改申请的动态内存大小为新的capacity
		if (newarray == NULL)//判断realloc是否执行成功
		{
			printf("realloc error\n");
			exit(-1);
		}
		s->_con_array = newarray;//将新的动态内存地址赋给s->_con_array
	}
	Contact* array = s->_con_array;
	size_t i = s->_size;
	strcpy(array[i]._name, con->_name);
	strcpy(array[i]._tel, con->_tel);
	strcpy(array[i]._address, con->_address);
	array[i]._age = con->_age;

	s->_size++;//附加联系人完成，s->_size++
}

void Contact_Book_Delete(Contact_Book* s, const char* name)
{
	assert(s);
	Contact* array = s->_con_array;
	int ret = 0;
	for (size_t i = 0; i < s->_size; i++)
	{
		ret = strcmp(array[i]._name, name);
		if (ret == 0)
		{
			for (size_t j = i; j < s->_size; j++)
			{
				strcpy(array[j]._name, array[j + 1]._name);
				strcpy(array[j]._tel, array[j + 1]._tel);
				strcpy(array[j]._address, array[j + 1]._address);
				array[j]._age = array[j + 1]._age;
			}
		}
	}
}
Contact* Contact_Book_Find(Contact_Book* s, const char* name)
{
	assert(s);
	Contact* array = s->_con_array;
	size_t i = 0;
	int ret = 0;
	for (i = 0; i < s->_size; i++)
	{
		ret = strcmp(array[i]._name, name);
		if (ret == 0)
		{
			return array+i;
		}
	}
	return NULL;
}
void Contact_Book_Save(Contact_Book* s, const char* file)
{
	FILE* fp = fopen(file, "wb");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	Contact* array = s->_con_array;
	for (size_t i = 0; i < s->_size; i++)
	{
		fwrite(&array[i], sizeof(Contact), 1, fp);
	}
	fclose(fp);
}
void Contact_Book_Load(Contact_Book* s, const char* file)
{
	FILE* fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact), 1, fp) == 1)
	{
		Contact_Book_Append(s, &con);
	}
	fclose(fp);
}
void Contact_Print(Contact_Book s)
{
	for (size_t i = 0; i < s._size; i++)
	{
		printf("**************************************\n");
		printf("姓名:> %s\n", s._con_array->_name);
		printf("电话:> %s\n", s._con_array->_tel);
		printf("地址:> %s\n", s._con_array->_address);
		printf("年龄:> %d\n", s._con_array->_age);
		printf("**************************************\n");
	}
}