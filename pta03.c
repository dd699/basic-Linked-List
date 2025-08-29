#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length(List L);

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Length(List L) {
    PtrToLNode p = L;
    int len = 0;
    while (p) {
        p = p->Next;//终止条件，计数器，前后之间怎么传递
        len++;
    }
    return len;
}
/* 你的代码将被嵌在这里 */