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
    //ע��������ɾ������val����ֻ�ҵ�һ����return
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            //ʹ�� while ������ if������Ϊ��Ҫ����ͷ�ڵ��������ֵ����Ŀ��ֵ val �������
            ListNode* tmp = head;
            //�����Ǳ���Ҫɾ����ͷ�ڵ��ָ�룬�Ա�����ܹ��ͷŸýڵ���ռ�õ��ڴ棬�����ڴ�й©��
            head = head->next;
            delete tmp;
            //�ͷ�ԭ����ͷ�ڵ�
        }
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                //Ҫ�ı����ʲô��Ҫ���д�����
                delete tmp;
            }
            else {
                p = p->next;
                //Ҫô��Ҫô�����
            }
        }
        return head;
        //��Ҫ���ǰ�ͷ�ڵ�ɾ��

    }
};