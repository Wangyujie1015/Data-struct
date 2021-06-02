#include<stdlib.h>
#include<string.h>
#include"seqList.h"
#include<stdio.h>

void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

void seqListCheckCapacity(seqList* sl)
{
	if (sl->_capacity == sl->_size)
	{
		//�ռ�����,����
		//1.���µĿռ�
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		//2.����
		memcpy(tmp, sl->_data, sizeof(SLDataType) * sl->_size);
		//3.�ͷ�ԭ�пռ�
		free(sl->_data);

		sl->_data = tmp;

		 //sl->_data = (SLDataType*)realloc(sl->_data, newCapacity * sizeof(SLDataType));
		//4.��������
		sl->_capacity = newCapacity;
	 }
}




  
void seqListPushBack(seqList* sl, SLDataType val)
{
	if (sl == NULL)
		return;
	//�������
	seqListCheckCapacity(sl);
	//β��
	sl->_data[sl->_size] = val;
	sl->_size++;
}

//βɾ
void seqListpopBack(seqList* sl)
{
	if (sl == NULL)
		return;
	if(sl->_size > 0)
	sl->_size--; 
}

void seqListprint(seqList* sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->_size; i++)
	{
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}


SLDataType seqListAT(seqList* sl, int pos)
{
	return sl->_data[pos];
}

int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
		return 0;
	else
		return 1;
}

int seqLiseSize(seqList* sl)
{
	if (sl == NULL)
		return 0;
	else
		return sl->_size;
}

void test()
{
	seqList sl;
	initseqList(&sl);
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqListPushBack(&sl, 4);
	seqListPushBack(&sl, 5);
	seqListprint(&sl);
	seqListpopBack(&sl);
	seqListprint(&sl);
	seqListpopBack(&sl);
	seqListprint(&sl);
	seqListpopBack(&sl);
	seqListprint(&sl);
	seqListpopBack(&sl);
	seqListprint(&sl);
	seqListpopBack(&sl);
	seqListprint(&sl);

}

int main()
{
	test();
	return 0;
}