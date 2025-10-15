#include "stack_.h"

// ջ����ʵ���ļ�
//////////////////////////////////////////////////////////////


Stack* Stack_Create(int maxlen)
// ����ջ
{
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->data = (T*)malloc(sizeof(T) * maxlen);
    stk->max = maxlen;
    stk->top = -1;
    return stk;
}

void Stack_Free(Stack* stk)
// �ͷ�ջ
{
    free(stk->data);
    free(stk);
}

void Stack_MakeEmpty(Stack* stk)
// ��Ϊ��ջ
{
    stk->top = -1;
}

bool Stack_IsEmpty(Stack* stk)
// �ж�ջ�Ƿ��
{
    return -1 == stk->top;
}

bool Stack_IsFull(Stack* stk)
// �ж�ջ�Ƿ���
{
    return stk->top == stk->max - 1;
}

T Stack_Top(Stack* stk)
// ��ȡ��ǰջ��Ԫ��
{
    return stk->data[stk->top];
}

T Stack_Push(Stack* stk, T e)
// ��Ԫ��eѹ��ջ��
// ����ջ����Ԫ��
{
    if (Stack_IsFull(stk)) {
        printf("Stack_IsFull(): stack full error when push element to the stack!\n");
        Stack_Free(stk);
        exit(0);
    }
    else {
        stk->top += 1;
        stk->data[stk->top] = e;
        return Stack_Top(stk);
    }
}

T Stack_Pop(Stack* stk)
// ��ջ��Ԫ�س�ջ
// ����ջ��Ԫ��
{
    if (Stack_IsEmpty(stk)) {
        printf("Stack_IsEmpty(): stack empty error when pop element of the stack top!\n");
        Stack_Free(stk);
        exit(0);
    }
    else {
        T topE = Stack_Top(stk);
        stk->top -= 1;
        return topE;
    }
}

void Stack_Print(Stack* stk)
// ��ӡջ����ջ�͵�Ԫ��
{
    if (Stack_IsEmpty(stk)) {
        printf("The stack is empty.\n");
        return;
    }

    //printf("The stack contains: ");
    for (int i = stk->top; i >= 0; i--) {
        printf("%d", stk->data[i]);
    }
    printf("\n");

}

void Decimal_Conversion_Octal(T e)
//  ����stackջʵ��������ʮ����ת�˽���
//  ���������ʮ�������� e
//  ��ӡe�İ˽��ƽ����ĩβ����
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    Stack* stk = Stack_Create(32);//����һ��ջʵ��

    while (e > 0) {
        int i = e % 8;
        Stack_Push(stk, i);
        e = (e - i) / 8;
        //���ﻻ��k�Ϳ���ʵ���������ת��
    }

    //��ӡջ��Ԫ��
    Stack_Print(stk);

    /********** End **********/
}





