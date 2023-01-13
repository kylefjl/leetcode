
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
//
// Related Topics 递归 链表 数学 👍 9073 👎 0


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
 * 两数相加
 * @author fjl
 * @date 2023-01-12 21:05:36
 */
//leetcode submit region begin(Prohibit modification and deletion)
// Definition for singly-linked list.
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* temp=new ListNode{0, nullptr};//创建空间并用temp指针记录
        auto* result=temp;//存储头节点
        while(true)
        {
            int num=l1->val+l2->val+temp->val;//存储一下加起来的数字，然后在下面分别计算进位和当前位
            temp->val=num%10;//当前位
            if(l1->next== nullptr&&l2->next== nullptr&&((num)/10==0))
            {//如果l1 l2 都没有下一个节点了，且不需要进位，则认为计算完毕，退出
                temp->next= nullptr;//标记尾节点
                break;
            }
            temp->next=new ListNode{0, nullptr};//开辟下一个节点
            temp->next->val=(num)/10;//计算进位
            temp=temp->next;//指向下一个

            //如果有下一位则链接到下一个，如果没有则把数字置0，不影响进位的计算
            if(l1->next!= nullptr)l1=l1->next;
            else l1->val=0;
            if(l2->next!= nullptr)l2=l2->next;
            else l2->val=0;
        }
        return result;//返回头节点
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    ListNode l1_node[4],l2_node[3];//输入 l1 [2 4 4 3] l2 [5 6 4]
    ListNode * result;
    l1_node[0].val=2;l1_node[0].next=&l1_node[1];
    l1_node[1].val=4;l1_node[1].next=&l1_node[2];
    l1_node[2].val=4;l1_node[2].next=&l1_node[3];
    l1_node[3].val=3;l1_node[3].next= nullptr;
    l2_node[0].val=5;l2_node[0].next=&l2_node[1];
    l2_node[1].val=6;l2_node[1].next=&l2_node[2];
    l2_node[2].val=4;l2_node[2].next= nullptr;
    result=s.addTwoNumbers(l1_node,l2_node);
    ListNode* temp=result;
//    int count=0;
    for(;result!= nullptr;)//输出 [7 0 9 3]
    {
        cout<<result->val<<" ";
        temp= result;
        result=result->next;
        delete temp;
//        cout<<"use delete count="<<++count<<std::endl;
    }


}
