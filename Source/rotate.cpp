#include <stdio.h>
#include <stdlib.h>
#include <vector> 
#include <iostream>
using namespace std;//命名空间
#define uint16 wchar_t
#define uint32 unsigned int
#define uint8 unsigned char
#define int16 short
/*********************************************************************************
  *Function:     右移
  *Description： 数字右移
  *Calls:        
  *Called By:    
  *Input:        数组，右移位数
  *Output:       
  *Return:       
  *Others:       创建暂存数组
**********************************************************************************/
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) 
    {
		int n=nums.size();
        k=k%n;
        vector<int> nums_temp=nums;//暂存
		for(int i=0;i<n;i++)
		{
			nums[i] = nums_temp[(n - k + i)%n];//
           
			
		}
    }
};

/*********************************************************************************
  *Function:     右移
  *Description： 数字右移
  *Calls:        
  *Called By:    
  *Input:        数组，右移位数
  *Output:       
  *Return:       
  *Others:       翻转
**********************************************************************************/
class Solution2 {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
int main()
{	
    vector<int> nums1={1,2,3,4,5,6,7,8,9};//初始化数组
    vector<int>nums2=nums1;
	Solution1 solution1;
	Solution2 solution2;
	solution1.rotate(nums1,3);//右移3位，利用暂存数组
    solution2.rotate(nums2,3);//右移3位，利用翻转数组
    
    printf("hello");
    system("pause");
    return 0;
}
