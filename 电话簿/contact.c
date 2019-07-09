#include"contact.h"

void Contact_Book_Init(Contact_Book* s)
{
	assert(s);
	s->_con_array = (Contact*)malloc(sizeof(Contact) * 8);//��ʼ��s->_con_array,���붯̬�ڴ�ռ䣬��СΪ8��Contact��С
	if (s->_con_array == NULL)//�ж�malloc�Ƿ�ִ�гɹ�
	{
		printf("malloc error\n");
		exit(-1);//�˳����򣬷���-1
	}
	s->_size = 0;
	s->_capacity = 8;
}
void Contact_Book_Destory(Contact_Book* s)
{
	assert(s);
	free(s->_con_array);//�ͷŶ�̬�ڴ�
	s->_con_array = NULL;//�ÿ�ָ�룬��ֹҰָ��
	s->_size = s->_capacity = 0;
}
void Contact_Book_Append(Contact_Book* s, Contact* con)
{
	assert(s && con);
	if (s->_size >= s->_capacity)//�жϴ�̨�ڴ��Ƿ��㹻
	{
		s->_capacity *= 2;//��̬�ڴ治��������*2
		Contact* newarray = (Contact*)realloc(s->_con_array, sizeof(Contact*) * s->_capacity);
		//�޸�����Ķ�̬�ڴ��СΪ�µ�capacity
		if (newarray == NULL)//�ж�realloc�Ƿ�ִ�гɹ�
		{
			printf("realloc error\n");
			exit(-1);
		}
		s->_con_array = newarray;//���µĶ�̬�ڴ��ַ����s->_con_array
	}
	Contact* array = s->_con_array;
	size_t i = s->_size;
	strcpy(array[i]._name, con->_name);
	strcpy(array[i]._tel, con->_tel);
	strcpy(array[i]._address, con->_address);
	array[i]._age = con->_age;

	s->_size++;//������ϵ����ɣ�s->_size++
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
		printf("���ļ�ʧ��\n");
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
		printf("���ļ�ʧ��\n");
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
		printf("����:> %s\n", s._con_array->_name);
		printf("�绰:> %s\n", s._con_array->_tel);
		printf("��ַ:> %s\n", s._con_array->_address);
		printf("����:> %d\n", s._con_array->_age);
		printf("**************************************\n");
	}
}