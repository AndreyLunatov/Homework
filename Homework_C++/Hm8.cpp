#include <iostream>
using namespace std;

void swapEvenOddIndices(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + i + 1);
        *(arr + i + 1) = temp;
    }
}

void mergeSortedArrays(int* A, int n, int* B, int m, int* C) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (*(A + i) <= *(B + j)) {
            *(C + k++) = *(A + i++);
        } else {
            *(C + k++) = *(B + j++);
        }
    }
    while (i < n) {
        *(C + k++) = *(A + i++);
    }
    while (j < m) {
        *(C + k++) = *(B + j++);
    }
}

void unionArrays(int* A, int n, int* B, int m, int* result, int& resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (*(A + i) < *(B + j)) {
            *(result + k++) = *(A + i++);
        } else if (*(A + i) > *(B + j)) {
            *(result + k++) = *(B + j++);
        } else {
            *(result + k++) = *(A + i++);
            j++;
        }
    }
    while (i < n) {
        *(result + k++) = *(A + i++);
    }
    while (j < m) {
        *(result + k++) = *(B + j++);
    }
    resultSize = k;
}

void intersectionArrays(int* A, int n, int* B, int m, int* result, int& resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (*(A + i) < *(B + j)) {
            i++;
        } else if (*(A + i) > *(B + j)) {
            j++;
        } else {
            *(result + k++) = *(A + i++);
            j++;
        }
    }
    resultSize = k;
}

void differenceAnotB(int* A, int n, int* B, int m, int* result, int& resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < n) {
        if (j < m && *(A + i) < *(B + j)) {
            *(result + k++) = *(A + i++);
        } else if (j < m && *(A + i) == *(B + j)) {
            i++;
            j++;
        } else if (j < m) {
            j++;
        } else {
            *(result + k++) = *(A + i++);
        }
    }
    resultSize = k;
}

void differenceBnotA(int* A, int n, int* B, int m, int* result, int& resultSize) {
    int i = 0, j = 0, k = 0;
    while (j < m) {
        if (i < n && *(B + j) < *(A + i)) {
            *(result + k++) = *(B + j++);
        } else if (i < n && *(B + j) == *(A + i)) {
            i++;
            j++;
        } else if (i < n) {
            i++;
        } else {
            *(result + k++) = *(B + j++);
        }
    }
    resultSize = k;
}

void symmetricDifference(int* A, int n, int* B, int m, int* result, int& resultSize) {
    int temp1[100], temp2[100], tempSize1, tempSize2;
    differenceAnotB(A, n, B, m, temp1, tempSize1);
    differenceBnotA(A, n, B, m, temp2, tempSize2);
    mergeSortedArrays(temp1, tempSize1, temp2, tempSize2, result);
    resultSize = tempSize1 + tempSize2;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int n = 5;
    int B[] = {2, 3, 4, 7, 8};
    int m = 5;

    cout << "Task 1: Swap Even and Odd Indices\n";
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int size1 = 6;
    cout << "Original: ";
    printArray(arr1, size1);
    swapEvenOddIndices(arr1, size1);
    cout << "After swap: ";
    printArray(arr1, size1);
    cout << endl;

    cout << "Task 2: Merge Sorted Arrays\n";
    int C[100];
    cout << "Array A: ";
    printArray(A, n);
    cout << "Array B: ";
    printArray(B, m);
    mergeSortedArrays(A, n, B, m, C);
    cout << "Merged Array C: ";
    printArray(C, n + m);
    cout << endl;

    cout << "Task 3: Set Operations\n";
    int result[100];
    int resultSize;

    cout << "Union: ";
    unionArrays(A, n, B, m, result, resultSize);
    printArray(result, resultSize);

    cout << "Intersection: ";
    intersectionArrays(A, n, B, m, result, resultSize);
    printArray(result, resultSize);

    cout << "A not B: ";
    differenceAnotB(A, n, B, m, result, resultSize);
    printArray(result, resultSize);

    cout << "B not A: ";
    differenceBnotA(A, n, B, m, result, resultSize);
    printArray(result, resultSize);

    cout << "Symmetric Difference: ";
    symmetricDifference(A, n, B, m, result, resultSize);
    printArray(result, resultSize);

    return 0;
}
