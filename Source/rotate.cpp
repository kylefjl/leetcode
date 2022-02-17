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
  *Others:       
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
            // if(i<k)
            // {
            //    nums[i]= nums_temp[n-k+i];
            // }
            // else
            // {
            //     nums[i]=nums_temp[i-k];
            // }
			
		}
    }
};
int main()
{	
    vector<int> nums={1,2,3,4,5,6,7,8,9};//初始化数组
	Solution1 solution1;
	solution1.rotate(nums,3);//右移3位
    printf("hello");
    system("pause");
    return 0;
}
