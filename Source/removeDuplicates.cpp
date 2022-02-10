

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include < vector> 
using namespace std;
#define uint16 unsigned int
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int similar_remove(int* nums,unsigned char size)//去重
{
	int* left;
	int* right;
	uint16 nums_long=1;
	left = nums;
	right=nums+1;
	for (int i = 0; i < size-1; i++)
   {
	   if(*left==*right)//左右相同，右指针右移
	   {
		right++;
	   }
	   else//左右不同，左指针左移，赋值为右指针
	   {
		   left++;
		   *left=*right;
		   right++;
		   nums_long++;
	   }
   }
	return nums_long;//返回数据长度
}
int main()
{
	int nums[10]={1,2,3,4,4,4,4,7,8,9};
	uint16 numlong = 0;	
	unsigned char size;
	size = sizeof(nums)/4;
	numlong=similar_remove(nums, size);
	printf("long:%d\n",numlong);
	system("pause");
	return 0;
}
