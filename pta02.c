#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum { false, true } bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        if (Insert(L, X, 0) == false)
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &P);
        if (Delete(L, P) == false)
            printf(" Deletion Error.\n");
        if (Insert(L, 0, P) == false)
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty() {
    List list = (List)malloc(sizeof(struct LNode));
    list->Last = -1;
    return list;
}
//创建一个指针指向一个结构体，这个结构体包含了一个数组和数组最后一个元素的位置
//链表是创建一个指向结构体的指针，该结构体中包含指向下一个结构体的指针
//顺序表只有一个结构体，链表有很多个，每个结构体存一个结点

Position Find(List L, ElementType X) {
    for (int i = 0; i < L->Last + 1; i++) {
        if (L->Data[i] == X) {
            return i;
        }
    }
    return ERROR;
}//设置flag旗帜表示是否找到也是一种思路，但没有两个return快

bool Insert(List L, ElementType X, Position P) {
    if (L->Last == (MAXSIZE - 1)) {
        printf("FULL");
        return false;
    }
    if (P<0 || P>L->Last + 1) {
        printf("ILLEGAL POSITION");
        return false;
    }
    L->Last++;
    for (int i = L->Last; i > P; i--) {
        L->Data[i] = L->Data[i - 1];
    }
    L->Data[P] = X;
    return true;
}//位置P指的就是数组下标，注意这里没有下标转换，而且下标最大是四
//要注意L->Last与maxim的区别，易错点,判断是否满用max 插入位置是否合法时用Last

bool Delete(List L, Position P) {
    if (P<0 || P>L->Last) { printf("POSITION %d EMPTY", P); return false; }
    for (int i = P; i < L->Last; i++) {
        L->Data[i] = L->Data[i + 1];//平移：a=b，b的内容移到a的位置
    }
    L->Last--;
    return true;
}
//易错点：删除时位置最多指向L->Last 但是插入时位置最多可以指向L->Last+1


/* 你的代码将被嵌在这里 */
