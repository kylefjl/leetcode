# 滑动窗口最大值

## 优先队列

优先队列的本质是大根堆

- 每次把一个新的元素放入优先队列，此时堆顶的元素就是堆中所有元素的最大值。
- 判断最大值在不在滑动窗口中，如果不再，弹出，继续找下一个最大值，之到最大值在滑窗内

```cc
//先级队列
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
```

 **时间复杂度**  $nlog(n)$

## 单调队列

维护一个单调递增的双端队列，队列中存放的是元素的值和下标。-

- 每次遍历到一个新元素时，将队列头中小于当前元素的元素弹出，将当前元素放入队列头
- 同时，弹出队列尾不在窗口内的元素
- 最后将窗口内最大值放入结果数组即可



```cc
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
```

**时间复杂度为**O(n)

