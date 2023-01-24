<p>给你一个 <strong>有向无环图</strong>&nbsp;， <code>n</code>&nbsp;个节点编号为 <code>0</code>&nbsp;到 <code>n-1</code>&nbsp;，以及一个边数组 <code>edges</code>&nbsp;，其中 <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;表示一条从点&nbsp;&nbsp;<code>from<sub>i</sub></code>&nbsp;到点&nbsp;<code>to<sub>i</sub></code>&nbsp;的有向边。</p>

<p>找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。</p>

<p>你可以以任意顺序返回这些节点编号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/5480e1.png" style="height: 181px; width: 231px;" /></p>

<pre><strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
<strong>输出：</strong>[0,3]
<strong>解释：</strong>从单个节点出发无法到达所有节点。从 0 出发我们可以到达 [0,1,2,5] 。从 3 出发我们可以到达 [3,4,2,5] 。所以我们输出 [0,3] 。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/5480e2.png" style="height: 201px; width: 201px;" /></p>

<pre><strong>输入：</strong>n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
<strong>输出：</strong>[0,2,3]
<strong>解释：</strong>注意到节点 0，3 和 2 无法从其他节点到达，所以我们必须将它们包含在结果点集中，这些点都能到达节点 1 和 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>2 &lt;= n &lt;= 10^5</code></li> 
 <li><code>1 &lt;= edges.length &lt;= min(10^5, n * (n - 1) / 2)</code></li> 
 <li><code>edges[i].length == 2</code></li> 
 <li><code>0 &lt;= from<sub>i,</sub>&nbsp;to<sub>i</sub> &lt; n</code></li> 
 <li>所有点对&nbsp;<code>(from<sub>i</sub>, to<sub>i</sub>)</code>&nbsp;互不相同。</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>图</details><br>

<div>👍 60, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://mp.weixin.qq.com/s/NF8mmVyXVfC1ehdMOsO7Cw' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：[数据结构精品课](https://aep.h5.xeknow.com/s/1XJHEO) 已更新到 V2.1，[手把手刷二叉树系列课程](https://mp.weixin.qq.com/s/eUG2OOzY3k_ZTz-CFvtv5Q) 上线，第 16 期刷题打卡 [开始报名](https://aep.xet.tech/s/46nofd)。**

</div>



