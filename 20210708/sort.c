#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void merge(int* arr, int begin, int mid, int end, int* tmp)
{
	//递增
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//辅助空间的起始位置
	int idx = begin;
	//合并有序序列
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//判断是否有未合并的元素
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//合并后的序列拷贝到原始数组的对应区间
	memcpy(arr+begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2; 
	//先合并子序列
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//合并两个有序的子序列
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}