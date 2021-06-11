#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;


//顺序结构实现:顺序表,提供尾插尾删的接口
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;


void initStack(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapacity(stack* st)
{
	if (st->_size == st->_capacity)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType) * newCap);
		st->_capacity = newCap;
	}
}

void stackPush(stack* st, STDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack* st)
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}

int stacksize(stack* st)
{
	if (st == NULL)
		return;
	return st->_size;
}


int stackEmptty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;

}


STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}

void test()
{

	stack st;
	initStack(&st);

	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);

	while (!(stackEmptty(&st)))
	{
		printf("%d ", stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}


int main()
{
	test();
	return 0;
}