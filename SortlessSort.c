#include <stdio.h>
#include <stdlib.h>

int a[500], b[500], b1[500];

void sort(int, int);
void merging(int, int, int);
int split(int, int);

int main() {
    int n = 500, i;
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 600 + 1;
        printf("%d\t", a[i]);
    }
    sort(0, n - 1);
    printf("\n\nSortless sort result:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    
    return 0;
}

void sort(int low, int high) {
    int mid;
    if (low < high) {
        mid = split(low, high);
        sort(low, mid);
        sort(mid + 1, high);
        merging(low, mid, high);
    }
}

void merging(int low, int mid, int high) {
    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }
    while (l1 <= mid)
        b[i++] = a[l1++];
    while (l2 <= high)
        b[i++] = a[l2++];
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

int split(int low, int high) {
    int i, j = low, k;
    for (i = low; i <= high; i++) {
        if ((i - low) % 2 == 0)
            b1[j++] = a[i];
    }
    k = j - 1; 
    for (i = low; i <= high; i++) {
        if ((i - low) % 2 != 0) 
            b1[j++] = a[i];
    }
    for (i = low; i <= high; i++) {
        a[i] = b1[i];
    }
    return k;
}
