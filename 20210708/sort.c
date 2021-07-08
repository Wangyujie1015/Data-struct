#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void merge(int* arr, int begin, int mid, int end, int* tmp)
{
	//����
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ����ʼλ��
	int idx = begin;
	//�ϲ���������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//�ж��Ƿ���δ�ϲ���Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//�ϲ�������п�����ԭʼ����Ķ�Ӧ����
	memcpy(arr+begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2; 
	//�Ⱥϲ�������
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);
	//�ϲ����������������
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}