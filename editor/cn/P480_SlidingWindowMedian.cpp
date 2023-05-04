//中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。 
//
// 例如： 
//
// 
// [2,3,4]，中位数是 3 
// [2,3]，中位数是 (2 + 3) / 2 = 2.5 
// 
//
// 给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗
//口中元素的中位数，并输出由它们组成的数组。 
//
// 
//
// 示例： 
//
// 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。 
//
// 
//窗口位置                      中位数
//---------------               -----
//[1  3  -1] -3  5  3  6  7       1
// 1 [3  -1  -3] 5  3  6  7      -1
// 1  3 [-1  -3  5] 3  6  7      -1
// 1  3  -1 [-3  5  3] 6  7       3
// 1  3  -1  -3 [5  3  6] 7       5
// 1  3  -1  -3  5 [3  6  7]      6
// 
//
// 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。 
//
// 
//
// 提示： 
//
// 
// 你可以假设 k 始终有效，即：k 始终小于等于输入的非空数组的元素个数。 
// 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。 
// 
//
// Related Topics 数组 哈希表 滑动窗口 堆（优先队列） 👍 415 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 滑动窗口中位数
* @author name
* @date 2023-04-12 16:53:51
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //滑动窗口中位数
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        for (int i = 0; i < k; ++i)//先将前k个元素插入到堆中
        {
            addNum(nums[i]);//
            blance();//平衡两个堆并查看堆顶是否是需要删除元素
        }
        vector<double> ans = {findMedian()};//将第一个中位数插入到数组中
        ans.reserve(nums.size() - k + 1);//预留空间
        for (int i = k; i < nums.size(); ++i) {
            addNum(nums[i]);
            erase(nums[i - k]);
            ans.push_back(findMedian());
        }
        return ans;
    }
    //插入元素
    void addNum(int num) {
        if((largeSize==0&&smallSize==0)||(largeSize!=0&&num<queue_big.top()))//如果都为空或者小于大顶堆的堆顶
        {
            queue_big.push(num);//插入大顶堆
            ++largeSize;//大顶堆的有效元素个数加一
        }
        else//如果大于等于大顶堆的堆顶
        {
            queue_small.push(num);//插入小顶堆
            ++smallSize;//小顶堆的有效元素个数加一
        }
    }
    //查找中位数
    double findMedian()
    {
        if(largeSize==smallSize)//如果两个堆的元素相等
        {
            return (static_cast<double>(queue_big.top())+queue_small.top())/2.0;//返回两个堆顶元素的平均值
        }
        else if (largeSize>smallSize) return queue_big.top();//如果大顶堆的元素多
        else return queue_small.top();

    }
    //删除元素
    template<typename T>
    void prune(T& heap) {
        while (!heap.empty()&&delayed.count(heap.top())&&delayed[heap.top()])//如果堆不为空且堆顶元素在delayed中
        {
            --delayed[heap.top()];//标记这个元素删除了一次
            heap.pop();//删除堆顶元素
        }
    }
//平衡两个堆
    void blance()
    {
        while (1)
        {
            if(largeSize>smallSize+1)//如果大顶堆的元素多于小顶堆的元素
            {
                queue_small.push(queue_big.top());//将大顶堆的堆顶元素插入小顶堆
                queue_big.pop();//删除大顶堆的堆顶元素
                --largeSize;//大顶堆的有效元素个数减一
                ++smallSize;//小顶堆的有效元素个数加一
                prune(queue_big);//删除大顶堆中的无效元素
            }
            else if(smallSize>largeSize+1)//如果小顶堆的元素多于大顶堆的元素
            {
                queue_big.push(queue_small.top());//将小顶堆的堆顶元素插入大顶堆
                queue_small.pop();//删除小顶堆的堆顶元素
                --smallSize;
                ++largeSize;
                prune(queue_small);//删除小顶堆中的无效元素
            }
            else break;//如果两个堆的元素相等或者相差1，跳出循环
        }
    }

    void erase(int num) {
        ++delayed[num];//标记这个元素需要删除
        if (largeSize!=0 &&num<= queue_big.top())--largeSize;//如果这个元素在大顶堆中，大顶堆的有效元素个数减一
        else --smallSize;//否则在小顶堆中，小顶堆的有效元素个数减一
        prune(queue_big);//删除大顶堆中的无效元素
        prune(queue_small);//删除小顶堆中的无效元素
        blance();//平衡两个堆
    }

private:
    unordered_map<int, int> delayed;//记录需要删除的元素（延迟删除）
    priority_queue<int,vector<int>,greater<>> queue_small;//小顶堆
    priority_queue<int> queue_big;//大顶堆
    int smallSize=0, largeSize=0;//记录两个堆的有效元素个数（有效元素指的是窗口内的元素）

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> nums = {7,9,3,8,0,2,4,8,3,9};
    int k = 1;
    auto result=s.medianSlidingWindow(nums,k);
    //打印result
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
    return 0;
}