#include "Infix2Postfix.h"

// 栈操作实现文件
//////////////////////////////////////////////////////////////


Stack* Stack_Create(int maxlen)
// 创建栈
{
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->data = (T*)malloc(sizeof(T) * maxlen);
    stk->max = maxlen;
    stk->top = -1;
    return stk;
}

void Stack_Free(Stack* stk)
// 释放栈
{
    free(stk->data);
    free(stk);
}

void Stack_MakeEmpty(Stack* stk)
// 置为空栈
{
    stk->top = -1;
}

bool Stack_IsEmpty(Stack* stk)
// 判断栈是否空
{
    return -1 == stk->top;
}

bool Stack_IsFull(Stack* stk)
// 判断栈是否满
{
    return stk->top == stk->max - 1;
}

T Stack_Top(Stack* stk)
// 获取当前栈顶元素
{
    return stk->data[stk->top];
}

T Stack_Push(Stack* stk, T e)
// 将元素e压入栈顶
// 返回栈顶点元素
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
// 将栈顶元素出栈
// 返回栈顶元素
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
// 打印栈顶到栈低的元素
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


int IsOperator(char ch)
{
    //判断是不是运算符
    char ops[] = "+-*/";
    int i;
    for (i = 0; i < 4; i++)
    {
        if (ch == ops[i])
            return 1;
    }
    return 0;
}


int Precedence(char op)
{
    //为优先级比较作准备
    if (op == '(')
    {
        return -1;
    }
    else if (op == '*' || op == '/')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
}


char* InFix2PostFix(char* InFix)
//转换中缀表达式到后缀表达式
{
    //分清楚入栈，进入结果数组，出字符
    int j = 0;
    int len = strlen(InFix);
    char* PostFix = (T*)malloc(sizeof(T) * len);
    Stack* ss = Stack_Create(len);

    //厘清思路，总共要判断四种符号，字母，括号，加减乘除

    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < len; i++) {
        if ((InFix[i] >= 'a' && InFix[i] <= 'z') || (InFix[i] >= 'A' && InFix[i] <= 'Z')) {
            PostFix[j++] = InFix[i];
            //注意PostFix[j++]不能用i作为参数
        }

        else if (InFix[i] == '(') {
            Stack_Push(ss, InFix[i]);
        }

        else if (InFix[i] == ')') {
            while (Stack_Top(ss) != '(') {
                PostFix[j++] = Stack_Pop(ss);
            }
            Stack_Pop(ss);
        }
        //用else if减少时间复杂度

        else if (IsOperator(InFix[i])) {
            while (!Stack_IsEmpty(ss) && Precedence(Stack_Top(ss)) >= Precedence(InFix[i])) {
                //不要漏了等于
                //注意这里要用while，因为当前元素不止跟栈顶元素比较，而是比到不符合条件为止
                PostFix[j++] = Stack_Pop(ss);
                //注意这里是pop不是top
            }
            Stack_Push(ss, InFix[i]);
        }
    }
    //别忘了处理属剩余元素
    while (!Stack_IsEmpty(ss)) {
        PostFix[j++] = Stack_Pop(ss);
    }

    /********** End **********/
    Stack_Free(ss);
    PostFix[j] = 0;   //表示字符串结束

    return PostFix;
}




