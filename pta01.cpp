#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲��� */

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

/* ��Ĵ��뽫��Ƕ������ */
List Reverse(List L) { //Listǿ������Ptrtonodeǿ�����
    if (!L) return NULL;//������򷵻�
    PtrToNode l = NULL, mid = L, r = L->Next;
    while (r) {//���һ��ѭ��rָ���β���
        mid->Next = l;//�ļ�ͷָ��

        l = mid;//����ƽ��
        mid = r;
        r = mid->Next;
    }
    mid->Next = l;//���һ�ε�������
    return mid;//return����mid����L,��ʱ��ͷ��mid��ָ��λ��
}
/* ��Ĵ��뽫��Ƕ������ */