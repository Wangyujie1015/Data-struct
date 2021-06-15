#include<stdio.h>


void shiftUp(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		//��Ҫ���������ݺ���Сֵ�Ƚ�
		if (arr[child] > arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			//����λ��
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}


//���µ����㷨
void shiftDown(int* arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//��Ҫ���������ݺ���Сֵ�Ƚ�
		if (arr[child] < arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			//����λ��
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}


void test()
{
	int arr[] = { 7,56,30,25,15,10 };
	shiftUp(arr, sizeof(arr) / sizeof(arr[0]), 0);
}

int main()
{
	test();
	return 0;
}