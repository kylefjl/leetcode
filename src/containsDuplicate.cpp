#include <stdio.h>
#include <stdlib.h>
#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;//命名空间
#define uint16 wchar_t
#define uint32 unsigned int
#define uint8 unsigned char
#define int16 short
/*********************************************************************************
  *Function:     查询重复数组
  *Description： 1：有重复 0：无重复
  *Calls:        
  *Called By:    
  *Input:        数组
  *Output:       
  *Return:       1：有重复 0：无重复
  *Others:       先排序，再比较
**********************************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return 1;
            }
        }
        return 0;
    }
};
int main()
{		
    vector<int> nums={1,2,3,4,4,4,4,7,8,9};//初始化数组，对应10天的股票值
	Solution solution;
	bool flag=solution.containsDuplicate(nums);
    printf("flag  :%d\n",flag);
    system("pause");
    return 0;
}
