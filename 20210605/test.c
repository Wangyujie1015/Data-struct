#include<stdio.h>

//数组里跳过一个数字，输出最后数组长度
int removeElement(int* nums, int numSize, int val)
{
	int i = 0;
	int dix = 0;
	for (i = 0; i < numSize; ++i)
	{
		if (nums[i] != val)
		{
			nums[dix++] = nums[i];
		}
	}
	return dix;
}

//2. 删除排序数组中的重复项。
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1)
        return numsSize;
    int i = 0, j = 1, idx = 0;
    while (j < numsSize)
    {
        nums[idx++] = nums[i];
        if (nums[i] == nums[j])
        {
            while (j < numsSize && nums[i] == nums[j])
                ++j;
            i = j;
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    if (i < numsSize)
    {
        nums[idx++] = nums[i];
    }
    return idx;
}

//合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* num3 = (int*)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, idx = 0;
    //同时遍历
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            num3[idx++] = nums1[i++];
        }
        else
        {
            num3[idx++] = nums2[j++];
        }
    }
    //直接拷贝剩余元素
    if (i < m)
    {
        memcpy(num3 + idx, nums1 + i, sizeof(int) * (m - i));
    }
    if (j < n)
    {
        memcpy(num3 + idx, nums2 + j, sizeof(int) * (n - j));
    }
    memcpy(nums1, num3, sizeof(int) * (m + n));
    free(num3);
}


int main()
{
	return 0;
}