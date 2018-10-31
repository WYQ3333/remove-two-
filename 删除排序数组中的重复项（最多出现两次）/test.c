////给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现两次，返回移除后数组的新长度。
////不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//示例 1:
//给定数组 nums = [1, 1, 2],
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//
//你不需要考虑数组中超出新长度后面的元素。
//示例 2:
//给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//
//你不需要考虑数组中超出新长度后面的元素。
//说明 :
//为什么返回数值是整数，但输出的答案是数组呢 ?
//请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
////你可以想象内部操作如下 :
//// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
////int len = removeDuplicates(nums);
//
//// 在函数里修改输入数组对于调用者是可见的。
//// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
////for (int i = 0; i < len; i++) {
//	//print(nums[i]);
////}
#include<stdio.h>
#include<Windows.h>


int removeDuplicates(int* nums, int numsSize) {
	if (numsSize <= 2)//数组中只有两个数或者小于两个数的情况一定是“合法”的，直接返回原数组即可
	{
		return numsSize;
	}
	int count = 1;
	int k = 1;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			if (count < 2)
			{
				nums[k++] = nums[i];
				count++;
			}
		}
		else
		{
			count = 1;
			nums[k++] = nums[i];
		}
	}
	return k;
}

int main()
{
	int nums[] = { 1,1,2,4,4,4,4};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	int len = removeDuplicates(nums, numsSize);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", nums[i]);
	}
	system("pause");
	return 0;
}