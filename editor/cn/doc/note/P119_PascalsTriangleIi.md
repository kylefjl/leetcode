杨辉三角 II

迭代

```cc
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        int level = 1;//此时的rowIndex是从第0层开始算的，所以统一从0开始
        vector<vector<int>> result;
        vector<int> lastLevel = {1};//添加第0层 {1}
        while (level <=rowIndex)
        {
            auto temp = lastLevel;
            for (int i = 1; i < lastLevel.size(); ++i)
            {
                lastLevel[i] += temp[i - 1];//错位相加
            }
            lastLevel.push_back(1);//手动添加每层最后的1
            level++;
        }
        return lastLevel;
    }
};
```

