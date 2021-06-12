#include<stdio.h>
#include<stdlib.h>

//队列:带有尾指针的单链表

typedef int QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode* _next;
}QNode;

typedef struct Queue
{
	//头尾指针
	struct QNode* _head;
	struct QNode* _tail;
	int _size;
}Queue;

void initQueue(Queue* q)
{
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}

int queueEmpty(Queue* q)
{
	return q->_head == NULL;

}

struct QNode* creatNode(QDataType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
void queuePush(Queue* q, QDataType val)
{
	if (q == NULL)
		return;
	struct QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
	++q->_size;
}

void queuePop(Queue* q)
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	if (q->_head == NULL)
		q->_tail = NULL;//空队列

	--q->_size;
} 

QDataType queueFront(Queue* q)
{
	return q->_head->_data;
}

QDataType queueBack(Queue* q)
{
	return q->_tail->_data; 
}

int queueSize(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->_size;
}




void test()
{
	struct Queue q;
	initQueue(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
}

int main()
{
	test();
	return 0;
}


//用栈实现队列
typedef struct {
	struct stack q1;
	struct stack q2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* pq = (struct MyQueue)malloc(sizeof(struct MyQueue));
	initStack(&pq->q1);
	initStack(&pq->q2);
	return pq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->q1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int front;
	//判断出队栈是否为空
	if (!stackEmpty(&obj->q2))
	{
		front = stackTop(&obj->q2)
			stackPop(&obj->q2);
	}
	else
	{
		//把入栈队元素给出队栈
		while (!stackEmpty(&obj->q1))
		{
			stackPush(&obj->q2, stackTop(&obj->q1));
			stackPop(&obj->q1);
		}
		front = stackTop(&obj->q2);
		stackPop(&obj->q2);
	}
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (stackEmpty(&obj->q2))
	{
		//把入栈队元素给出队栈
		while (!stackEmpty(&obj->q1))
		{
			stackPush(&obj->q2, stackTop(&obj->q1));
			stackPop(&obj->q1);
		}
	}
	return stackTop(&obj->q2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return stackEmpty(&obj->q1) && stackEmpty(&obj->q2);
}

void myQueueFree(MyQueue* obj) {
	stackDestory(&obj->q1);
	stackDestory(&obj->q2);
	free(obj);

}




//用队列实现栈

typedef struct {
	struct Queue q;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	initQueue(&pst->q);
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	queuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int n = queueSize(&obj->q);
	whwile(n > 1)
	{
		int front = queueFront(&obj->q);
		queuePop(&obj->q);
		queuePush(&obj->q, front);
		--n;
	}
	int top = queueFront(&obj->q);
	queuePop(&obj->q);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->q)
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
	queueDestroy(&obj->q);
	free(obj);
}
