//你可以选择使用单链表或者双链表，设计并实现自己的链表。 
//
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。 
//
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。 
//
// 实现 MyLinkedList 类： 
//
// 
// MyLinkedList() 初始化 MyLinkedList 对象。 
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。 
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。 
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。 
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 
//index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。 
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", 
//"deleteAtIndex", "get"]
//[[], [1], [3], [1, 2], [1], [1], [1]]
//输出
//[null, null, null, null, 2, null, 3]
//
//解释
//MyLinkedList myLinkedList = new MyLinkedList();
//myLinkedList.addAtHead(1);
//myLinkedList.addAtTail(3);
//myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
//myLinkedList.get(1);              // 返回 2
//myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
//myLinkedList.get(1);              // 返回 3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= index, val <= 1000 
// 请不要使用内置的 LinkedList 库。 
// 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。 
// 
//
// Related Topics 设计 链表 👍 995 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 设计链表
* @author fjl
* @date 2024-02-24 16:41:50
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}//explicit 防止隐式转换
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
    MyLinkedList() {
        this->dummyHead = new ListNode(0);//虚拟头节点
        this->size = 0;//链表长度 初始化为0
    }
    ~MyLinkedList() {
        delete dummyHead;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) { //下标无效 返回-1
            return -1;
        }
        ListNode* cur = dummyHead;
        for (int i = 0; i <= index; ++i) {
            cur = cur->next;
        }
        return cur->val;

    }
    
    void addAtHead(int val) {// 在头部插入
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val); //在尾部插入
    }
    
    void addAtIndex(int index, int val) {//在指定位置之前插入
        if (index < 0 || index > size) {//下标无效 不插入
            return;
        }
        ListNode* prev = dummyHead;
        for (int i = 0; i < index; ++i) {//找到插入位置的前一个节点
            prev = prev->next;
        }
        prev->next = new ListNode(val, prev->next);//插入节点
        size++;

    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {//下标无效 不删除
            return;
        }
        ListNode* prev = dummyHead;
        for (int i = 0; i < index; ++i) {//找到删除位置的前一个节点
            prev = prev->next;
        }
        ListNode* delNode = prev->next;//暂存删除节点
        prev->next = prev->next->next;//指向需删除节点的下一个节点
        delete delNode;//释放内存
        size--;
    }
    //虚拟头节点
    ListNode* dummyHead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
//   Solution s;



}