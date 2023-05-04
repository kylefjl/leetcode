# 滑动窗口中

## 大小堆 优先队列

和P295 数据流的中位数 相似，多了个“删除元素的过程”

https://leetcode.cn/problems/sliding-window-median/solution/hua-dong-chuang-kou-zhong-wei-shu-by-lee-7ai6/



```c++
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
```

