//给定一个数组 trees，其中 trees[i] = [xi, yi] 表示树在花园中的位置。 
//
// 你被要求用最短长度的绳子把整个花园围起来，因为绳子很贵。只有把 所有的树都围起来，花园才围得很好。 
//
// 返回恰好位于围栏周边的树木的坐标。 
//
// 示例 1: 
//
// 
//
// 
//输入: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//输出: [[1,1],[2,0],[3,3],[2,4],[4,2]] 
//
// 示例 2: 
//
// 
//
// 
//输入: points = [[1,2],[2,2],[4,2]]
//输出: [[4,2],[2,2],[1,2]] 
//
// 
//
// 注意: 
//
// 
// 1 <= points.length <= 3000 
// points[i].length == 2 
// 0 <= xi, yi <= 100 
// 所有给定的点都是 唯一 的。 
// 
//
// Related Topics 几何 数组 数学 👍 214 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 安装栅栏
* @author fjl
* @date 2023-05-24 15:58:03
*/
//leetcode submit region begin(Prohibit modification and deletion)
//jarvis
class Solution {
public:
    /*
     * 求叉积
     * @param a
     * @param b
     * @param res
     * @return int
     *cross(a,b,r) =ab*br=(bx-ax)*(ry-by)-(by-ay)*(rx-bx)
     * */
    double cross(const  vector<int> &a, const vector<int> &b, const vector<int> &res)
    {
        return (b[0] - a[0]) * (res[1] - b[1]) - (b[1] - a[1]) * (res[0] - b[0]);
    }
    //求距离 两点之间的距离 用于排序 二范数
    int distance(const vector<int> & p, const vector<int> & q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        int bottom = 0;
        /* 找到 y 最小的点 bottom*/
        for (int i = 0; i < n; i++) {
            if (trees[i][1] < trees[bottom][1]) {
                bottom = i;
            }
        }
        swap(trees[bottom], trees[0]);
        /* 以 bottom 原点，按照极坐标的角度大小进行排序 */
        sort(trees.begin() + 1, trees.end(), [&](const vector<int> & a, const vector<int> & b) {
            int diff = cross(trees[0], a, b);
            if (diff == 0) {
                return distance(trees[0], a) < distance(trees[0], b);
            } else {
                return diff > 0;
            }
        });
        /* 对于凸包最后且在同一条直线的元素按照距离从大到小进行排序 */
        int r = n - 1;
        while (r >= 0 && cross(trees[0], trees[n - 1], trees[r]) == 0) {//最后一个点和第一个点在一条直线上
            r--;
        }
        for (int l = r + 1, h = n - 1; l < h; l++, h--) {
            swap(trees[l], trees[h]);
        }
        stack<int> st;//单调栈
        st.emplace(0);
        st.emplace(1);
        for (int i = 2; i < n; i++) {
            int top = st.top();
            st.pop();
            /* 如果当前元素与栈顶的两个元素构成的向量顺时针旋转，则弹出栈顶元素 */
            while (!st.empty() && cross(trees[st.top()], trees[top], trees[i]) < 0) {
                top = st.top();
                st.pop();
            }
            st.emplace(top);
            st.emplace(i);
        }


        return res;
    }
    /*
     * */
//    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//        const int n = trees.size();
//        if (n < 4) {//小于3个点，直接返回
//            return trees;
//        }
//        int leftMost=0;//最左边的点
//        for (int i = 0; i < n; ++i)
//        {
//            //找到最左边的点   x坐标最小的点 或者 x坐标相同 y坐标最小的点 作为起点
//            if (trees[i][0] < trees[leftMost][0]|| (trees[i][0] == trees[leftMost][0] && trees[i][1] < trees[leftMost][1]))
//            {
//                leftMost = i;
//            }
//        }
//        vector<vector<int>> res={trees[leftMost]};//起点
//        vector<bool> visited(n, false);//标记是否访问过
//        int p = leftMost,q=(p+1)%n;// p为起点，q为下一个点
//        do{
//            visited[p]= true;//标记为访问过
//            q=(p+1)%n;//
//            for (int j = 0; j < n; ++j)//找到下一个点 q 点 使得其余的点均在向量 $\vec{pq}$ 的左边
//            {
//                if (cross(trees[p], trees[q], trees[j]) < 0)
//                {
//                    q=j;//j在向量pq的右边，即q在向量pj的左边，更新q 为j
//                }
//            }
//            for (int i = 0; i < n; ++i)//找到所有在向量 $\vec{pq}$ 的延长线上的点，加入结果集
//            {
//                if (visited[i]||i==q) continue;//已经访问过的点 或者 q点 跳过
//                if (cross(trees[p], trees[q], trees[i]) == 0)
//                {
//                    visited[i]=true;//在向量pq的延长线上的点，标记为访问过
//                    res.push_back(trees[i]);//加入结果集
//                }
//            }
//            if  (!visited[q])//q点没有访问过，加入结果集
//            {
//                res.emplace_back(trees[q]);
//                visited[q] = true;
//            }
//            p=q;//更新p为q 继续迭代
//        }
//        while (p != leftMost);//当p回到起点时，结束迭代
//        return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   //points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
    vector<vector<int>> points={{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
   auto  res=s.outerTrees(points);
    for (int i = 0; i < res.size(); ++i)
    {
         cout<<res[i][0]<<","<<res[i][1]<<endl;
    }
}