//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
//
// Related Topics递归 | 链表 
//
// 👍 2861, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
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
* 合并两个有序链表
* @author name
* @date 2023-01-14 16:02:59
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1== nullptr&&list2== nullptr)return nullptr;
        else if(list1== nullptr)return list2;//判断边界情况
        else if(list2== nullptr)return list1;
        ListNode *front,*back,*result;
        //小的为front，大的为back
        list1->val<=list2->val? (front=list1,back=list2):(front=list2,back=list1);
        result=front;//存储头节点
        while(front->next!= nullptr)
        {//移动front到需要插入back的位置
            if(front->next->val<=back->val)//如果front的下一个还是小于back，则front移动到下一个
                front=front->next;
            else break;
        }
        //开始递归链接
        link_list(front,back);
        return result;//返回头节点
    }
    //递归链接，back链接到front后
    inline ListNode* link_list(ListNode*& front,ListNode*& back)
    {
        if( front->next== nullptr)
        { //front节点到头了，直接链接并退出
            front->next=back;
            return nullptr;
        }
        ListNode* temp_ptr=front->next;//暂存front的下个节点位置
        front->next=back;//链接
        while(back->next!= nullptr)
        {//移动back直到其比front大
            // 如果back的下一个小于temp_ptr，则back移动到下一个
            if(back->next->val<=temp_ptr->val)
                back=back->next;
            else
            {
                //此时back小于temp_ptr且back的下一个大于temp_ptr，
                //temp_ptr链接到back后
                return link_list(back,temp_ptr);
            }
        }
        //back节点到头了，直接链接并退出
        back->next=temp_ptr;
        return nullptr;
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
    l1_node[2].val=4;l1_node[2].next=&l1_node[3];
    l1_node[3].val=5;l1_node[3].next= nullptr;
    l2_node[0].val=1;l2_node[0].next=&l2_node[1];
    l2_node[1].val=4;l2_node[1].next=&l2_node[2];
    l2_node[2].val=8;l2_node[2].next= nullptr;
    result=s.mergeTwoLists(l2_node,l1_node);
    while(result!= nullptr)
    {
        cout<<result->val<<" ";
        result=result->next;

    }
}