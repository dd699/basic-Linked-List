/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        while (curA != nullptr) {
            //Ҫע�����ﲻ���ж�curA����һ��
            curA = curA->next;
            lenA++;
        }
        while (curB != nullptr) {
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        //ע�������ָ������Ҫд�ڽ��������棬������
        if (lenB > lenA) {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int len = 0;
        //ע��Ҫ��ʼ��len
        len = lenA - lenB;

        while (len--) {
            curA = curA->next;
        }
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
        //ע�����ѭ���ܵ��ͣ������ȷ������������ȷ�ͼ�����ֱ�����û�ҵ���������㷨
        //���Ҫ���������յĴ������ڲ�return 
    }
};