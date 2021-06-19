#include<stdlib.h>
#include<stdio.h>

typedef char DataType;
//�������Ľڵ�  ������
typedef struct BNode
{
	struct BNode* _left;
	struct BNode* _right;
	DataType _data;
}Node;

typedef struct BTree
{
	//�������ĸ��ڵ�
	Node* _root;
}BTree;

//void creatBinaryTree(BTree* bt)
//{
//	//����һ������
//	bt->_root = NULL;
//}

//����һ��������,���ض������ĸ��ڵ�ָ��
//�����˳��Ϊǰ�����
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

//ǰ�����
void preOrder(Node* root)
{
	if (root)
	{
		//  ��  ������  ������
		printf("c ", root->_data);

		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//�������
void preOrder(Node* root)
{
	if (root)
	{
		//  ������ ��   ������
		preOrder(root->_left);

		printf("c ", root->_data);
		preOrder(root->_right);
	}
}

//�������
void preOrder(Node* root)
{
	if (root)
	{
		//  ������  ������ ��   
		preOrder(root->_left);
		preOrder(root->_right);

		printf("c ", root->_data);
	}
}

//�ڵ����ͳ��
int bTreeSize(Node* root)
{
	if (root == NULL)
		return;
	//�������ڵ����+�������ڵ����+��ǰ�ڵ�
	//��ÿ���ڵ㶼���ɸ��ڵ����ұ���
	return bTreeSize(root->_left)
		+ bTreeSize(root->_right) + 1;
}

//���
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left = 1 : right + 1;
}

//Ҷ�ӽڵ����
int bTreeLeafSize(Node* root)
{
	//����
	if (root == NULL)
		return 0;
	//Ҷ�ӽڵ�
	if (root->_left == NULL || root->_right == NULL)
		return 1;
	//��Ҷ�ӽڵ�
	return bTreeLeafSize(root->_left)
		+ bTreeLeafSize(root->_right);
}

//����k��Ľڵ���
//������������(���ڵ㲻��)k-1��Ľڵ�����
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1)
		+ bTreeKSize(root->_right, k - 1);

}

//��һ���ڵ��λ��
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

//���ٶ�����
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

//����������
void bTreeLevelOrder(Node* root)
{
	//�������б���ڵ�
	Queue q;
	initQueue(&q);

	//���ڵ�������
	if (root)
		queuePush(&q, root);
	//���������е�ÿһ���ڵ�
	while (!queueEmoty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = queueFront(&q);
		//����
		queuePop(&q);
		printf("%d ", front->_data);
		//�����ͷԪ�ص����Һ��ӽڵ�
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}


//�ж��Ƿ���ȫ������:�������,�ڵ�����
//����ʵ��
int isCompleteBtree(Node* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmoty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = queueFront(&q);
		//����
		queuePop(&q);
		printf("%d ", front->_data);
		//�����ͷԪ�ص����Һ��ӽڵ�
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
			//����зǿսڵ�,,˵��������
			return 0;
	}
	return 1;
}


////����ʵ��
//int isCompleteBtree(Node* root)
//{
//	list q;
//	initList(&q);
//	if (root)
//		Push_back(&q, root);
//	while (!listEmoty(&q))
//	{
//		//��ȡ��ͷԪ��
//		Node* front = head(&q);
//		//����
//	    Pop_front(&q);
//		printf("%d ", front->_data);
//		//�����ͷԪ�ص����Һ��ӽڵ�
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
//			//����зǿսڵ�,,˵��������
//			return 0;
//	}
//	return 1;
//}
