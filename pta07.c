#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType* Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode* Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf_s("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
        case push:
            scanf_s("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf_s("%d", &Tag);
            X = Pop(S, Tag);
            if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
//ʵ�ֹ���ջ������ջ����һ���洢�ռ�
//����ջ��Tag=1 �� Tag=2���������� Data��ջ 1 ������ͷ�����м�������ջ 2 ������β�����м�������
//������ջ�� ��ջ��ָ�����ڡ� ʱ���ж�Ϊջ����ջ��ָ��ص���ʼλ��ʱ���ж�Ϊջ�ա�

//��������ջ
Stack CreateStack(int MaxSize) {
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->Data = (ElementType*)calloc(MaxSize, sizeof(ElementType));
    s->Top1 = -1, s->Top2 = MaxSize;
    //��ʼ״̬��ջΪ��ʱ��ջ��ָ�� top = -1�����������±�� 0 ��ʼ����
    //��ջ�������Ƚ� top �� 1��top++�����ٽ�Ԫ�ش��� data[top]��
    //Top1 = -1��ջ 1 Ϊ�գ�ջ 1 ��ջ��ָ���ʼ������������⣩��
    //Top2 = MaxSize��ջ 2 Ϊ�գ�ջ 2 ��ջ��ָ���ʼ���������Ҳ��⣩��
    s->MaxSize = MaxSize;
    return s;
}

//��ջ
bool Push(Stack S, ElementType X, int Tag) {
    if (S->Top1 + 1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1) {
        S->Top1++;
        S->Data[S->Top1] = X;
        return true;//�Ƚ��������ջ�߼�
    }
    if (Tag == 2) {
        S->Top2--;
        S->Data[S->Top2] = X;
        return true;
    }
    return false;
}

//��ջ
ElementType Pop(Stack S, int Tag) {
    //�Ƿ���һ���жϣ��Ƿ��Ҫ�ֿ��ж�
    if (Tag == 1) {
        if (S->Top1 == -1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
      
        return S->Data[S->Top1--];//�״�㣺Ҫ��ȡֵ�ټ���
    }
    if (Tag == 2) {
        if (S->Top2 == S->MaxSize ){
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top2++];//�״��ͬ��
    }
    return ERROR;
 
}

/* ��Ĵ��뽫��Ƕ������ */