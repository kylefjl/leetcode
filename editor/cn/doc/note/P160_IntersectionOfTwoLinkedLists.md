# 相交链表



#### 哈希集合

```cc
   ListNode *getIntersectionNode_hash(ListNode *headA, ListNode *headB){
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
```

#### 双指针

```cc


  //双指针 时间复杂度O(m+n) 空间复杂度O(1)
    ListNode *getIntersectionNode_ptr(ListNode *headA, ListNode *headB){
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = (pA == nullptr ? headB : pA->next);
            pB = (pB == nullptr ? headA : pB->next);
        }
        return pA;
    }

```

