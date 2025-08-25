#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXN 100000
int heap[MAXN+5];  
int heapSize = 0;
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}
void heapifyDown(int i) {
    while (1) {
        int left = 2*i+1, right = 2*i+2, smallest = i;
        if (left < heapSize && heap[left] < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}
void insertHeap(int x) {
    heap[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}
void deleteHeap(int x) {
    int idx = -1;
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == x) { idx = i; break; }
    }
    if (idx == -1) return;
    heap[idx] = heap[heapSize-1];
    heapSize--;
    heapifyUp(idx);
    heapifyDown(idx);
}

int getMin() {
    return heap[0];
}
int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            insertHeap(x);
        } else if (type == 2) {
            scanf("%d", &x);
            deleteHeap(x);
        } else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
