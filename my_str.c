#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

char* my_strcpy(char* dest, const char* src)//字符串复制
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
char* my_strcat(char* dest, const char* src)//字符串连接
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
char* my_strstr(const char* dest, const char* src)//对比字符串src是否是的dest的子串
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

char* my_strchr(const char* dest, char c)//查找字符串dest中首次出现字符c的位置
{
	assert(dest);
	while (*dest && *dest != c)
	{
		++dest;
	}
	return *dest == c ? dest : NULL;
}

int my_strcmp(const char* dest, const char* src)//比较两个字符串，相同返回0，dest大于src返回正数，dest小于src返回负数
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


void* my_memcpy(void* dest, const void* src, size_t n)//作用与strcpu相同，但是memcpy是泛型的，可以对各种类型使用
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

void* my_memmove(void* dest, const void* src, size_t n)//与memcpy相比，memmove可以适用于源地址与目标地址内存重叠的情况
{
	assert(dest && src);
	char* dest_ = (char*)dest;
	const char* src_ = (char*)src;//void*类型是无法直接使用的
	if (dest_ < src_ + n && dest_ > src_)//前重叠要从后往前copy
	{                                             //&&逻辑与（且）    &按位与
		dest_ += n - 1;
		src_ += n - 1;
		while (n--)
		{
			*dest_-- = *src_--;
		}
	}
	else//后重叠以及不重叠要从前往后copy
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