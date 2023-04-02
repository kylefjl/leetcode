# 颜色分类

计数排序

```cc
void sortColors(vector<int>& nums) {
        int count[3]={0,0,0};//存储各个颜色的个数
        for (int i = 0; i < nums.size(); ++i)
        {
            ++count[nums[i]];
        }
        //按照颜色数量重写nums。
        for (int i = 0; i < count[0]; ++i)nums[i]=0;
        for (int i = 0; i < count[1]; ++i)nums[i+count[0]]=1;
        for (int i = 0; i < count[2]; ++i)nums[i+count[0]+count[1]]=2;
    }
```

