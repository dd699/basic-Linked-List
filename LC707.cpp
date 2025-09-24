class MyLinkedList {

public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int a) :val(a), next(NULL) {}
    };
    //根据题意，节点下标从零开始，注意虚拟头节点不算，真正的头节点是实际存储数据的
    MyLinkedList() {
        head = new LinkedNode(0);
        //这里是创建一个新节点，不要漏了new
        size = 0;
    }

    int get(int index) {
        if (index >= size || index < 0) {
            return -1;
        }
        LinkedNode* cur = head->next;
        //这里不用new，因为cur指向的是已经存在的节点
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    //-- index会陷入死循环，因为非零值返回真，即负数也返回真

    void addAtHead(int val) {
        LinkedNode* cur = new LinkedNode(val);
        //这里要用new，否则就是局部变量，函数结束之后被释放
        cur->next = head->next;
        head->next = cur;
        size++;
    }

    void addAtTail(int val) {
        LinkedNode* cur = new LinkedNode(val);
        LinkedNode* p = head;
        //不能在没有判空前让p->next
        while (p->next != NULL) {
            //防止空指针
            p = p->next;
        }
        cur->next = p->next;
        p->next = cur;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index > size) {
            return;
        }
        LinkedNode* cur = new LinkedNode(val);
        LinkedNode* p = head;
        while (index--) {
            p = p->next;
        }
        cur->next = p->next;
        p->next = cur;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        LinkedNode* p = head;
        while (index--) {
            p = p->next;
        }
        LinkedNode* tmp = p->next;
        p->next = tmp->next;
        delete tmp;
        //注意new对应的是delete
        size--;
    }
    void printLinkedList() {
        LinkedNode* cur = head;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    LinkedNode* head;
    int size;
    //这个要放在LinkedNOde的定义之后

};

/*
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */