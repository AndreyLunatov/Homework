#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int* createArray(int& size, int& capacity, int initialCapacity) {
    capacity = (initialCapacity <= 0) ? 10 : initialCapacity;
    size = 0;
    int* arr = new int[capacity];
    cout << "Введіть " << initialCapacity << " елементів масиву:\n";
    for (int i = 0; i < initialCapacity; i++) {
        cin >> arr[i];
        size++;
    }
    return arr;
}


void printArray(int* arr, int size) {
    if (size == 0) {
        cout << "Масив порожній" << endl;
        return;
    }
    cout << "Масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void resize(int*& arr, int& size, int& capacity) {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}


void shrink(int*& arr, int& size, int& capacity) {
    if (capacity <= 10) return;
    capacity /= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

// Завдання 1: Видалити елемент за індексом
int* removeElementAtIndex(int* arr, int& size, int& capacity, int index) {
    if (index < 0 || index >= size) {
        cout << "Некоректний індекс!" << endl;
        return arr;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    if (size < capacity / 2 && capacity > 10) {
        shrink(arr, size, capacity);
    }
    return arr;
}

// Завдання 2: Створити масив із від’ємних чисел
int* getNegativeNumbers(int* arr, int size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) newSize++;
    }
    int* negArr = new int[newSize];
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) negArr[k++] = arr[i];
    }
    return negArr;
}

// Завдання 3: Об’єднати два масиви
int* mergeArrays(int* A, int sizeA, int* B, int sizeB, int& newSize) {
    newSize = sizeA + sizeB;
    int* merged = new int[newSize];
    for (int i = 0; i < sizeA; i++) {
        merged[i] = A[i];
    }
    for (int i = 0; i < sizeB; i++) {
        merged[sizeA + i] = B[i];
    }
    return merged;
}

// Завдання 4: Знайти спільні елементи двох масивів
int* getCommonElements(int* A, int sizeA, int* B, int sizeB, int& newSize) {
    newSize = 0;
    int maxSize = (sizeA < sizeB) ? sizeA : sizeB;
    int* common = new int[maxSize];
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                bool alreadyAdded = false;
                for (int k = 0; k < newSize; k++) {
                    if (common[k] == A[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    common[newSize++] = A[i];
                }
            }
        }
    }
    return common;
}

// Завдання 5: Елементи A, які не входять до B
int* getUniqueElementsA(int* A, int sizeA, int* B, int sizeB, int& newSize) {
    newSize = 0;
    int* unique = new int[sizeA];
    for (int i = 0; i < sizeA; i++) {
        bool found = false;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique[newSize++] = A[i];
        }
    }
    return unique;
}

// Завдання 6: Елементи, які не є спільними для A і B
int* getNonCommonElements(int* A, int sizeA, int* B, int sizeB, int& newSize) {
    newSize = 0;
    int* temp = new int[sizeA + sizeB];
    // Елементи A, які не в B
    for (int i = 0; i < sizeA; i++) {
        bool found = false;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[newSize++] = A[i];
        }
    }
    // Елементи B, які не в A
    for (int i = 0; i < sizeB; i++) {
        bool found = false;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[newSize++] = B[i];
        }
    }
    int* result = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        result[i] = temp[i];
    }
    delete[] temp;
    return result;
}

// Завдання 7: Додавання блоку елементів у кінець
void appendBlock(int*& arr, int& size, int& capacity, int* block, int blockSize) {
    while (size + blockSize > capacity) {
        resize(arr, size, capacity);
    }
    for (int i = 0; i < blockSize; i++) {
        arr[size + i] = block[i];
    }
    size += blockSize;
}

// Завдання 8: Вставка блоку елементів за індексом
void insertBlock(int*& arr, int& size, int& capacity, int index, int* block, int blockSize) {
    if (index < 0 || index > size) {
        cout << "Некоректний індекс!" << endl;
        return;
    }
    while (size + blockSize > capacity) {
        resize(arr, size, capacity);
    }
    for (int i = size - 1; i >= index; i--) {
        arr[i + blockSize] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        arr[index + i] = block[i];
    }
    size += blockSize;
}

// Завдання 9: Видалення блоку елементів
void removeBlock(int*& arr, int& size, int& capacity, int index, int blockSize) {
    if (index < 0 || index >= size || blockSize < 0 || index + blockSize > size) {
        cout << "Некоректні параметри для видалення блоку!" << endl;
        return;
    }
    for (int i = index; i < size - blockSize; i++) {
        arr[i] = arr[i + blockSize];
    }
    size -= blockSize;
    if (size < capacity / 2 && capacity > 10) {
        shrink(arr, size, capacity);
    }
}

// Завдання 10: Видалити прості числа
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) newSize++;
    }
    int* newArr = new int[newSize];
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[k++] = arr[i];
        }
    }
    return newArr;
}

