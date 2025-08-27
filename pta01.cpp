#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Reverse(List L) { //List强调链表，Ptrtonode强调结点
    if (!L) return NULL;//链表空则返回
    PtrToNode l = NULL, mid = L, r = L->Next;
    while (r) {//最后一次循环r指向队尾结点
        mid->Next = l;//改箭头指向

        l = mid;//依次平移
        mid = r;
        r = mid->Next;
    }
    mid->Next = l;//最后一次单独处理
    return mid;//return的是mid不是L,此时表头是mid所指的位置
}
/* 你的代码将被嵌在这里 */