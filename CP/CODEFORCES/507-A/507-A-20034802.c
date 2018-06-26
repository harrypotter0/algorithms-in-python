#include <stdio.h>

typedef struct {
    int a, idx;
} Rec;

Rec rec[100];

int compare(const void *a, const void *b) {
    return ((Rec *)a)->a - ((Rec *)b)->a;
}

int main(void) {
    int i;
    int n, k;
    int cnt;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &rec[i].a);
        rec[i].idx = i + 1;
    }

    qsort(rec, n, sizeof(Rec), &compare);

    for (cnt = 0; cnt < n && k - rec[cnt].a >= 0; cnt++)
        k -= rec[cnt].a;

    printf("%d\n", cnt);
    for (i = 0; i < cnt; i++)
        printf("%d ", rec[i].idx);

    return 0;
}