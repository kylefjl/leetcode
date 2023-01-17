//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
//
// Related Topics链表 | 分治 | 堆（优先队列） | 归并排序 
//
// 👍 2300, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty()) return nullptr;
        vector<ListNode*> sort_list;
        int i;
        for( i=0;(i+1)<lists.size();i+=2)
        {//每两个进行链接
            sort_list.push_back(mergeTwoLists(lists[i],lists[i+1]));
        }
        if(i==(lists.size()-1))sort_list.push_back(lists.back());//把单独的一个加上
        if(lists.size()==1)return lists.front();//合并完毕，返回节点
        return mergeKLists(sort_list);//递归
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists_low(vector<ListNode*>& lists)
    {
        if(lists.empty()) return nullptr;
        if(lists.size()>1)//还有2个以上的链表需要合并
        {//合并最后的两个
            ListNode* list_node=mergeTwoLists(*(lists.end()-1),*(lists.end()-2));
            //先弹出最后两个，再压入合并之后
            lists.pop_back();
            lists.pop_back();
            lists.push_back(list_node);
            //递归调用
            return mergeKLists(lists);
        }
        else return lists.front();//合并完毕，返回节点
    }
    //todo 优先级队列

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    ListNode l1_node[4],l2_node[3],l3_node[3];
    ListNode * result;
    l1_node[0].val=2;l1_node[0].next=&l1_node[1];
    l1_node[1].val=4;l1_node[1].next=&l1_node[2];
    l1_node[2].val=4;l1_node[2].next=&l1_node[3];
    l1_node[3].val=5;l1_node[3].next= nullptr;
    l2_node[0].val=1;l2_node[0].next=&l2_node[1];
    l2_node[1].val=4;l2_node[1].next=&l2_node[2];
    l2_node[2].val=8;l2_node[2].next= nullptr;

    l3_node[0].val=3;l3_node[0].next=&l3_node[1];
    l3_node[1].val=7;l3_node[1].next=&l3_node[2];
    l3_node[2].val=8;l3_node[2].next= nullptr;
    vector<ListNode*> input={l1_node,l2_node,l3_node};
    result=s.mergeKLists(input);
    while(result!= nullptr)
    {
        cout<<result->val<<" ";
        result=result->next;

    }
}