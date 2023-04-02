# 杨辉三角

迭代

```cc
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int level=2;//第一层不用算，直接开始第二层
        vector<vector<int>> result;
        result.push_back({1});//添加第一层 {1}
        while (level<=numRows)
        {
            auto temp=result.back();
            for(int i=1;i<temp.size();++i)
            {
                temp[i]+=result.back()[i-1];//错位相加
            }
            temp.push_back(1);//手动添加每层最后的1
            result.push_back(std::move(temp));
            level++;
        }
        return result;
    }
};
```

