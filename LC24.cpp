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
        //�����ǹ��캯��ҲҪnew
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        //������ͷָ�뿪ʼ����
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            //�ؼ�˼·�����ĸ�Ԫ��һ�飬��ô����˳��
            //Ҫ����������ʱֵ����Ȼ����ָ�뷽��֮���Ҳ�����

            cur->next = tmp1->next;
            cur->next->next = tmp1;
            tmp1->next = tmp2;

            cur = cur->next->next;

        }
        ListNode* result = dummyhead->next;
        delete dummyhead;
        //��ʹdummy head��ɾ������resultû�й�ϵ
        return result;
        //ע�ⲻҪ����head����Ϊhead�������ˣ�ָ��ڶ���ֵ

    }
};