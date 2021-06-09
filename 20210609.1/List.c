#include<stdio.h>
#include<stdlib.h>


typedef int LDataType;

//双向节点
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

//双向带头循环链表
typedef struct List
{
	struct ListNode* _head;
}List;

void initList(List* lst)
{
	//构建循环结构
	//创建头结点
	lst->_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//循环
	lst->_head->_prev = lst->_head->_next = lst->_head;
}

struct ListNode* creatNode(LDataType  val)
{
	 struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	 node->_data = val;
	 node->_next = node->_prev = NULL;
	 return node;
};

//尾插
void listPushBack(List* lst, LDataType val)

{
	struct ListNode* tail = lst->_head->_prev;
	struct ListNode* newNode = creatNode(val);

	tail->_next = newNode;
	newNode->_prev = tail;

	lst->_head->_prev = newNode;
	newNode->_next = lst->_head;

}

void listprint(List* lst)
{
	struct ListNode* cur = lst->_head->_next;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
		if (cur == lst->_head)
			break;
	}
}

void test()
{
	struct List lst;
	initList(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	listprint(&lst);
}

int main()
{
	test();
	return 0;
}