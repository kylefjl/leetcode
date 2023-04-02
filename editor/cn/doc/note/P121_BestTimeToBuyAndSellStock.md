# 买卖股票的最佳时机

贪心算法

计算i到j天的利润（j>i），找到最大的一个

```cc
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;//
        int temp_profit=0;//假设当天卖出的利润
        const auto size=prices.size();
        for (int i = 1; i < size; ++i)
        {
            temp_profit+=(prices[i]-prices[i-1]);//累加差价
            if(max_profit<temp_profit)max_profit= temp_profit;//更新最大利润
            else if(temp_profit<=0) temp_profit=0;//如果当天卖出的利润为负，则交易行为不成立，取消买入和卖出
        }
        return max_profit;
    }
};
```

