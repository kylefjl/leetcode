# 设计链表



```cc
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
```

