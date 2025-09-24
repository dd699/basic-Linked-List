class MyLinkedList {

public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int a) :val(a), next(NULL) {}
    };
    //�������⣬�ڵ��±���㿪ʼ��ע������ͷ�ڵ㲻�㣬������ͷ�ڵ���ʵ�ʴ洢���ݵ�
    MyLinkedList() {
        head = new LinkedNode(0);
        //�����Ǵ���һ���½ڵ㣬��Ҫ©��new
        size = 0;
    }

    int get(int index) {
        if (index >= size || index < 0) {
            return -1;
        }
        LinkedNode* cur = head->next;
        //���ﲻ��new����Ϊcurָ������Ѿ����ڵĽڵ�
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    //-- index��������ѭ������Ϊ����ֵ�����棬������Ҳ������

    void addAtHead(int val) {
        LinkedNode* cur = new LinkedNode(val);
        //����Ҫ��new��������Ǿֲ���������������֮���ͷ�
        cur->next = head->next;
        head->next = cur;
        size++;
    }

    void addAtTail(int val) {
        LinkedNode* cur = new LinkedNode(val);
        LinkedNode* p = head;
        //������û���п�ǰ��p->next
        while (p->next != NULL) {
            //��ֹ��ָ��
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
        //ע��new��Ӧ����delete
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
    //���Ҫ����LinkedNOde�Ķ���֮��

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