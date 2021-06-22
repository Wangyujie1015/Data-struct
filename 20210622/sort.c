#include<stdio.h>

void swap(int* arr, int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
//ѡ������
void selectSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		
		for (int j = i+1; j < n; j++)
		{
			//�ҵ��������Сֵ
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		//����Сֵ������ 
		int tmp = arr[min];
		arr[min] = arr[i];
		arr[i] = tmp;
	}
}


//��������1.0

int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])//mid end begin
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[mid] < arr[end])
			return mid;
		else if (arr[begin] < arr[end])
			return end;
		else//end begin mid
			return begin;
	}
}

int patrion(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	int tmp = mid;
	mid = arr[begin];
	arr[begin] = tmp;
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
			--end;
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		int tmp = arr[end];
		arr[end] = arr[begin];
		arr[begin] = tmp;
	}
	//������׼ֵ������λ�õ�����
	int tmp = arr[start];
	arr[start] = arr[begin]; 
	arr[begin] = tmp;
	return begin;
}

//2.0
int patrion(int* arr, int begin, int end)
{
	int key = arr[begin];

	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
			--end;

		    arr[begin] = arr[end];
		while (begin < end && arr[begin] <= key)
			++begin;
			arr[end] = arr[begin];


	}
	arr[begin] = key;
	return begin;

}

void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div:һ�λ���֮��Ļ�׼ֵλ��
	int div = patrion(arr, begin, end);
		//���������ֽ��п�������
		//[begin,div-1]
		//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
}


void test()
{
	int arr[] = { 2,5,6,8,3,4,7,20,65,1};
	selectSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{

	return 0;
}