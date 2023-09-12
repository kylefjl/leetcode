//给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。 
//
// 实现 MovingAverage 类： 
//
// 
// MovingAverage(int size) 用窗口大小 size 初始化对象。 
// double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均
//值，即滑动窗口里所有数字的平均值。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//inputs = ["MovingAverage", "next", "next", "next", "next"]
//inputs = [[3], [1], [10], [3], [5]]
//输出：
//[null, 1.0, 5.5, 4.66667, 6.0]
//
//解释：
//MovingAverage movingAverage = new MovingAverage(3);
//movingAverage.next(1); // 返回 1.0 = 1 / 1
//movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
//movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
//movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= size <= 1000 
// -10⁵ <= val <= 10⁵ 
// 最多调用 next 方法 10⁴ 次 
// 
//
// 
//
// 
// 注意：本题与主站 346 题相同： https://leetcode-cn.com/problems/moving-average-from-data-
//stream/ 
//
// Related Topics 设计 队列 数组 数据流 👍 95 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 滑动窗口的平均值
* @author name
* @date 2023-04-12 17:01:11
*/
//leetcode submit region begin(Prohibit modification and deletion)
template <typename T, int M>//模板参数 T为数据类型，M为窗口大小
class MovingAverage {
public:
    /** Initialize your data structure here. */
    static_assert(M>1, "SMA require window width>1");
    MovingAverage():window_sum(0),nums(M),nums_size(0)
    {
    }
    double next(T val) {
        window_sum += val;//加入新的值
        if(M==nums_size)//满了
        {
            window_sum-= nums[left_idx];//减去最早的值
            nums[left_idx]=val;//记录新的值
            left_idx=(left_idx+1)%M;//更新最早的值的位置
        }
        else
        {
            nums[nums_size]=val;//记录新的值
            ++nums_size;//更新记录的值的个数
        }

        return static_cast<T>(window_sum)/static_cast<T>(nums_size);//返回平均值
    }
    int nums_size;//记录的值的个数
    vector<int> nums;//记录的值
    int left_idx=0;//最早的值的位置
    T window_sum=0;//窗口的和
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    MovingAverage<int,3> movingAverage;
}