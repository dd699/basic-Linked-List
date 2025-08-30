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

/* 你的代码将被嵌在这里 */
//实现共享栈，两个栈共用一个存储空间
//两个栈（Tag=1 和 Tag=2）共用数组 Data，栈 1 从数组头部向中间生长，栈 2 从数组尾部向中间生长。
//当两个栈的 “栈顶指针相邻” 时，判定为栈满；栈顶指针回到初始位置时，判定为栈空。

//创建共享栈
Stack CreateStack(int MaxSize) {
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->Data = (ElementType*)calloc(MaxSize, sizeof(ElementType));
    s->Top1 = -1, s->Top2 = MaxSize;
    //初始状态：栈为空时，栈顶指针 top = -1（假设数组下标从 0 开始）。
    //入栈操作：先将 top 加 1（top++），再将元素存入 data[top]。
    //Top1 = -1：栈 1 为空（栈 1 的栈顶指针初始在数组最左侧外）。
    //Top2 = MaxSize：栈 2 为空（栈 2 的栈顶指针初始在数组最右侧外）。
    s->MaxSize = MaxSize;
    return s;
}

//入栈
bool Push(Stack S, ElementType X, int Tag) {
    if (S->Top1 + 1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1) {
        S->Top1++;
        S->Data[S->Top1] = X;
        return true;//先进后出的入栈逻辑
    }
    if (Tag == 2) {
        S->Top2--;
        S->Data[S->Top2] = X;
        return true;
    }
    return false;
}

//出栈
ElementType Pop(Stack S, int Tag) {
    //是否满一起判断，是否空要分开判断
    if (Tag == 1) {
        if (S->Top1 == -1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
      
        return S->Data[S->Top1--];//易错点：要先取值再减减
    }
    if (Tag == 2) {
        if (S->Top2 == S->MaxSize ){
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top2++];//易错点同上
    }
    return ERROR;
 
}

/* 你的代码将被嵌在这里 */