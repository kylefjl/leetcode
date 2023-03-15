# 旋转链表

没啥需要考虑的地方，注意k可能比链表的长度大

```cc
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
```