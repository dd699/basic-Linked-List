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
    //注意这里是删除所有val不是只找到一个就return
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            //使用 while 而不是 if，是因为需要处理头节点连续多个值等于目标值 val 的情况。
            ListNode* tmp = head;
            //作用是保存要删除的头节点的指针，以便后续能够释放该节点所占用的内存，避免内存泄漏。
            head = head->next;
            delete tmp;
            //释放原来的头节点
        }
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                //要改变的是什么，要变的写在左边
                delete tmp;
            }
            else {
                p = p->next;
                //要么变要么向后移
            }
        }
        return head;
        //不要忘记把头节点删掉

    }
};