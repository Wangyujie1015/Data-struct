#include<stdio.h>

//插入排序
void insertSort(int* arr,int n)
{
	//假设第一个数据有序
	for (int i = 1; i < n; i++)
	{
		//从有序数据的最后一个向前遍历
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > data)
		{
			//大数据向后移动
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}

}




//希尔排序   插入排序的优化
//1.先分组,进行大步长的插入排序,是数据(接近有序)
//2.最后全部一组,进行插入排序

void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//保证最后有一趟是gap=1
		gap = gap / 3 + 1;
		//一趟希尔排序
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= end;
			}
			arr[end + gap] = data;
		}
	}
}


//选择排序

int main()
{
	return 0;
}