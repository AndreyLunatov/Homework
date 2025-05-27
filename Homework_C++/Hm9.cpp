#include <iostream>
using namespace std;


int* createArray(int& size, int& capacity, int initialCapacity) {
    capacity = (initialCapacity <= 0) ? 10 : initialCapacity;
    size = 0;
    return new int[capacity];
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


void addElement(int*& arr, int& size, int& capacity, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Некоректний індекс! Індекс повинен бути від 0 до " << size << endl;
        return;
    }

  
    if (size == capacity) {
        resize(arr, size, capacity);
    }

   
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

   
    arr[index] = value;
    size++;
}


void removeElement(int*& arr, int& size, int& capacity, int index) {
    if (index < 0 || index >= size) {
        cout << "Некоректний індекс! Індекс повинен бути від 0 до " << size - 1 << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    
    if (size < capacity / 2 && capacity > 10) {
        shrink(arr, size, capacity);
    }
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


void freeArray(int* arr) {
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "ukr");

   
    int initialCapacity;
    cout << "Введіть початкову місткість масиву (або 0 для значення за замовчуванням): ";
    cin >> initialCapacity;

    int size = 0;
    int capacity;
    int* arr = createArray(size, capacity, initialCapacity);

    int choice, index, value;
    do {
        cout << "\nМеню:\n";
        cout << "1. Додати елемент\n";
        cout << "2. Видалити елемент\n";
        cout << "3. Вивести масив\n";
        cout << "4. Вихід\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть індекс (0-" << size << ") та значення: ";
            cin >> index >> value;
            addElement(arr, size, capacity, index, value);
            break;
        case 2:
            cout << "Введіть індекс для видалення (0-" << size - 1 << "): ";
            cin >> index;
            removeElement(arr, size, capacity, index);
            break;
        case 3:
            printArray(arr, size);
            break;
        case 4:
            cout << "Програма завершена.\n";
            freeArray(arr);
            return 0;
        default:
            cout << "Некоректний вибір!\n";
        }
    } while (true);

    return 0;
}
