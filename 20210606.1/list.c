#include<stdlib.h >
#include<stdio.h>
typedef int LDataType;

//����ڵ�;����+ָ��
typedef struct listNode
{
	LDataType _data;
	struct LDataType* _next;
}listNode;

//����
typedef struct list
{
	listNode* _head;
}list;

void listInit(list* lst)
{
	//��ʼ��Ϊ������
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//�����½ڵ�
listNode* creatListNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
	{
		//�����һ���ڵ�
		//�����ڵ�
		lst->_head = creatListNode(val);
	}
	else
	{
		//�ӵ�һ���ڵ㿪ʼ����,�ҵ����һ���ڵ�
		listNode* tail = lst->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
 		}
		tail->_next = creatListNode(val);
	}
}

void listPopBack(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	//����,�ҵ����һ���ڵ�
	listNode* prev = NULL;
	listNode* tail = lst->_head;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}
	//�ͷ����һ���ڵ�
	free(tail);
	//����next 
	if (prev == NULL)//ֻ��һ���ڵ�,�ı�head
	//if (lst->_head->_next == NULL)
		lst->_head = NULL;
	else
	prev->_next = NULL;
}

//ͷ��
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//�����ڵ�
	listNode* node = creatListNode(val);
	//node head
	node->_next = lst->_head;
	lst->_head = node;
}

void listPopFront(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//�������
void listInsertAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;;
	listNode* newNode = creatListNode(val);
	listNode* next = node->_next;
	node->_next = newNode;
	newNode->_next = next;

}

//����ɾ��һ���ڵ����һ���ڵ�
void; istEraseAfter(listNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode* next = node->_next;
	listNode* nextnext = next->_next;

	//�ͷ�next
	free(next);
	node->_next = nextnext;
}

//����һ���ڵ�
listNode* listFind(list* lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		if (cur->_data == val)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

//����; �����ڵĽڵ�
void listDestroy(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		//������һ���ڵ�
		listNode* next = cur->_next;
		//�ͷŵ�ǰ�ڵ�
		free(cur);
		//���µ���һ���ڵ�λ��
		cur = next;
	}
	lst->_head = NULL;
}

void test()
{
	list lst;
	listInit(&lst);
	listPushFront(&lst, 6);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
}

int main()
{
	test();
	return 0;
}
