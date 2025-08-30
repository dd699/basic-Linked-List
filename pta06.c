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





//�׻�������ָ����Ժ������εĲ��������ǲ���p->data�������������������ָ������֮ǰҪ�п�
//�벻��ͷ�ڵ�Ĳ�ͬ��p�ӱ�ͷ����һ����ʼ��������ͷ�������κ���Ϣ

/* ��Ĵ��뽫��Ƕ������ */
List MakeEmpty() {
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;//�����ǳ�ʼ��ʱҪ����ָ��ָ���
    return L;
}


//��ȷд������Ҫ��p->data֮ǰ�ж�p�Ƿ��ǿ�ָ��
Position Find(List L, ElementType X) {
    PtrToLNode p = L->Next;
    while (p && p->Data != X) p = p->Next; // �ؼ������ж�p�Ƿ�ΪNULL
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
    if (L == NULL) return false;  // ����δ��ʼ��,��ȷ�߽�����ʹ������ӽ�׳

    PtrToLNode PtrTonewLNode = (PtrToLNode)malloc(sizeof(struct LNode));
    if (PtrTonewLNode == NULL) return false;  // �ڴ����ʧ��
    
    PtrTonewLNode->Data = X;
    
 //PΪNULL,��ʾ��������ĩβ
 /* if (P == NULL) {

        PtrToLNode p = L;
        while (p->Next != NULL) {
            p = p->Next;
        }
        p->Next = PtrTonewLNode;
        PtrTonewLNode->Next = NULL;
        return true;
    }*/
    //������Բ����пգ���ΪPΪ��Ҳ������������������

    //��ָ��λ��Pǰ����
    PtrToLNode p = L->Next, pre = L;
    while (p && p != P) {
        pre = p;
        p = p->Next;
    }
    //���P����������
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
//ֻ�в���ͷ�ڵ��Ҫ�����������ͷ�ڵ��ֻ��Ҫ��ͷָ��next���������ù�

/* ��Ĵ��뽫��Ƕ������ */