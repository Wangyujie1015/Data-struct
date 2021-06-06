#include<stdio.h>

//合并两个有序数组
//void merge(int* nums1, int nums1Size, int m,
//	int* nums2, int nums2Size, int n) {
//
//	int i = m - 1, j = n - 1, idx = m + n - 1;
//	while (i >= 0 && j >= 0)
//	{
//		if (nums1[i] >= nums2[j])
//		{
//			nums1[idx++] = nums1[i--];
//		}
//		else
//		{
//			nums1[idx++] = nums2[j--];
//		}
//	}
//	if (j > 0)
//	{
//		memcpy(nums1, nums2, sizeof(int) * (j + 1));
//	}
//}


//右旋转数组元素
//void reverse(int* arr, int a, int b)
//{
//	int c = 0;
//	while (a < b)
//	{
//		c = arr[a];
//		arr[a] = arr[b];
//		arr[b] = c;
//		a++;
//		b--;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k) 
//{
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reserve(nums, 0, numsSize - 1);
//}

//2.0
//void reverse(int* nums, int start, int end)
//{
//	while (start < end)
//	{
//		nums[start] = nums[start] ^ nums[end];
//		nums[end] = nums[start] ^ nums[end];
//		nums[start] = nums[start] ^ nums[end];
//		++start;
//		--end;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reverse(nums, 0, numsSize - 1);
//}
int main()
{
	return 0;
}