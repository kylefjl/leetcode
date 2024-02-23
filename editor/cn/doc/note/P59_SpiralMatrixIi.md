#  螺旋矩阵 II

注意[) 左闭右开， 分割好区域

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;//定义边界 (每此循环一层)
        int num = 1;
        while (left<right&&top<bottom)//当左边界小于右边界并且上边界小于下边界时
        {
            int i=top,j=left;
            for(j=left;j<right;++j)res[i][j]=num++;//从左到右 [) 左闭右开
            for(i=top;i<bottom;++i)res[i][j]=num++;//从上到下
            for(j=right;j>left;--j)res[i][j]=num++;//从右到左
            for(i=bottom;i>top;--i)res[i][j]=num++;//从下到上
            left++;// 左边界+1
            right--;
            top++;
            bottom--;
        }
        if (left==right&&top==bottom)//当左边界等于右边界并且上边界等于下边界时 说明是奇数 且是最后一个 只有一个元素
        {
            res[left][top]=num;
        }
        return res;
    }
};
```