// Завдання 11: Розподіл статичного масиву на додатні, від’ємні та нульові
void distributeArray(int* arr, int size, int*& posArr, int& posSize, int*& negArr, int& negSize, int*& zeroArr, int& zeroSize) {
    posSize = negSize = zeroSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) posSize++;
        else if (arr[i] < 0) negSize++;
        else zeroSize++;
    }
    posArr = new int[posSize];
    negArr = new int[negSize];
    zeroArr = new int[zeroSize];
    int p = 0, n = 0, z = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) posArr[p++] = arr[i];
        else if (arr[i] < 0) negArr[n++] = arr[i];
        else zeroArr[z++] = arr[i];
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(0));

    int sizeA, capacityA, sizeB, capacityB;
    int* A = nullptr;
    int* B = nullptr;

    cout << "Введіть розмір масиву A: ";
    cin >> sizeA;
    A = createArray(sizeA, capacityA, sizeA);
    cout << "Введіть розмір масиву B: ";
    cin >> sizeB;
    B = createArray(sizeB, capacityB, sizeB);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Видалити елемент за індексом\n";
        cout << "2. Створити масив із від’ємних чисел\n";
        cout << "3. Об’єднати два масиви\n";
        cout << "4. Знайти спільні елементи\n";
        cout << "5. Елементи A, які не входять до B\n";
        cout << "6. Некомбіновані елементи A і B\n";
        cout << "7. Додати блок елементів у кінець\n";
        cout << "8. Вставити блок елементів за індексом\n";
        cout << "9. Видалити блок елементів\n";
        cout << "10. Видалити прості числа\n";
        cout << "11. Розподіл на додатні, від’ємні, нульові\n";
        cout << "12. Вихід\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            cout << "Введіть індекс для видалення з масиву A: ";
            cin >> index;
            A = removeElementAtIndex(A, sizeA, capacityA, index);
            printArray(A, sizeA);
            break;
        }
        case 2: {
            int negSize;
            int* negArr = getNegativeNumbers(A, sizeA, negSize);
            cout << "Масив від’ємних чисел: ";
            printArray(negArr, negSize);
            delete[] negArr;
            break;
        }
        case 3: {
            int mergedSize;
            int* merged = mergeArrays(A, sizeA, B, sizeB, mergedSize);
            printArray(merged, mergedSize);
            delete[] merged;
            break;
        }
        case 4: {
            int commonSize;
            int* common = getCommonElements(A, sizeA, B, sizeB, commonSize);
            printArray(common, commonSize);
            delete[] common;
            break;
        }
        case 5: {
            int uniqueSize;
            int* unique = getUniqueElementsA(A, sizeA, B, sizeB, uniqueSize);
            printArray(unique, uniqueSize);
            delete[] unique;
            break;
        }
        case 6: {
            int nonCommonSize;
            int* nonCommon = getNonCommonElements(A, sizeA, B, sizeB, nonCommonSize);
            printArray(nonCommon, nonCommonSize);
            delete[] nonCommon;
            break;
        }
        case 7: {
            int blockSize;
            cout << "Введіть розмір блоку для додавання: ";
            cin >> blockSize;
            int* block = new int[blockSize];
            cout << "Введіть " << blockSize << " елементів блоку:\n";
            for (int i = 0; i < blockSize; i++) {
                cin >> block[i];
            }
            appendBlock(A, sizeA, capacityA, block, blockSize);
            printArray(A, sizeA);
            delete[] block;
            break;
        }
        case 8: {
            int blockSize, index;
            cout << "Введіть індекс для вставки: ";
            cin >> index;
            cout << "Введіть розмір блоку: ";
            cin >> blockSize;
            int* block = new int[blockSize];
            cout << "Введіть " << blockSize << " елементів блоку:\n";
            for (int i = 0; i < blockSize; i++) {
                cin >> block[i];
            }
            insertBlock(A, sizeA, capacityA, index, block, blockSize);
            printArray(A, sizeA);
            delete[] block;
            break;
        }
        case 9: {
            int index, blockSize;
            cout << "Введіть індекс початку блоку: ";
            cin >> index;
            cout << "Введіть розмір блоку для видалення: ";
            cin >> blockSize;
            removeBlock(A, sizeA, capacityA, index, blockSize);
            printArray(A, sizeA);
            break;
        }
        case 10: {
            int newSize;
            int* newArr = removePrimes(A, sizeA, newSize);
            printArray(newArr, newSize);
            delete[] A;
            A = newArr;
            sizeA = newSize;
            capacityA = newSize;
            break;
        }
        case 11: {
            int posSize, negSize, zeroSize;
            int *posArr, *negArr, *zeroArr;
            distributeArray(A, sizeA, posArr, posSize, negArr, negSize, zeroArr, zeroSize);
            cout << "Додатні: ";
            printArray(posArr, posSize);
            cout << "Від’ємні: ";
            printArray(negArr, negSize);
            cout << "Нульові: ";
            printArray(zeroArr, zeroSize);
            delete[] posArr;
            delete[] negArr;
            delete[] zeroArr;
            break;
        }
        case 12:
            cout << "Програма завершена.\n";
            delete[] A;
            delete[] B;
            return 0;
        default:
            cout << "Некоректний вибір!\n";
        }
    } while (true);

    return 0;
}
