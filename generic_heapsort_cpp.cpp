#include <iostream>

template<typename T>
void heapify(T *array, size_t heapSize, size_t rootIndex) {
    size_t largest = rootIndex;
    size_t leftChild = 2 * rootIndex + 1;
    size_t rightChild = 2 * rootIndex + 2;

    if (leftChild < heapSize && array[leftChild] > array[largest])
        largest = leftChild;

    if (rightChild < heapSize && array[rightChild] > array[largest])
        largest = rightChild;

    if (largest != rootIndex) {
        std::swap(array[rootIndex], array[largest]);
        heapify(array, heapSize, largest);
    }
}

template<typename T>
void heapsort(T *array, size_t arrayLength) {
    for (int i = arrayLength / 2 - 1; i >= 0; --i) {
        heapify(array, arrayLength, i);
    }

    for (int i = arrayLength - 1; i >= 0; --i) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    // Testing heapsort with integers
    int intArray[] = {9, 5, 7, 1, 3, 8, 2, 4, 6};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);
    heapsort(intArray, intArrayLength);

    std::cout << "Sorted integer array: ";
    for (int i = 0; i < intArrayLength; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Testing heapsort with characters
    char charArray[] = {'g', 'e', 'c', 'a', 'f', 'd', 'b'};
    size_t charArrayLength = sizeof(charArray) / sizeof(char);
    heapsort(charArray, charArrayLength);

    std::cout << "Sorted character array: ";
    for (int i = 0; i < charArrayLength; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
