#include<stdio.h>

void swap(int* arr, int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}


//前后指针方法
void quickSort(int* arr, int begin, int end)
{
	int key = arr[begin];

	// 上一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = begin + 1;
	while (cur <= end)
	{
		//当cur走到下一个位置,判断是否连续
		if (arr[cur] < key && ++prev != cur)
		{
			//不连续,交换数据
			swap(arr, prev, cur);
		}
		++cur;
	}
	swap(arr, begin, prev);
	return prev;

}


//非递归快排 :不会有栈溢出的风险
void quickSort(int* arr, int n)
{
	seqList sq;
	initseqList(&sq);
	//首先保存整个区间
	//先放右,再放左
	seqListPushBack(&sq, n - 1);
	seqListPushBack(&sq, 0);
	//遍历顺序表,处理所有区间
	while (!seqListEmpty(&sq))
	{
		int left = seqListBack(&sq);
		seqListpopBack(&sq);
		int right = seqListBack(&sq);
		seqListpopBack(&sq);

		//划分区间[left,right]
		int div = partion(arr, left, right);

		//保存产生的两个新区建
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