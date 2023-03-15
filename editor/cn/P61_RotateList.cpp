//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 
//
// 
//
// 示例 1：
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
// 
//
// 示例 2： 
// 
// 
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 500] 内 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 10⁹ 
// 
//
// Related Topics 链表 双指针 👍 902 👎 0

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
* 旋转链表
* @author name
* @date 2023-03-14 10:28:55
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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0|| head== nullptr)return head;
        ListNode* i_head= head,*new_head= nullptr;
        ListNode* End_head= head;
        int size=1;
        while(End_head->next!= nullptr)//计算size
        {
            End_head=End_head->next;
            ++size;
        }
        int i=size-k%(size);//求第i个节点需要断开
        while(i>1)
        {
            i_head=i_head->next;
            --i;
        }
        if(i_head==End_head)return head;//如果需要断开的和最后一个相同，则直接返回head；
        new_head=i_head->next;//新head 指向i_head的下一个（第二段的头一个）;
        i_head->next= nullptr;//i_head标记成尾节点
        End_head->next=head;//第一段接到第二段的末尾

        return new_head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    ListNode l1_node[5],l2_node[1];
    ListNode * result;
//    l1_node[0].val=1;l1_node[0].next=&l1_node[1];
//    l1_node[1].val=2;l1_node[1].next=&l1_node[2];
//    l1_node[2].val=3;l1_node[2].next=&l1_node[3];
//    l1_node[3].val=4;l1_node[3].next=&l1_node[4];
//    l1_node[4].val=5;l1_node[4].next= nullptr;
    l2_node[0].val=5;l2_node[0].next= nullptr;

    result=s.rotateRight(l2_node,1);
    while(result!= nullptr)
    {
        cout<<result->val<<" ";
        result=result->next;

    }
}