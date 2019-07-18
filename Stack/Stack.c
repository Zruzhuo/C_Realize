#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_top = 0;
	ps->capcity = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array != NULL)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->capcity = ps->_top = 0;
	}
}
void StackPush(Stack* ps, STDateType x)
{
	assert(ps);
	if (ps->_top == ps->capcity)
	{
		size_t newcapcity = ps->capcity = 0 ? 2 : ps->capcity * 2;
		ps->_array = (STDateType*)realloc(ps->_array, newcapcity * sizeof(STDateType));
		ps->capcity = newcapcity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}
STDateType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top - 1];
}
size_t StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}