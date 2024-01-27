# 长度最小的子数组

## 前缀和

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //前缀和
        const int size = nums.size();
        vector<int> sums(size+1,0);
        for (int i = 1; i <= size; ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        int ans = size;
        int length=ans;
        bool length_update=false;
        if (sums[size]< target) return 0;//如果所有元素的和都小于target，直接返回0
        for (int i = 0; i < size; ++i)
        {
            while(length>=0) //找到一个length，使得i+length满足条件且length最小
            {
                if (i+length>size)length=size-i;//如果i+length>size，说明后面的元素不够了，直接取到最后一个元素
                if(sums[length+i]-sums[i]>=target)//如果此时的长度满足条件，就减少长度，继续判断，直到不满足条件
                {
                    length_update=true;//记录是否减过长度
                    length--;
                }
                else break;//如果已经不满足条件，就跳出循环
            }
            if(length_update)ans=(length+1);//如果length_update为true，说明减过长度，就更新ans为length+1，因为length此时已经比刚好满足条件的长度少1
            length=ans;//将length重置为ans
            length_update=false;//将length_update重置为false
        }
        return ans;
    }
};
