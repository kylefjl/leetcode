//给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。 
//
//
// 
//
// 
// 
// 示例 1： 
// 
// 
//
// 
//输入：n = 2
//输出：[0,1,1]
//解释：
//0 --> 0
//1 --> 1
//2 --> 10
// 
//
// 示例 2： 
//
// 
//输入：n = 5
//输出：[0,1,1,2,1,2]
//解释：
//0 --> 0
//1 --> 1
//2 --> 10
//3 --> 11
//4 --> 100
//5 --> 101
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 10⁵ 
// 
//
// 
//
// 进阶： 
//
// 
// 很容易就能实现时间复杂度为 O(n log n) 的解决方案，你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？ 
// 你能不使用任何内置函数解决此问题吗？（如，C++ 中的 __builtin_popcount ） 
// 
//
// Related Topics 位运算 动态规划 👍 1150 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 比特位计数
* @author fjl
* @date 2023-02-06 17:36:24
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>  result(n+1) ;
        for(int i = 0; i <=n; ++i){
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
//    vector<int> countBits(int n) {
//        vector<int>  result(n+1) ;
//        for(int i = 0; i <=n; ++i){
//            result[i] = count(i);
//        }
//        return result;
//    }
//    inline int count (int  x){
//        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
//        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
//        x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
//        x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
//        x = (x & 0x0000FFFF) + ((x >>16) & 0x0000FFFF);
//        return x;
//    }
};

//leetcode submit region end(Prohibit modification and deletion)

vector<int> fun()
{
    vector<int> vec(1000000,0);
    return std::move(vec) ;
}
int main()
{
   Solution s;
   s.countBits(5);
}