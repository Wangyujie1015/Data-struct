#include<stdio.h>

//��������
void insertSort(int* arr,int n)
{
	//�����һ����������
	for (int i = 1; i < n; i++)
	{
		//���������ݵ����һ����ǰ����
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > data)
		{
			//����������ƶ�
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}

}




//ϣ������   ����������Ż�
//1.�ȷ���,���д󲽳��Ĳ�������,������(�ӽ�����)
//2.���ȫ��һ��,���в�������

void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//��֤�����һ����gap=1
		gap = gap / 3 + 1;
		//һ��ϣ������
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


//ѡ������

int main()
{
	return 0;
}