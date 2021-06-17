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
Node* creatBinaryTree(DataType arr[], int idx)
{
	if (arr[idx] == '#')
	{
		idx++; 
		return NULL;
	}
	
	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[idx++];

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;


}