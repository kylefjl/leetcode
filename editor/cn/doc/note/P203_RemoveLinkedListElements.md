# 移除链表元素
```cc

class Solution {
public://哨兵节点 遍历链表 删除节点 时间复杂度O(n) 空间复杂度O(1) 迭代
    ListNode* removeElements(ListNode* head, int val) {
        ListNode head_node(-1, head);//哨兵节点
        ListNode* node_it=&head_node;//指向当前节点
        while(node_it->next!= nullptr)//遍历链表
        {
            if(node_it->next->val==val)//如果当前节点的下一个节点的值等于val
                node_it->next=node_it->next->next;//删除当前节点的下一个节点
            else node_it=node_it->next;//否则继续遍历，指向下一个节点
        }
        return head_node.next;
    }
};
```