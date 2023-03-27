//给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。 
//
// 
//
// 示例 1： 
// 
// 
//输入：points = [[1,1],[2,2],[3,3]]
//输出：3
// 
//
// 示例 2： 
// 
// 
//输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出：4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 300 
// points[i].length == 2 
// -10⁴ <= xi, yi <= 10⁴ 
// points 中的所有点 互不相同 
// 
//
// Related Topics 几何 数组 哈希表 数学 👍 484 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 直线上最多的点数
* @author name
* @date 2023-03-22 14:06:38
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size(), result = 1;
        for (int i = 0; i < size - 1; ++i) {
            vector<double> ratio;//斜率
            for (int j = i + 1; j < size; ++j) {
                if (points[i][0] == points[j][0]) {
                    ratio.emplace_back(INT_MAX);//两点的x相当，确定的直线垂直，斜率为无穷大
                } else {//两点确定斜率
                    ratio.emplace_back((double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
                }
            }
            sort(ratio.begin(), ratio.end());//排序，方便对相同的斜率进行计数
            for (int j = 0; j < ratio.size(); ) {
                int index = j+1;
                while (index < ratio.size() && ratio[index] - ratio[j] < 2e-6) {
                    ++index;//如果在浮点型的误差范围之内，认为是同一斜率
                }
                result = max(result, index - j + 1);//计算最大的个数
                j=index;
            }
        }
        return result;
    }
};
//class Solution {
//public:
//    //求公约数  辗转相除法
//    int gcd(int a, int b) {
//        return b ? gcd(b, a % b) : a;
//    }
//
//    int maxPoints(vector<vector<int>>& points) {
//        const int n = points.size();
//        if (n <= 2) return n;
//        int ret = 0;
//        for (int i = 0; i < n; ++i) {
//            if (ret >= n - i || ret > n / 2) {
//                break;//剪枝 剩余的直线个数已经不可能超过现在的最大值
//            }
//            unordered_map<int, int> mp;//哈希
//            for (int j = i + 1; j < n; ++j) {
//                //用(x y)代表斜率y/x，为保证同一斜率对应唯一的(x,y),需要对
//                //(x,y)进行约分且保证y为正值
//                int x = points[i][0] - points[j][0];
//                int y = points[i][1] - points[j][1];
//                if (x == 0) {
//                    y = 1;
//                } else if (y == 0) {
//                    x = 1;
//                } else {
//                    if (y < 0) {
//                        x = -x;
//                        y = -y;
//                    }
//                    int gcdXY = gcd(abs(x), abs(y));
//                    x /= gcdXY, y /= gcdXY;
//                }
//                mp[y + x * 20001]++;//保证y+x*20001作为key不会冲突
//            }
//            int maxn = 0;
//            for (auto& [_, num] : mp) {
//                maxn = max(maxn, num + 1);
//            }
//            ret = max(ret, maxn);
//        }
//        return ret;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<vector<int>> input={{9,-25},{-4,1},{-1,5},{-7,7}};
   cout<< s.maxPoints(input);
}