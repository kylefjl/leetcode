# K个一组翻转链表

## 递归

迭代确定k个一组节点的头节点位置，然后调用递归函数处理k个节点的翻转

```cc
class Solution
{
public:

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
```

>执行耗时:8 ms,击败了98.20% 的C++用户
>内存消耗:11.2 MB,击败了47.15% 的C++用户