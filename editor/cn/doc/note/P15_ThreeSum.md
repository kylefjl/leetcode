# 三数之和

## 排序加双指针

- 要点：去重，可以利用排序之后特性，保证首先固定的a只出现一次（假设a+b+c=0）,然后在**大于等于**a范围里（如果a有重复值的话）里寻找另外的两个数，同样，也保证b在a已经固定的情况下只出现一次，这样就可以避免重复解
- 优化：应为a是从排好序的数字里面依次选择的，所以可以推断出需要求解的b+a是依次变大的，可以利用上一次的结果对下一次查找的范围进行限定，具体可以看代码里面的`end_idx`的选择

```cc
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& sort_nums)
    {
        std::sort(sort_nums.begin(),sort_nums.end());//先排序
        std::vector<vector<int>> result;//存储结果
        auto end_idx=sort_nums.end()-1;
        int last_num;
        for (auto it=sort_nums.begin();it!=sort_nums.end();)
        {
            //从小到大选择一个数作为第一个，调用twoSum求剩下的两个数
            auto pair= twoSum(sort_nums,0-*it,it+1,end_idx);
            if(!pair.empty())//如果有数据说明有三数之和为0
            {
                for(auto item: pair)
                {
                    vector<int> temp{*it,item[0],item[1]};//
                    result.push_back(temp);//存储结果
                }
            }
            if(*it>=0)break;//因为不可能3个数都大于0，所以it大于等于0证明已遍历所有可能
            last_num=*it;//存储当前的数字
            while(it!=sort_nums.end()&&*it==last_num)it++;//向右移动直到找到下一个不同的数字
        }
        return result;
    }
//在sort_nums中查找两数之和等于target，begin_idx、end_idx指定了范围
    vector<vector<int>> twoSum(const vector<int>& sort_nums, int target,const vector<int>::iterator& begin_idx,vector<int>::iterator& end_idx)
    {
        vector<vector<int>> result;
        auto left_it=begin_idx;
        auto right_it=end_idx;
        int count=0,last_right_num,last_left_num;
        for(;left_it<right_it;)//访问完毕退出
        {//左右两个迭代器向中间靠近
            if(target<2*(*left_it)||target>2*(*right_it))break;//不可能存在两数之和等于target
            if(*left_it+*right_it>target)
            {
                last_right_num=*right_it;
                //如果相加大于目标，为了变小，只能右边数字再小一些
                while(*right_it==last_right_num&&left_it!=right_it)
                    right_it--;
            }
            else if (*left_it+*right_it<target)
            {   //如果相加小于目标，为了变大，只能左边数字再大一些
                last_left_num=*left_it;
                while(*left_it==last_left_num&&left_it!=right_it)
                    left_it++;
                //如果第一次移动左迭代器，说明对于当前的target来说right_it已经够大了，
                // 又因为以及排了序，所以下一个target肯定大于当前的
                // 所以，可以把当前的right_it作为下一个target查询时的end_idx
                if(count==0)
                {
                    end_idx=right_it;
                    count=1;
                }
            }
            else if (*left_it+*right_it==target)
            {
                vector<int> temp={*left_it,*right_it};
                result.push_back(temp);//找到结果则添加到序列里，然后接着查找
                last_right_num=*right_it,last_left_num=*left_it;
                //左右同时移动直到找到下一个不同的数字
                while(*right_it==last_right_num&&left_it!=right_it)
                    right_it--;
                while(*left_it==last_left_num&&left_it!=right_it)
                    left_it++;
                //同上
                if(count==0)
                {
                    end_idx=right_it;
                    count=1;
                }
            }
        }
        return result;
    }
};
```

	执行耗时:88 ms,击败了40.60% 的C++用户
	内存消耗:35.1 MB,击败了6.66% 的C++用户

