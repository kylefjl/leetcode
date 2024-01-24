# 二分查找



```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
		        return search_Iteration(nums.begin(),nums.end(),target);
    }
    //二分查找 重载 递归写法
    int search(vector<int>::iterator begin,vector<int>::iterator end,int target){
        auto size=end-begin;
        if(size==0)return -1;//如果没有元素，说明target不存在，返回-1
        int tar_mid= floor(size/2);//二分 floor 向下取整
        if(target==*(begin+tar_mid)){ //如果中间元素等于target，返回中间元素的下标
            return tar_mid;
        }else if(target>*(begin+tar_mid)){
           int  index=search(begin+tar_mid+1,end,target);//如果target大于中间元素，则在右边查找
            return index==-1?-1:(tar_mid+1)+index;//如果右边查找的下标为-1，则说明右边没有找到，返回-1，否则返回右边查找的下标+中间元素的下标+1
        }else{
            return search(begin,begin+tar_mid,target);//如果target小于中间元素，则在左边查找
        }
    }
    //二分查找 重载 迭代写法
    int search_Iteration(vector<int>::iterator begin,vector<int>::iterator end,int target){
        auto size=end-begin;
        int left=0,right=size-1;
        int mid=0;
        while(left<=right)
        {
             mid=left+ std::ceil((right-left)/2.0);//向上取整
            if(*(begin+mid)==target)return mid;//如果中间元素等于target，返回中间元素的下标
            else if(*(begin+mid)>target)right=mid-1;//如果中间元素大于target，则在左边查找
            else left=mid+1;//如果中间元素小于target，则在右边查找
        }
        return -1;//如果没有找到，返回-1
    }
};
```







迭代（Iteration）和递归（Recursion）都是计算机科学中用于解决问题的两种不同的方法。

1. **迭代：**
   - **循环结构：** 迭代是通过循环结构来重复执行一段代码，直到满足某个条件为止。
   - **控制结构：** 使用迭代语句（如for循环或while循环）来反复执行相同的代码块，直到达到预定的条件。
   - **效率：** 通常来说，迭代在处理一些简单的问题上可能更为高效，因为它直接控制了程序的流程。
2. **递归：**
   - **函数调用自身：** 递归是通过函数调用自身来解决问题的方法。
   - **基本情况：** 递归函数需要有一个或多个基本情况，以避免无限递归。
   - **控制结构：** 递归通过不断地将问题分解为更小的子问题来解决整个问题。
   - **可读性：** 有时递归可以使代码更为简洁和易读，特别是对于一些问题的自然表达。

比较迭代和递归的选择通常取决于具体的问题和编程环境。在某些情况下，递归可以提供更清晰和简洁的解决方案，而在其他情况下，迭代可能更为实用和高效。