#include<stdio.h>
#include<stdlib.h> 
#include "rec_linklist.h"

RLinkList CreateHeadList(int n) {
    // 请在下面的Begin-End之间补充代码，插入结点。
    /********** Begin *********/
    RLinkList head = (RLNode*)malloc(sizeof(RLNode));
    head->num = 0;
    head->next = head;
    head->prior = head;

    RLNode* temp = head;

    for (int i = 1; i <= n; i++) {
        RLNode* p = (RLNode*)malloc(sizeof(RLNode));
        p->num = i;//储存原始序号
        p->next = head;//*头尾相接

        p->prior = temp;
        temp->next = p;//改p的前驱指针的后继

        head->prior = p;//*头尾相接

        temp = p;//temp指针后移
    }

    /********** End **********/
    return head;
}
void Find(RLinkList head, int* num) {
    RLinkList look = head;
    /********** Begin *********/
    look = look->next;  // 从第一个有效节点开始
    int count = 1;      // 报数从1开始
    int n = 0;          // 出列顺序索引

    // 循环条件：链表中不止一个有效节点（排除头节点）
    while (look->next != look && look->prior != look) {
        // 关键：若look指向头节点，立即跳转到下一个有效节点
        if (look == head) {
            look = look->next;
            continue;
        }

        if (count % 3 == 0) {
            num[n++] = look->num;  // 记录出列序号

            RLNode* node = look;   // 保存要删除的节点

            // 调整双向指针，移除node
            node->prior->next = node->next;
            node->next->prior = node->prior;

            // 移动look到下一个节点（可能是头节点）
            look = node->next;

            free(node);  // 释放内存
        }
        else {
            // 未报到3，移动到下一个节点
            look = look->next;
        }
        count++;
    }

    // 最后剩余的节点若为头节点，跳转到有效节点
    if (look == head) {
        look = look->next;
    }
    num[n] = look->num;  // 记录最后幸存者
    /********** End **********/
}