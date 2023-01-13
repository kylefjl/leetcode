# 笔记

## 1. 排序

思路：先排序，再利用左右迭代器查找合适的一组数，因为已经排了序，所有可以根据大小关系控制迭代器的移动

```cc
 vector<int> twoSum(vector<int>& nums, int target) {
          vector<int> sort_nums=nums;//保存原始数据
          std::sort(sort_nums.begin(),sort_nums.end());//先排序
          vector<int> result;
          auto left_it=sort_nums.begin();
          auto right_it=sort_nums.end()-1;//尾迭代器-1，指向有效数据
          for(;left_it!=right_it;)//左右两边相等则访问完毕退出
          {//左右两个迭代器向中间靠近
              if(*left_it+*right_it>target)right_it--;//如果相加大于目标，为了变小，只能右边数字再小一些
              else if (*left_it+*right_it<target)left_it++;//如果相加小于目标，为了变大，只能左边数字再大一些
              else if (*left_it+*right_it==target)break;//相等退出
          }
          for(int i=0;i<nums.size();i++)
          {
              //在原始数据中查找数原本的位置记录在result
              if(nums[i]==*left_it||nums[i]==*right_it)result.push_back(i);
          }
          return result;
      }
```

执行耗时:8 ms,击败了91.36% 的C++用户
内存消耗:10.2 MB,击败了53.73% 的C++用户

# 2. 哈希

如果把vector里的int作为哈希表的key，会出现key重复的情况，所以此处采用允许key重复的hashtable，cppreference查找unordered_multimap即可，当然，也可以和官方解答一样在插入前判断是否重复；

```cc
vector<int> twoSum(vector<int> &nums, int target) {
        unordered_multimap<int, int> hash_map;//允许重复的hashtable
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {//插入
            hash_map.emplace(std::make_pair(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            auto position = hash_map.find(target - nums[i]);
            if (position != hash_map.end() && position->second != i) {//如果有target - nums[i]对应的数且不是自身
                if (hash_map.count(position->first) == 1) {//如果对应键只有一个数的话，直接返回
                    return {position->second, i};
                }
                else //对应键有多个数
                {
                    auto range = hash_map.equal_range(target - nums[i]);//get数的首位迭代器
                    for (auto i = range.first; i != range.second; ++i)
                    {
                        result.push_back(i->second);
                    }
                    return result;
                }
            }
        }
        return {};
    }
```

执行耗时:12 ms,击败了68.78% 的C++用户
内存消耗:11.7 MB,击败了6.10% 的C++用户
