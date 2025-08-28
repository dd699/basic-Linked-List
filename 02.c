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
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
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
/* ��Ĵ��뽫��Ƕ������ */
List MakeEmpty() {
    List list = (List)malloc(sizeof(struct LNode));
    list->Last = -1;
    return list;
}
//����һ��ָ��ָ��һ���ṹ�壬����ṹ�������һ��������������һ��Ԫ�ص�λ��
//�����Ǵ���һ��ָ��ṹ���ָ�룬�ýṹ���а���ָ����һ���ṹ���ָ��
//˳���ֻ��һ���ṹ�壬�����кܶ����ÿ���ṹ���һ�����

Position Find(List L, ElementType X) {
    for (int i = 0; i < L->Last + 1; i++) {
        if (L->Data[i] == X) {
            return i;
        }
    }
    return ERROR;
}//����flag���ı�ʾ�Ƿ��ҵ�Ҳ��һ��˼·����û������return��

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
}//λ��Pָ�ľ��������±꣬ע������û���±�ת���������±��������
//Ҫע��L->Last��maxim�������״��,�ж��Ƿ�����max ����λ���Ƿ�Ϸ�ʱ��Last

bool Delete(List L, Position P) {
    if (P<0 || P>L->Last) { printf("POSITION %d EMPTY", P); return false; }
    for (int i = P; i < L->Last; i++) {
        L->Data[i] = L->Data[i + 1];//ƽ�ƣ�a=b��b�������Ƶ�a��λ��
    }
    L->Last--;
    return true;
}
//�״�㣺ɾ��ʱλ�����ָ��L->Last ���ǲ���ʱλ��������ָ��L->Last+1


/* ��Ĵ��뽫��Ƕ������ */