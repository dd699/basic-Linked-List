#include <stdio.h>
#include <stdlib.h>
#include "CLnkQueue.h"

LNode* CLQ_Create()
{
    LNode* rear = (LNode*)malloc(sizeof(LNode));
    rear->data = 0;
    rear->next = rear;
    return rear;
}

void CLQ_Free(LNode* rear)
{
    CLQ_MakeEmpty(rear);
    free(rear);
}

void CLQ_MakeEmpty(LNode*& rear)
{
    T item;
    while (!CLQ_IsEmpty(rear))
        CLQ_Out(rear, item);  // �����������ƥ�����ò�����
}

bool CLQ_IsEmpty(LNode* rear)  // �޸�Ϊ��ָͨ�룬��������
{
    return rear == rear->next;
}

int CLQ_Length(LNode* rear)
{
    return rear->next->data;
}

void CLQ_In(LNode*& rear, T x)  // �������ã������޸��ⲿָ��
{
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data = x;
    node->next = rear->next;
    rear->next = node;
    rear = node;

    rear->next->data++;  // ��Ҫ���Ǹ��³���
}

bool CLQ_Out(LNode*& rear, T& item)  // �ڶ�������Ϊ����
{
    if (CLQ_IsEmpty(rear)) {
        return false;  // ����Ϊ��
    }

    LNode* front = rear->next;  // ͷ�ڵ�
    LNode* first = front->next;  // ��һ��Ԫ�ؽڵ�

    item = first->data;  // ֱ�Ӹ�ֵ�����ñ���
    front->next = first->next;  // �Ƴ��ڵ�
    free(first);

    // ���п�ʱ����βָ��
    if (front->next == front) {
        rear = front;
    }

    front->data--;  // ���ȼ�1
    return true;
}

bool CLQ_Head(LNode* rear, T& item)  // ʹ�����÷�������
{
    if (CLQ_IsEmpty(rear))
        return false;

    item = rear->next->next->data;
    return true;
}

void CLQ_Print(LNode* rear)
{
    if (CLQ_IsEmpty(rear)) {
        printf("The queue is: empty. \n");
        return;
    }
    LNode* node = rear->next->next;
    do {
        printf("%d  ", node->data);
        node = node->next;
    } while (node != rear->next);
    printf("\n");
}






