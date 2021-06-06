#include<stdlib.h >
#include<stdio.h>
typedef int LDataType;

//定义节点;数据+指针
typedef struct listNode
{
	LDataType _data;
	struct LDataType* _next;
}listNode;

//链表
typedef struct list
{
	listNode* _head;
}list;

void listInit(list* lst)
{
	//初始化为空链表
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//创建新节点
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
		//插入第一个节点
		//创建节点
		lst->_head = creatListNode(val);
	}
	else
	{
		//从第一个节点开始遍历,找到最后一个节点
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
	//遍历,找到最后一个节点
	listNode* prev = NULL;
	listNode* tail = lst->_head;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}
	//释放最后一个节点
	free(tail);
	//更新next 
	if (prev == NULL)//只有一个节点,改变head
	//if (lst->_head->_next == NULL)
		lst->_head = NULL;
	else
	prev->_next = NULL;
}

//头插
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//创建节点
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

//随意插入
void listInsertAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;;
	listNode* newNode = creatListNode(val);
	listNode* next = node->_next;
	node->_next = newNode;
	newNode->_next = next;

}

//随意删除一个节点的下一个节点
void; istEraseAfter(listNode* node)
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode* next = node->_next;
	listNode* nextnext = next->_next;

	//释放next
	free(next);
	node->_next = nextnext;
}

//查找一个节点
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

//销毁; 链表内的节点
void listDestroy(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		//保存下一个节点
		listNode* next = cur->_next;
		//释放当前节点
		free(cur);
		//更新到下一个节点位置
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
