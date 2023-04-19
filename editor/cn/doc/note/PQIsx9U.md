# 滑动窗口的平均值

维护一个窗口数之和，窗口满了之后每加一个数，都减去最早的数

```cc
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):window_size(size),window_sum(0),nums(size),nums_size(0)
    {
    }
    double next(int val) {
        window_sum += val;//加入新的值
        if(window_size==nums_size)//满了
        {
            window_sum-= nums[left_idx];//减去最早的值
            nums[left_idx]=val;//记录新的值
            left_idx=(left_idx+1)%window_size;//更新最早的值的位置
        }
        else
        {
            nums[nums_size]=val;//记录新的值
            ++nums_size;//更新记录的值的个数

        }

        return static_cast<double>(window_sum)/static_cast<double>(nums_size);//返回平均值
    }
    const  int window_size;//窗口大小
    int nums_size;//记录的值的个数
    vector<int> nums;//记录的值
    int left_idx=0;//最早的值的位置
    long long int window_sum=0;//窗口的和
};
```

