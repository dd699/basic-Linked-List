#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* ϸ���ڴ˲��� */

ElementType FindKth(List L, int K);

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
ElementType FindKth(List L, int K) {
    if (!L || K <= 0) return ERROR;//�ǵü��ձ�ʹ���ֵ�Ϸ���
    PtrToLNode p = L;
    int i = 1;
    while (i != K) {
        p = p->Next;
        i++;
        if (p == NULL) return ERROR;//�����ں���������ѭ����ֱ�ӷ���
    }
    return p->Data;

}
//�����һ��ʼ��˳�����������㿪ʼ
/* ��Ĵ��뽫��Ƕ������ */
