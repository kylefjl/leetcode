


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
  *Function:       求最大利润
  *Description：    增区间累加   Calls:
  *Called By:  
  *Input:          数组
  *Output:        累加值
  *Return:   
  *Others:    
**********************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n=prices.size();
		int maxp=0;
		if (n==0)//数组为空返回
		{
			return 0;
		}
		for(int i=0;i<n-1;i++)
		{
			prices[i]=prices[i+1]-prices[i];//求插值
			if(prices[i]>=0)//累加正值
			{
				maxp+=prices[i];
			}
		}
		return maxp;//返回最大利润
    }
};
int main()
{	
	vector<int> nums={1,2,3,4,4,4,4,7,8,9};//初始化数组，对应10天的股票值
	Solution solution;
	int maxp=solution.maxProfit(nums);
	printf("max profit %d\n",maxp);
	system("pause");
	return 0;
}
