#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* ϸ���ڴ˲��� */

int Length(List L);

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int Length(List L) {
    PtrToLNode p = L;
    int len = 0;
    while (p) {
        p = p->Next;//��ֹ��������������ǰ��֮����ô����
        len++;
    }
    return len;
}
/* ��Ĵ��뽫��Ƕ������ */