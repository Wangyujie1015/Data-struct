#include<stdio.h>

void swap(int* arr, int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}


//ǰ��ָ�뷽��
void quickSort(int* arr, int begin, int end)
{
	int key = arr[begin];

	// ��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;
	while (cur <= end)
	{
		//��cur�ߵ���һ��λ��,�ж��Ƿ�����
		if (arr[cur] < key && ++prev != cur)
		{
			//������,��������
			swap(arr, prev, cur);
		}
		++cur;
	}
	swap(arr, begin, prev);
	return prev;

}


//�ǵݹ���� :������ջ����ķ���
void quickSort(int* arr, int n)
{
	seqList sq;
	initseqList(&sq);
	//���ȱ�����������
	//�ȷ���,�ٷ���
	seqListPushBack(&sq, n - 1);
	seqListPushBack(&sq, 0);
	//����˳���,������������
	while (!seqListEmpty(&sq))
	{
		int left = seqListBack(&sq);
		seqListpopBack(&sq);
		int right = seqListBack(&sq);
		seqListpopBack(&sq);

		//��������[left,right]
		int div = partion(arr, left, right);

		//�������������������
		//[left,div-1]
		if (left < div - 1)
		{
			seqListPush(&sq, div - 1); 
	        seqListPush(&sq, left);

		}
		//[div+1,right]
		if (div <= right)
		{
			seqListPush(&sq, right);
			seqListPush(&sq, div+1); 

		}
	}

 }