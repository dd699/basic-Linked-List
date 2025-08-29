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

/* ��Ĵ��뽫��Ƕ������ */
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
}//�����ҵ�ʱreturnҲ����������return,���£�
//Position Find( List L, ElementType X ) {
 //   PtrToLNode p = L;
 //   while (p) {
 //      if (p->Data == X) return p;
 //       p = p->Next;
 //   }
 //   return ERROR;
//}

List Insert(List L, ElementType X, Position P) {//��P֮ǰ����
    PtrToLNode PtrTonewLNode = (PtrToLNode)malloc(sizeof(struct LNode));//����Ҫ����һ���µĽ�㶼Ҫ��malloc����
    PtrTonewLNode->Data = X;
    //��ͷ�ڵ�ģ�����ͷ�ڵ�֮ǰ����ʱ��Ҫ������ͷ�ڵ����

    if (PtrTonewLNode == NULL) {
        // �ڴ����ʧ�ܣ�����򵥴����� ERROR��ʵ�ʿɸ����������
        return ERROR;
    }
    if (P == NULL) {
        // ���뵽����ĩβ,�������Ҫ��������
        if (L == NULL) {
            PtrTonewLNode->Next = NULL;
            return PtrTonewLNode;
        }
        PtrToLNode p = L;
        while (p->Next != NULL) {//һ����ѯ���㷨��Ŀ�����ҵ�ĩβ����ǰ�����
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
    //p�Ǻ�̣�pre��ǰ�����ں�һ����λ�ò�ѯ���㷨����λ�ã���λ�򣬰�ֵ��
    PtrToLNode p = L,pre=NULL;
    while (p && p != P) {//����p != NULL || p != P����Ϊp=Pʱ����һ������Ϊ��
        pre = p;
        p = p->Next;
    }
    if (p!=P) {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
    pre->Next = PtrTonewLNode;
    PtrTonewLNode->Next = p;//���� PtrTonewLNode->Next = p->Next;

    return L;//�״�㣺��󷵻ص���L����ptrtonewnode

}



List Delete(List L, Position P) {//ɾ���Ͳ��붼��һ���ģ��Ȳ�ѯ������һ��ǰ���ͺ��
    if (L == NULL) return ERROR;
    if (P == L) {
        PtrToLNode new = L->Next;
        free(L);//malloc free
        return new;
    }
    PtrToLNode p = L, pre = NULL;
    //������
    while (p && p != P) {
        pre = p;
        p = p->Next;
    }
    if (p != P) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    //������������һ����
    pre->Next = p->Next;
    free(p);
    return L;
}

/* ��Ĵ��뽫��Ƕ������ */
