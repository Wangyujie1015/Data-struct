#include<stdlib.h>
#include<stdio.h>

typedef char DataType;
//二叉树的节点  二叉链
typedef struct BNode
{
	struct BNode* _left;
	struct BNode* _right;
	DataType _data;
}Node;

typedef struct BTree
{
	//二叉树的根节点
	Node* _root;
}BTree;

//void creatBinaryTree(BTree* bt)
//{
//	//创建一个空树
//	bt->_root = NULL;
//}

//创建一个二叉树,返回二叉树的根节点指针
//数组的顺序为前序遍历
Node* creatBinaryTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}

	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;

}

//前序遍历
void preOrder(Node* root)
{
	if (root)
	{
		//  根  左子树  右子树
		printf("c ", root->_data);

		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//中序遍历
void preOrder(Node* root)
{
	if (root)
	{
		//  左子树 根   右子树
		preOrder(root->_left);

		printf("c ", root->_data);
		preOrder(root->_right);
	}
}

//后序遍历
void preOrder(Node* root)
{
	if (root)
	{
		//  左子树  右子树 根   
		preOrder(root->_left);
		preOrder(root->_right);

		printf("c ", root->_data);
	}
}

//节点个数统计
int bTreeSize(Node* root)
{
	if (root == NULL)
		return;
	//左子树节点个数+右子树节点个数+当前节点
	//把每个节点都当成根节点左右遍历
	return bTreeSize(root->_left)
		+ bTreeSize(root->_right) + 1;
}

//层高
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left = 1 : right + 1;
}

//叶子节点个数
int bTreeLeafSize(Node* root)
{
	//空树
	if (root == NULL)
		return 0;
	//叶子节点
	if (root->_left == NULL || root->_right == NULL)
		return 1;
	//非叶子节点
	return bTreeLeafSize(root->_left)
		+ bTreeLeafSize(root->_right);
}

//返回k层的节点数
//就是左右字树(根节点不算)k-1层的节点数和
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1)
		+ bTreeKSize(root->_right, k - 1);

}

//找一个节点的位置
Node* bTreeFind(Node* root, char ch)
{
	if (root)
	{
		if (root->_data == ch)
			return root;
		Node* node = bTreeFind(root->_left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->_right, ch);
	}
	else
		return NULL;
}

//销毁二叉树
void bTreeDestory(Node** root)
{
	if (*root)
	{
		bTreeDestory(&((*root)->_left));
		bTreeDestory(&((*root)->_left));

		free(*root);
		*root = NULL;
	}
}

//层序遍历输出
void bTreeLevelOrder(Node* root)
{
	//借助队列保存节点
	Queue q;
	initQueue(&q);

	//根节点存入队列
	if (root)
		queuePush(&q, root);
	//遍历队列中的每一个节点
	while (!queueEmoty(&q))
	{
		//获取队头元素
		Node* front = queueFront(&q);
		//出队
		queuePop(&q);
		printf("%d ", front->_data);
		//保存队头元素的左右孩子节点
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}


//判断是否完全二叉树:层序遍历,节点连续
//队列实现
int isCompleteBtree(Node* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmoty(&q))
	{
		//获取队头元素
		Node* front = queueFront(&q);
		//出队
		queuePop(&q);
		printf("%d ", front->_data);
		//保存队头元素的左右孩子节点
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break;
		
	}
	while (!queueEmoty(&q))
	{
		Node* front = queueFront(&q);
		queuePop(&q);
		if (front)
			//如果有非空节点,,说明不连续
			return 0;
	}
	return 1;
}


////链表实现
//int isCompleteBtree(Node* root)
//{
//	list q;
//	initList(&q);
//	if (root)
//		Push_back(&q, root);
//	while (!listEmoty(&q))
//	{
//		//获取队头元素
//		Node* front = head(&q);
//		//出队
//	    Pop_front(&q);
//		printf("%d ", front->_data);
//		//保存队头元素的左右孩子节点
//		if (front)
//		{
//			Push_back(&q, front->_left);
//			Push_back(&q, front->_right);
//		}
//		else
//			break;
//
//	}
//	while (!listEmoty(&q))
//	{
//		Node* front = head(&q);
//		pop_front(&q);
//		if (front)
//			//如果有非空节点,,说明不连续
//			return 0;
//	}
//	return 1;
//}
