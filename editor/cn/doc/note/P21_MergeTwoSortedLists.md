# 合并两个有序链表

## 递归

递归调用，为了减少递归次数在每次递归里面增加了while循环已找到插入点

```cc
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
```

>执行耗时:8 ms,击败了57.82% 的C++用户
>内存消耗:14.4 MB,击败了34.20% 的C++用户

官方递归，看着很简约

```cc
class Solution {
public:
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
};

```

