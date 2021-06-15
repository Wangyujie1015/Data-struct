#include<stdio.h>


void shiftUp(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		//需要调整的数据和最小值比较
		if (arr[child] > arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			//更新位置
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}


//向下调整算法
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//需要调整的数据和最小值比较
		if (arr[child] < arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			//更新位置
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