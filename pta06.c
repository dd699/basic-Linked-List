#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum { false, true } bool;
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

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
    bool flag;

    L = MakeEmpty();
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        flag = Insert(L, X, L->Next);
        if (flag == false) printf("Wrong Answer\n");
    }
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (flag == false)
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if (flag == false) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if (flag == true) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if (flag == true) printf("Wrong Answer\n");
    for (P = L->Next; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}





//易混淆：空指针可以函数传参的参数，但是不能p->data，（会引发编译错误）在指向数据之前要判空
//与不带头节点的不同：p从表头的下一个开始遍历，表头不包含任何信息

/* 你的代码将被嵌在这里 */
List MakeEmpty() {
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;//别忘记初始化时要设置指针指向空
    return L;
}


//正确写法在于要在p->data之前判断p是否是空指针
Position Find(List L, ElementType X) {
    PtrToLNode p = L->Next;
    while (p && p->Data != X) p = p->Next; // 关键：先判断p是否为NULL
    return p ? p : ERROR;
}
/*Position Find(List L, ElementType X) {
    if (L == NULL) return ERROR;
    PtrToLNode p = L->Next;
    while (p->Data != X) {
        p = p->Next;
        if (p == NULL) {
            return ERROR;
        }
    }
    return p;
}*/

bool Insert(List L, ElementType X, Position P) {
    if (L == NULL) return false;  // 链表未初始化,明确边界条件使代码更加健壮

    PtrToLNode PtrTonewLNode = (PtrToLNode)malloc(sizeof(struct LNode));
    if (PtrTonewLNode == NULL) return false;  // 内存分配失败
    
    PtrTonewLNode->Data = X;
    
 //P为NULL,表示插入链表末尾
 /* if (P == NULL) {

        PtrToLNode p = L;
        while (p->Next != NULL) {
            p = p->Next;
        }
        p->Next = PtrTonewLNode;
        PtrTonewLNode->Next = NULL;
        return true;
    }*/
    //这里可以不用判空，因为P为空也包含在下面的情况里面

    //在指定位置P前插入
    PtrToLNode p = L->Next, pre = L;
    while (p && p != P) {
        pre = p;
        p = p->Next;
    }
    //如果P不在链表中
    if (p != P) {
        printf("Wrong Position for Insertion\n");
        return false;
    }
    pre->Next = PtrTonewLNode;
    PtrTonewLNode->Next = p;

    return true;

}
bool Delete(List L, Position P) {
    if (L == NULL) return false;
    if (P == L) {

        return false;
    }
    PtrToLNode p = L->Next, pre = L;
    while (p && p != P) {
        pre = p;
        p = p->Next;
    }
    if (p != P) {
        printf("Wrong Position for Deletion\n");
        return false;
    }
    pre->Next = p->Next;
    free(p);
    return true;
}
//只有不带头节点的要特殊操作，带头节点的只需要开头指向next，其他不用管

/* 你的代码将被嵌在这里 */