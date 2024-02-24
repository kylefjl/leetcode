//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [], val = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [7,7,7,7], val = 7
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 列表中的节点数目在范围 [0, 10⁴] 内 
// 1 <= Node.val <= 50 
// 0 <= val <= 50 
// 
//
// Related Topics 递归 链表 👍 1387 👎 0

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}//explicit 防止隐式转换
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
* 移除链表元素
* @author fjl
* @date 2024-02-24 15:42:43
*/
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public://哨兵节点 遍历链表 删除节点 时间复杂度O(n) 空间复杂度O(1) 迭代
    ListNode* removeElements(ListNode* head, int val) {
        ListNode head_node(-1, head);//哨兵节点
        ListNode* node_it=&head_node;//指向当前节点
        while(node_it->next!= nullptr)//遍历链表
        {
            if(node_it->next->val==val)//如果当前节点的下一个节点的值等于val
                node_it->next=node_it->next->next;//删除当前节点的下一个节点
            else node_it=node_it->next;//否则继续遍历，指向下一个节点
        }
        return head_node.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    auto* head2 = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    ListNode* result = s.removeElements(head2, 7);
    while(result!= nullptr)
    {
        cout << result->val << " ";
        result=result->next;
    }


}