#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heapify(void *base, size_t num, size_t size,
             int (*compar)(const void *, const void *),
             size_t rootIndex, size_t heapSize) {
    size_t largest = rootIndex;
    size_t leftChild = 2 * rootIndex + 1;
    size_t rightChild = 2 * rootIndex + 2;

    char *array = (char *)base;

    if (leftChild < heapSize &&
        compar(array + leftChild * size, array + largest * size) > 0)
        largest = leftChild;

    if (rightChild < heapSize &&
        compar(array + rightChild * size, array + largest * size) > 0)
        largest = rightChild;

    if (largest != rootIndex) {
        char temp[size];
        memcpy(temp, array + rootIndex * size, size);
        memcpy(array + rootIndex * size, array + largest * size, size);
        memcpy(array + largest * size, temp, size);

        heapify(base, num, size, compar, largest, heapSize);
    }
}

void heapsort(void *base, size_t num, size_t size,
              int (*compar)(const void *, const void *)) {
    // Build max heap
    for (int i = num / 2 - 1; i >= 0; --i) {
        heapify(base, num, size, compar, i, num);
    }

    // Extract elements from heap in sorted order
    for (int i = num - 1; i >= 0; --i) {
        char temp[size];
        memcpy(temp, base, size);
        memcpy(base, base + i * size, size);
        memcpy(base + i * size, temp, size);

        heapify(base, i, size, compar, 0, i);
    }
}

int intComparator(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int intArray[] = {9, 5, 7, 1, 3, 8, 2, 4, 6};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    heapsort(intArray, intArrayLength, sizeof(int), intComparator);

    printf("Sorted integer array: ");
    for (int i = 0; i < intArrayLength; ++i) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    return 0;
}
