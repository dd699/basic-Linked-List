#include<stdio.h>
#include<stdlib.h> 
#include "rec_linklist.h"

RLinkList CreateHeadList(int n) {
    // ���������Begin-End֮�䲹����룬�����㡣
    /********** Begin *********/
    RLinkList head = (RLNode*)malloc(sizeof(RLNode));
    head->num = 0;
    head->next = head;
    head->prior = head;

    RLNode* temp = head;

    for (int i = 1; i <= n; i++) {
        RLNode* p = (RLNode*)malloc(sizeof(RLNode));
        p->num = i;//����ԭʼ���
        p->next = head;//*ͷβ���

        p->prior = temp;
        temp->next = p;//��p��ǰ��ָ��ĺ��

        head->prior = p;//*ͷβ���

        temp = p;//tempָ�����
    }

    /********** End **********/
    return head;
}
void Find(RLinkList head, int* num) {
    RLinkList look = head;
    /********** Begin *********/
    look = look->next;  // �ӵ�һ����Ч�ڵ㿪ʼ
    int count = 1;      // ������1��ʼ
    int n = 0;          // ����˳������

    // ѭ�������������в�ֹһ����Ч�ڵ㣨�ų�ͷ�ڵ㣩
    while (look->next != look && look->prior != look) {
        // �ؼ�����lookָ��ͷ�ڵ㣬������ת����һ����Ч�ڵ�
        if (look == head) {
            look = look->next;
            continue;
        }

        if (count % 3 == 0) {
            num[n++] = look->num;  // ��¼�������

            RLNode* node = look;   // ����Ҫɾ���Ľڵ�

            // ����˫��ָ�룬�Ƴ�node
            node->prior->next = node->next;
            node->next->prior = node->prior;

            // �ƶ�look����һ���ڵ㣨������ͷ�ڵ㣩
            look = node->next;

            free(node);  // �ͷ��ڴ�
        }
        else {
            // δ����3���ƶ�����һ���ڵ�
            look = look->next;
        }
        count++;
    }

    // ���ʣ��Ľڵ���Ϊͷ�ڵ㣬��ת����Ч�ڵ�
    if (look == head) {
        look = look->next;
    }
    num[n] = look->num;  // ��¼����Ҵ���
    /********** End **********/
}