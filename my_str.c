#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

char* my_strcpy(char* dest, const char* src)//�ַ�������
{
	assert(dest && src);
	char* str = dest;
	while (*str++ = *src++);
	return dest;
}

char* my_strncpy(char* dest, const char* src, int num)
{
	assert(dest && src);
	char* str = dest;
	while (num-- && *src)
	{
		*str++ = *src++;
	}
	return dest;
}
char* my_strcat(char* dest, const char* src)//�ַ�������
{
	assert(dest && src);
	char* str = dest;
	while (*str)
	{
		str++;
	}
	while (*str++ = *src++);
	return dest;
}

char* my_strncat(char* dest, const char* src, size_t num)
{
	assert(dest && src);
	char* str = dest;
	while (*str)
	{
		str++;
	}
	while (num-- && src)
	{
		*str++ = *src++;
	}
	*str = '\0';
	return dest;
}
char* my_strstr(const char* dest, const char* src)//�Ա��ַ���src�Ƿ��ǵ�dest���Ӵ�
{
	assert(dest && src);
	while (*dest)
	{
		const char* str1 = dest;
		const char* str2 = src;
		while (*str2 == *str1 && *str1)
		{
			++str1;
			++str2;
			if (*str2 == '\0')
			{
				return dest;
			}
		}
		dest++;
	}
	return NULL;
}

char* my_strchr(const char* dest, char c)//�����ַ���dest���״γ����ַ�c��λ��
{
	assert(dest);
	while (*dest && *dest != c)
	{
		++dest;
	}
	return *dest == c ? dest : NULL;
}

int my_strcmp(const char* dest, const char* src)//�Ƚ������ַ�������ͬ����0��dest����src����������destС��src���ظ���
{
	assert(dest && src);
	while (*dest && *src)
	{
		if (*(unsigned char*)dest < *(unsigned char*)src)
		{
			return -1;
		}
		else if (*(unsigned char*)dest > *(unsigned char*)src)
		{
			return 1;
		}
		else
		{
			++dest;
			++src;
		}
	}
	if (*dest != '\0')
	{
		return 1;
	}
	else if (*src != '\0')
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


void* my_memcpy(void* dest, const void* src, size_t n)//������strcpu��ͬ������memcpy�Ƿ��͵ģ����ԶԸ�������ʹ��
{
	assert(dest && src);
	char* str1 = (char*)dest;
	char* str2 = (const char*)src;
	while (n--)
	{
		*str1++ = *str2++;
	}
	return dest;
}

void* my_memmove(void* dest, const void* src, size_t n)//��memcpy��ȣ�memmove����������Դ��ַ��Ŀ���ַ�ڴ��ص������
{
	assert(dest && src);
	char* dest_ = (char*)dest;
	const char* src_ = (char*)src;//void*�������޷�ֱ��ʹ�õ�
	if (dest_ < src_ + n && dest_ > src_)//ǰ�ص�Ҫ�Ӻ���ǰcopy
	{                                             //&&�߼��루�ң�    &��λ��
		dest_ += n - 1;
		src_ += n - 1;
		while (n--)
		{
			*dest_-- = *src_--;
		}
	}
	else//���ص��Լ����ص�Ҫ��ǰ����copy
	{
		while (n--)
		{
			*dest_++ = *src_++;
		}
	}
	return dest;
}
int main()
{
	char* src = "word";
	char* dest = "hello ";
	char c = 'e';

	int arr1[4] = {0};
	int arr2[4] = {1,2,3,4};
	size_t n = sizeof(arr2);

	printf("%s\n", my_strncpy(dest, src, 3));

	/*printf("%s\n", my_strcat(dest, src));

	printf("%p\n", dest);
	printf("%p\n", my_strstr(dest, src));

	printf("%s\n", my_strchr(dest, c));

	printf("%d\n", my_strcmp(dest, src));

	my_memcpy(arr1, arr2, n);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr1[i]);
	}

	my_memmove(arr1, arr2, n);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr1[i]);
	}*/
	system("pause");
	return 0;
}