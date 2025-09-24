/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        //就算是构造函数也要new
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        //从虚拟头指针开始遍历
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            //关键思路在于四个元素一组，怎么交换顺序
            //要设置两个暂时值，不然改了指针方向之后找不到了

            cur->next = tmp1->next;
            cur->next->next = tmp1;
            tmp1->next = tmp2;

            cur = cur->next->next;

        }
        ListNode* result = dummyhead->next;
        delete dummyhead;
        //即使dummy head被删掉，跟result没有关系
        return result;
        //注意不要返回head，因为head被交换了，指向第二个值

    }
};