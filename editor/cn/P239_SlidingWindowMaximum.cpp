//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
// 滑动窗口每次只向右移动一位
//。 
//
// 返回 滑动窗口中的最大值 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2240 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 滑动窗口最大值
* @author name
* @date 2023-04-11 20:31:02
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
   // 优先级队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> queue;
        for (int i = 0; i <k-1 ; ++i)
        {
            queue.emplace(nums[i],i);
        }

        vector<int> res(nums.size()-(k-1));//结果数组
        for (int i = k-1; i <nums.size() ; ++i)
        {
            queue.emplace(nums[i],i);//添加元素
            while(queue.top().second<i-(k-1)) queue.pop();//弹出不在窗口内的元素
            res[i-(k-1)]=queue.top().first;//将窗口内最大值放入结果数组
        }
        return res;
    }

//   单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        assert(k>0&&nums.size()>=k);//k必须大于0，且nums的长度必须大于等于k
        vector<int> res(nums.size()-(k-1));//结果数组
        deque<pair<int,int>> d_equeue;//单调增 双端队列 存放的是元素的值和下标
        for (int i = 0; i <nums.size() ; ++i)//遍历数组，模拟滑窗
        {
            while(!d_equeue.empty()&&d_equeue.front().first<=nums[i])d_equeue.pop_front();//弹出队列头中小于当前元素的元素
            d_equeue.emplace_front(nums[i],i);//将当前元素放入队列头
            while(!d_equeue.empty()&&d_equeue.back().second<=(i-k))d_equeue.pop_back();//弹出队列尾不在窗口内的元素
            if(i>=(k-1))res[i-(k-1)]=d_equeue.back().first;//将窗口内最大值放入结果数组
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
//   vector<int> nums={1,3,-1,-3,5,3,6,7};
   vector<int> nums={1};
   int k=1;
   auto res=s.maxSlidingWindow(nums,k);
copy(res.begin(),res.end() ,ostream_iterator<int>(cout," "));
   return 0;
}