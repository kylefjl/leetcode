# 环形链表 II

```cc
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;// 哈希表
        ListNode* dummy=new ListNode(0,head);// 哨兵节点
        ListNode* it=dummy;
        while (it!=nullptr)
        {
            if(visited.count(it))break;// 如果当前节点已经被访问过，说明有环，退出
            visited.insert(it);// 否则，将当前节点加入哈希表
            it=it->next;// 指向下一个节点
        }
        return it;
        
    }
};
```

