# 反转链表

```cc
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

```

