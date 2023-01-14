# 合并K个升序链表

## 递归

递归调用，两个两个地合并

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