//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
// 
// 
// 
// 
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]
// 
//
// 示例 2： 
// 
// 
//输入：head = [1,2]
//输出：[2,1]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围是 [0, 5000] 
// -5000 <= Node.val <= 5000 
// 
//
// 
//
// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 
//
// Related Topics 递归 链表 👍 3502 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 反转链表
* @author fjl
* @date 2024-02-24 18:40:01
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}//explicit 防止隐式转换
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* reverseList(ListNode* head) {
        ListNode*  it_ptr=head;
        ListNode*  temp_ptr=nullptr;
        ListNode*  pre=nullptr;

        while(it_ptr!= nullptr)//遍历链表
        {
            temp_ptr=it_ptr->next;//保存下一个节点
            it_ptr->next=pre;//反转
            pre=it_ptr;//pre指向当前节点
            it_ptr= temp_ptr;//it_ptr指向下一个节点
        }
        return pre;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    auto* head2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* result = s.reverseList(head2);
    while(result!= nullptr)
    {
        cout << result->val << " ";
        result=result->next;
    }
}