<p>给你二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>层序遍历</strong> 。 （即逐层地，从左到右访问所有节点）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" /> 
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[3],[9,20],[15,7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[[1]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li>树中节点数目在范围 <code>[0, 2000]</code> 内</li> 
 <li><code>-1000 &lt;= Node.val &lt;= 1000</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 广度优先搜索 | 二叉树</details><br>

<div>👍 1550, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://mp.weixin.qq.com/s/NF8mmVyXVfC1ehdMOsO7Cw' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：[数据结构精品课](https://aep.h5.xeknow.com/s/1XJHEO) 已更新到 V2.1，[手把手刷二叉树系列课程](https://aep.xet.tech/s/3YGcq3) 上线。**

<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

前文 [BFS 算法框架](https://labuladong.github.io/article/fname.html?fname=BFS框架) 就是由二叉树的层序遍历演变出来的。

下面是层序遍历的一般写法，通过一个 while 循环控制从上向下一层层遍历，for 循环控制每一层从左向右遍历：

![](https://labuladong.gitee.io/pictures/dijkstra/1.jpeg)

**标签：[BFS 算法](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2122002916411604996)，[二叉树](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=2121994699837177859)**

## 解法代码

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) {
            return res;
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        // while 循环控制从上向下一层层遍历
        while (!q.isEmpty()) {
            int sz = q.size();
            // 记录这一层的节点值
            List<Integer> level = new LinkedList<>();
            // for 循环控制每一层从左向右遍历
            for (int i = 0; i < sz; i++) {
                TreeNode cur = q.poll();
                level.add(cur.val);
                if (cur.left != null)
                    q.offer(cur.left);
                if (cur.right != null)
                    q.offer(cur.right);
            }
            res.add(level);
        }
        return res;
    }
}
```

**类似题目**：
  - [103. 二叉树的锯齿形层序遍历 🟠](/problems/binary-tree-zigzag-level-order-traversal)
  - [107. 二叉树的层序遍历 II 🟠](/problems/binary-tree-level-order-traversal-ii)
  - [1161. 最大层内元素和 🟠](/problems/maximum-level-sum-of-a-binary-tree)
  - [1302. 层数最深叶子节点的和 🟠](/problems/deepest-leaves-sum)
  - [1609. 奇偶树 🟠](/problems/even-odd-tree)
  - [637. 二叉树的层平均值 🟢](/problems/average-of-levels-in-binary-tree)
  - [919. 完全二叉树插入器 🟠](/problems/complete-binary-tree-inserter)
  - [958. 二叉树的完全性检验 🟠](/problems/check-completeness-of-a-binary-tree)
  - [剑指 Offer 32 - I. 从上到下打印二叉树 🟠](/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof)
  - [剑指 Offer 32 - II. 从上到下打印二叉树 II 🟢](/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof)
  - [剑指 Offer 32 - III. 从上到下打印二叉树 III 🟠](/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof)

</details>
</div>





