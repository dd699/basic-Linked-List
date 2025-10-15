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
        CLQ_Out(rear, item);  // 传入变量本身（匹配引用参数）
}

bool CLQ_IsEmpty(LNode* rear)  // 修改为普通指针，无需引用
{
    return rear == rear->next;
}

int CLQ_Length(LNode* rear)
{
    return rear->next->data;
}

void CLQ_In(LNode*& rear, T x)  // 保持引用，用于修改外部指针
{
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data = x;
    node->next = rear->next;
    rear->next = node;
    rear = node;

    rear->next->data++;  // 不要忘记更新长度
}

bool CLQ_Out(LNode*& rear, T& item)  // 第二个参数为引用
{
    if (CLQ_IsEmpty(rear)) {
        return false;  // 队列为空
    }

    LNode* front = rear->next;  // 头节点
    LNode* first = front->next;  // 第一个元素节点

    item = first->data;  // 直接赋值给引用变量
    front->next = first->next;  // 移除节点
    free(first);

    // 队列空时更新尾指针
    if (front->next == front) {
        rear = front;
    }

    front->data--;  // 长度减1
    return true;
}

bool CLQ_Head(LNode* rear, T& item)  // 使用引用返回数据
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






