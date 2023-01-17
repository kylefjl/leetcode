//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
//
// Related Topics递归 | 链表 
//
// 👍 1887, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
#include <chrono>


using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class TimeCost
{
public:
    TimeCost()
    {
        start = std::chrono::system_clock::now();
    }

    TimeCost(string name_input) : funName(name_input)
    {
        start = std::chrono::system_clock::now();
    }

    void tic()
    {
        start = std::chrono::system_clock::now();
    }

    double toc()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = (end - start);
        std::cout << funName << " cost "
                  << duration.count() * std::chrono::seconds::period::num / std::chrono::seconds::period::den
                  << " second " << endl;
        return duration.count();
    }

    double toc_noOut()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = (end - start);
        return duration.count();
    }

private:
    std::chrono::time_point<chrono::system_clock> start, end;
    std::string funName = "xxx fun ";
};

/*
* K 个一组翻转链表
* @author name
* @date 2023-01-16 21:35:46
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
class Solution
{
public:
    ListNode *new_head;//用来暂存翻转后的新头节点
    ListNode *next_head;//用来暂存最新的未翻转的节点
    //调用递归函数，调用完毕后再把翻转后的链接回去，输入的head 虚拟的头节点
    inline void ReverseNode(ListNode *&head, int k)
    {
        auto cur_end = ReverseNode_it(head->next, k - 1);
        cur_end->next = next_head;//原先的前节点链接到翻转后的新头节点
        head->next = new_head;//和原先的后节点链接
    }
    inline ListNode *ReverseNode_it(ListNode *head, int k)
    {
        if (k == 0)//如果到头
        {
            new_head = head;//暂存翻转后的新头节点
            next_head = head->next;//暂存最新的未翻转的节点
            return head;
        }
        //后一个节点的next指向当前节点的地址
        else return ReverseNode_it(head->next, k - 1)->next = head;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        auto *head_pre = new ListNode{0, head};//定义首节点避免处理边界情况
        auto temp = head_pre;
        int size = 0;//首先查询链表的长度
        auto k_head = head_pre;
        ListNode *first_node = nullptr;
        while (temp->next != nullptr)
        {
            ++size;
            temp = temp->next;
            if (size % k == 0)//如果还有k个节点，则翻转
            {
                first_node = k_head->next;
                ReverseNode(k_head, k);
                if (first_node == nullptr)
                {
                    break;
                }//此时链表的顺序已经变化，temp之向翻转后的最后一个节点
                temp = k_head = first_node;
            }
        }
        auto result = head_pre->next;
        delete head_pre;//free内存
        return result;
    }
// 重载函数，如果不指定k，则翻转整个链表
     inline ListNode*& ReverseNode(ListNode*  head) {
         if(head->next== nullptr)
         {
             new_head=head;
             return head->next;
         }
         else ReverseNode(head->next)=head;
         return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s{};
    auto *heard_pre = new ListNode{0, nullptr};
    auto temp = heard_pre;
    for (int i = 0; i < 6; i++)//生成测试链表
    {
        temp->next = new ListNode{i, nullptr};
        temp = temp->next;
    }
    TimeCost timecost("reverseKGroup");
    auto result = s.reverseKGroup(heard_pre->next, 2);
    timecost.toc();//计时输出
    delete heard_pre;//free内存
    for (; result != nullptr;)//输出 [7 0 9 3]
    {
        cout << result->val << " ";
        temp = result;
        result = result->next;
        delete temp;//free内存
    }
}