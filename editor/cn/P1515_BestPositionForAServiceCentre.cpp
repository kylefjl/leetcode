//一家快递公司希望在新城市建立新的服务中心。公司统计了该城市所有客户在二维地图上的坐标，并希望能够以此为依据为新的服务中心选址：使服务中心 到所有客户的欧几里
//得距离的总和最小 。 
//
// 给你一个数组 positions ，其中 positions[i] = [xi, yi] 表示第 i 个客户在二维地图上的位置，返回到所有客户的 欧几里得
//距离的最小总和 。 
//
// 换句话说，请你为服务中心选址，该位置的坐标 [xcentre, ycentre] 需要使下面的公式取到最小值： 
//
// 
//
// 与真实值误差在 10⁻⁵之内的答案将被视作正确答案。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：positions = [[0,1],[1,0],[1,2],[2,1]]
//输出：4.00000
//解释：如图所示，你可以选 [xcentre, ycentre] = [1, 1] 作为新中心的位置，这样一来到每个客户的距离就都是 1，所有距离之和为 4 
//，这也是可以找到的最小值。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：positions = [[1,1],[3,3]]
//输出：2.82843
//解释：欧几里得距离可能的最小总和为 sqrt(2) + sqrt(2) = 2.82843
// 
//
// 
//
// 提示： 
//
// 
// 1 <= positions.length <= 50 
// positions[i].length == 2 
// 0 <= xi, yi <= 100 
// 
//
// Related Topics 几何 数学 随机化 👍 58 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 服务中心的最佳位置
* @author name
* @date 2023-05-09 16:54:57
*/
//leetcode submit region begin(Prohibit modification and deletion)
#define DIS(x,y,x0,y0) sqrt(pow(x-x0,2)+pow(y-y0,2))
class Solution {
public:
    // 获得到postions中所有点的距离和最小的点 采用梯度下降法
    double getMinDistSum(vector<vector<int>>& positions) {
        double x=0,y=0;//x,y为中心点的坐标
        double alpha=1;//学习率
        double decay=1e-3;//衰减系数
        for (auto &position:positions) {//初始化中心点（x，y的平均值）
            x+=position[0];
            y+=position[1];
        }
        x=x/positions.size();//求平均值
        y=y/positions.size();//求平均值
        auto getDist =[&](double x, double y) {//求到所有点的距离和
            double dis = 0;
            for (auto &position:positions) {
                dis += sqrt(pow(position[0] - x, 2) + pow(position[1] - y, 2));//求距离
            }
            return dis;
        };
        while (true)
        {
            double dx=0,dy=0;
            for (auto &position:positions) {//求梯度
                dx+=(x-position[0])/(DIS(x,y,position[0],position[1])+1e-7);//加1e-7  防止除0
                dy+=(y-position[1])/(DIS(x,y,position[0],position[1])+1e-7);
            }
            dx=alpha*dx;//乘以学习率
            dy=alpha*dy;//乘以学习率
            x-=dx;//更新中心点
            y-=dy;
            alpha*=(1-decay);//学习率衰减
            if(DIS(dx,dy,0,0)<1e-6)//当梯度足够小的时候，认为找到最优值，退出循环
                break;
        }
        return getDist(x,y);//返回最到所有点的距离和的最小值
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   //[44,23],[18,45],[6,73],[0,76],[10,50],[30,7],[92,59],[44,59],[79,45],[69,37],[66,63],[10,78],[88,80],[44,87]
   vector<vector<int>> positions={{44,23},{18,45},{6,73},{0,76},{10,50},{30,7},{92,59},{44,59},{79,45},{69,37},{66,63},{10,78},{88,80},{44,87}};
   s.getMinDistSum(positions);

}