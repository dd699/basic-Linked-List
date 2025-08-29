#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) printf("Wrong Answer\n");
    }
    scanf_s("%d", &N);
    while (N--) {
        scanf_s("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    for (P = L; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X) {
    if (L == NULL) return ERROR;
    PtrToLNode p = L;
    while (p->Data != X) {
        p = p->Next;
        if (p == NULL) {
            return ERROR;
        }
    }
    return p;
}//可以找到时return也可以找完了return,如下：
//Position Find( List L, ElementType X ) {
 //   PtrToLNode p = L;
 //   while (p) {
 //      if (p->Data == X) return p;
 //       p = p->Next;
 //   }
 //   return ERROR;
//}

List Insert(List L, ElementType X, Position P) {//在P之前插入
    PtrToLNode PtrTonewLNode = (PtrToLNode)malloc(sizeof(struct LNode));//凡是要创建一个新的结点都要用malloc分配
    PtrTonewLNode->Data = X;
    //有头节点的，当在头节点之前插入时，要单独对头节点操作

    if (PtrTonewLNode == NULL) {
        // 内存分配失败，这里简单处理返回 ERROR，实际可根据需求调整
        return ERROR;
    }
    if (P == NULL) {
        // 插入到链表末尾,这种情况要单独处理
        if (L == NULL) {
            PtrTonewLNode->Next = NULL;
            return PtrTonewLNode;
        }
        PtrToLNode p = L;
        while (p->Next != NULL) {//一个查询的算法，目的是找到末尾结点的前驱结点
            p = p->Next;
        }
        p->Next = PtrTonewLNode;
        PtrTonewLNode->Next = NULL;
        return L;
    }
    if (P == L) {
        PtrTonewLNode->Next = L;
        return PtrTonewLNode;
    }
    //p是后继，pre是前驱，融合一个按位置查询的算法（按位置，按位序，按值）
    PtrToLNode p = L,pre=NULL;
    while (p && p != P) {//不能p != NULL || p != P，因为p=P时，第一个条件为真
        pre = p;
        p = p->Next;
    }
    if (p!=P) {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
    pre->Next = PtrTonewLNode;
    PtrTonewLNode->Next = p;//不是 PtrTonewLNode->Next = p->Next;

    return L;//易错点：最后返回的是L不是ptrtonewnode

}



List Delete(List L, Position P) {//删除和插入都是一样的，先查询，在造一个前驱和后继
    if (L == NULL) return ERROR;
    if (P == L) {
        PtrToLNode new = L->Next;
        free(L);//malloc free
        return new;
    }
    PtrToLNode p = L, pre = NULL;
    //从这里
    while (p && p != P) {
        pre = p;
        p = p->Next;
    }
    if (p != P) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    //到这里：与插入是一样的
    pre->Next = p->Next;
    free(p);
    return L;
}

/* 你的代码将被嵌在这里 */
