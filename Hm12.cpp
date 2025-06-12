#include <iostream>
using namespace std;

// Функція для виведення масиву
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Завдання 1: Видалення елемента за індексом
int* deleteElement(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Неправильний індекс!" << endl;
        return arr;
    }
    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArr[j++] = arr[i];
        }
    }
    delete[] arr;
    size--;
    return newArr;
}

// Завдання 2: Створення масиву з від'ємних чисел
int* getNegativeNumbers(int* arr, int size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) newSize++;
    }
    int* negArr = new int[newSize];
    for (int i = 0, j = 0; i < size; i++) {
        if (arr[i] < 0) negArr[j++] = arr[i];
    }
    return negArr;
}

// Завдання 3: Додавання блоку елементів у кінець
int* addBlockToEnd(int* arr, int& size, int* block, int blockSize) {
    int* newArr = new int[size + blockSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        newArr[size + i] = block[i];
    }
    delete[] arr;
    size += blockSize;
    return newArr;
}

// Завдання 4: Вставка блоку елементів за індексом
int* insertBlockAtIndex(int* arr, int& size, int* block, int blockSize, int index) {
    if (index < 0 || index > size) {
        cout << "Неправильний індекс!" << endl;
        return arr;
    }
    int* newArr = new int[size + blockSize];
    for (int i = 0, j = 0; i < size + blockSize; i++) {
        if (i >= index && i < index + blockSize) {
            newArr[i] = block[i - index];
        } else {
            newArr[i] = arr[j++];
        }
    }
    delete[] arr;
    size += blockSize;
    return newArr;
}

// Завдання 5: Видалення блоку елементів за індексом
int* deleteBlockAtIndex(int* arr, int& size, int index, int blockSize) {
    if (index < 0 || index >= size || blockSize > size - index) {
        cout << "Неправильний індекс або розмір блоку!" << endl;
        return arr;
    }
    int* newArr = new int[size - blockSize];
    for (int i = 0, j = 0; i < size; i++) {
        if (i < index || i >= index + blockSize) {
            newArr[j++] = arr[i];
        }
    }
    delete[] arr;
    size -= blockSize;
    return newArr;
}

int main() {
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Завдання 1
    int index;
    cout << "Введіть індекс для видалення: ";
    cin >> index;
    arr = deleteElement(arr, size, index);
    cout << "Масив після видалення: ";
    printArray(arr, size);

    // Завдання 2
    int negSize;
    int* negArr = getNegativeNumbers(arr, size, negSize);
    cout << "Масив від'ємних чисел: ";
    printArray(negArr, negSize);

    // Завдання 3
    int blockSize;
    cout << "Введіть розмір блоку для додавання: ";
    cin >> blockSize;
    int* block = new int[blockSize];
    cout << "Введіть елементи блоку: ";
    for (int i = 0; i < blockSize; i++) {
        cin >> block[i];
    }
    arr = addBlockToEnd(arr, size, block, blockSize);
    cout << "Масив після додавання блоку: ";
    printArray(arr, size);

    // Завдання 4
    cout << "Введіть індекс для вставки блоку: ";
    cin >> index;
    cout << "Введіть розмір нового блоку: ";
    cin >> blockSize;
    int* newBlock = new int[blockSize];
    cout << "Введіть елементи нового блоку: ";
    for (int i = 0; i < blockSize; i++) {
        cin >> newBlock[i];
    }
    arr = insertBlockAtIndex(arr, size, newBlock, blockSize, index);
    cout << "Масив після вставки блоку: ";
    printArray(arr, size);

    // Завдання 5
    cout << "Введіть індекс для видалення блоку: ";
    cin >> index;
    cout << "Введіть розмір блоку для видалення: ";
    cin >> blockSize;
    arr = deleteBlockAtIndex(arr, size, index, blockSize);
    cout << "Масив після видалення блоку: ";
    printArray(arr, size);

    // Очищення пам'яті
    delete[] arr;
    delete[] negArr;
    delete[] block;
    delete[] newBlock;

    return 0;
}
