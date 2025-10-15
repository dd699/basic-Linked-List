#include "Infix2Postfix.h"

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


int IsOperator(char ch)
{
    //�ж��ǲ��������
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
    //Ϊ���ȼ��Ƚ���׼��
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
//ת����׺���ʽ����׺���ʽ
{
    //�������ջ�����������飬���ַ�
    int j = 0;
    int len = strlen(InFix);
    char* PostFix = (T*)malloc(sizeof(T) * len);
    Stack* ss = Stack_Create(len);

    //����˼·���ܹ�Ҫ�ж����ַ��ţ���ĸ�����ţ��Ӽ��˳�

    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    for (int i = 0; i < len; i++) {
        if ((InFix[i] >= 'a' && InFix[i] <= 'z') || (InFix[i] >= 'A' && InFix[i] <= 'Z')) {
            PostFix[j++] = InFix[i];
            //ע��PostFix[j++]������i��Ϊ����
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
        //��else if����ʱ�临�Ӷ�

        else if (IsOperator(InFix[i])) {
            while (!Stack_IsEmpty(ss) && Precedence(Stack_Top(ss)) >= Precedence(InFix[i])) {
                //��Ҫ©�˵���
                //ע������Ҫ��while����Ϊ��ǰԪ�ز�ֹ��ջ��Ԫ�رȽϣ����Ǳȵ�����������Ϊֹ
                PostFix[j++] = Stack_Pop(ss);
                //ע��������pop����top
            }
            Stack_Push(ss, InFix[i]);
        }
    }
    //�����˴�����ʣ��Ԫ��
    while (!Stack_IsEmpty(ss)) {
        PostFix[j++] = Stack_Pop(ss);
    }

    /********** End **********/
    Stack_Free(ss);
    PostFix[j] = 0;   //��ʾ�ַ�������

    return PostFix;
}




