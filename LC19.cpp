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
            //要注意这里不是判断curA的下一个
            curA = curA->next;
            lenA++;
        }
        while (curB != nullptr) {
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        //注意上面的指针重制要写在交换的上面，很巧妙
        if (lenB > lenA) {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int len = 0;
        //注意要初始化len
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
        //注意这个循环很典型，如果正确就跳出，不正确就继续，直到最后都没找到很像查找算法
        //最后不要忘了在最终的大括号内部return 
    }
};