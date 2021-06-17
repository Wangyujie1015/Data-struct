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