# 有效的字母异位词

```cc

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length())return false;
        int str_count[26];//数组 哈希
        for(auto & ch:s)//遍历字符串
        {
            ++str_count[ch-'a'];//统计每个字符出现的次数
        }
        for(auto & ch:t)
        {
            --str_count[ch-'a'];//减去t中每个字符出现的次数
        }
        for(int i : str_count)//如果计数表中有不为0 返回false
        {
            if(i!=0)return false;
        }
        return true;

    }
};
```

