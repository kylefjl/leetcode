//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
//
// Related Topics递归 | 链表 
//
// 👍 1674, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

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
* 两两交换链表中的节点
* @author name
* @date 2023-01-14 23:39:19
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
    ListNode* swapPairs(ListNode* head) {
        auto*  head_pre=new ListNode{0,head};
        auto temp=head_pre;
        int size=0;
        while (temp->next!= nullptr)
        {
            temp=temp->next;
            size++;
        }
        ListNode* temp1,*temp2;
        swaptwoPairs_iter(head_pre,size, temp1,temp2);
        auto result=head_pre->next;
        delete head_pre;
        return result;
    }
     void swaptwoPairs_iter(ListNode*&  head,int size,ListNode*& temp1,ListNode*&temp2) {

        if(size>=4)
        {
            temp1=head->next;//1
            head->next=temp1->next;//2
            temp1->next=head->next->next->next;//3
            temp2=head->next->next;//4
            head->next->next=temp1;//5
            temp2->next=temp1->next->next;//6
            temp1->next->next=temp2;//7

            size-=4;
            swaptwoPairs_iter(head->next->next->next->next,size,temp1,temp2);
        }
        else
        {
            swapPairs_iter(head,size);
        }
    }
    void swapPairs_iter(ListNode*&  head,int size) {
        ListNode* temp;
        if(size>=2)
        {
            temp=head->next;
            head->next=temp->next;
            temp->next=head->next->next;
            head->next->next=temp;
            size-=2;
            swapPairs_iter(head->next->next,size);
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
   Solution s;

    ListNode l1_node[4],l2_node[3];
    ListNode * result;
    l1_node[0].val=2;l1_node[0].next=&l1_node[1];
    l1_node[1].val=4;l1_node[1].next=&l1_node[2];
    l1_node[2].val=6;l1_node[2].next=&l1_node[3];
    l1_node[3].val=5;l1_node[3].next= nullptr;
    result=s.swapPairs(l1_node);
    while(result!= nullptr)
    {
        cout<<result->val<<" ";
        result=result->next;

    }
}