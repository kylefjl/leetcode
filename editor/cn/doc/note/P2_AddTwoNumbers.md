# 笔记

要点在于判断下一节点是否存在，指针移动的时候要注意是否为空，计算结束的标志是：**如果L1 L2 都没有下一个节点了，且不需要进位** ，**注意如果有进位则还需要再申请下一个节点**，

```cc
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
```

执行耗时:24 ms,击败了76.79% 的C++用户
内存消耗:69.3 MB,击败了88.88% 的C++用户
