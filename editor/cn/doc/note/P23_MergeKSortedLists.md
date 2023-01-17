# 合并K个升序链表

## 递归(顺序合并)

先找两个合并，总链表数减1，然后递归调用mergeKLists，假设总长为n，合并后平均长度为n/k-1,n/k-2,,n/k-3。。。。

```cc
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty()) return nullptr;
        if(lists.size()>1)
        {
            ListNode* list_node=mergeTwoLists(*(lists.end()-1),*(lists.end()-2));
            lists.pop_back();
            lists.pop_back();
            lists.push_back(list_node);
            return mergeKLists(lists);
        }
        else return lists.front();
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
};
```

>执行耗时:200 ms,击败了13.98% 的C++用户
>内存消耗:15.4 MB,击败了12.66% 的C++用户

## 递归(分治合并)

将k个链表中的每两个进行合并，合并后平均长度为2n/k,4n/k,5n/k,,6n/k。。。。

```cc
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
```

>执行耗时:24 ms,击败了52.73% 的C++用户
>内存消耗:13.5 MB,击败了21.58% 的C++用户