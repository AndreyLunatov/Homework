
//1.Запитайте у користувача два числа, запишіть їх у змінні а та б,
//поміняйте місцями значення у цих змінних.
/*#include <iostream
using namespace std;

int main() {
    int a, b, op;
    

    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    
  op = a;
    a = b;
    b = op;
    
    cout << "After swapping: a = " << a << ", b = " << b << endl;
    return 0;
}
*/

//2.Запитайте у користувача число, порахуйте кількість цифр в ньому.
/*
 #include <iostream>
using namespace std;

int main() {
    int number, count = 0;

    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        number = -number;
    }


    if (number == 0) {
        count = 1;
    } else {

        while (number > 0) {
            number /= 10;
            count++;
        }
    }

    cout << "Number of digits: " << count << endl;

    return 0;
}
*/



//3.Користувач вводить з клавіатури кількість студентів, які склали іспит,
//та кількість «боржників». Обчислити, який відсоток становлять «боржники» від загальної кількості студентів,
//а також який відсоток становлять студенти, які склали іспит
/*
#include <iostream>
using namespace std;

int main() {
    int passed, failed, total;
    double passedPercent, failedPercent;

    cout << "Enter the number of students who passed the exam: ";
    cin >> passed;
    cout << "Enter the number of students who failed the exam: ";
    cin >> failed;

    total = passed + failed;
    passedPercent = (double)passed / total * 100;
    failedPercent = (double)failed / total * 100;

    cout << "Percentage of students who passed: " << passedPercent << "%" << endl;
    cout << "Percentage of students who failed: " << failedPercent << "%" << endl;

    return 0;
}
*/




//4.Створіть масив з 20 елементів, ініціалізуйте масив випадковими числами від 20 до 20
//а. Порахуйте кількість нульових елементів
//в. Порахуйте середнє значення негативних
//с. Знайдіть максимальне значення серед позитвних чисел.
/*
#include <iostream>
using namespace std;

int main() {
    int arr[20];
    int zeroCount = 0;
    int negativeCount = 0;
    double negativeSum = 0;
    int maxPositive = -21;

    int seed = 12345;
    for (int i = 0; i < 20; i++) {
        arr[i] = (seed * 1103515245 + 12345) % 41 - 20;
        seed = (seed * 1103515245 + 12345) & 0x7fffffff;
        cout << arr[i] << " ";

        if (arr[i] == 0) {
            zeroCount++;
        }
        if (arr[i] < 0) {
            negativeSum += arr[i];
            negativeCount++;
        }
        if (arr[i] > 0 && arr[i] > maxPositive) {
            maxPositive = arr[i];
        }
    }
    cout << endl;

    cout << "Number of zero elements: " << zeroCount << endl;

    if (negativeCount > 0) {
        cout << "Average of negative numbers: " << negativeSum / negativeCount << endl;
    } else {
        cout << "No negative numbers found" << endl;
    }

    if (maxPositive != -21) {
        cout << "Maximum positive number: " << maxPositive << endl;
    } else {
        cout << "No positive numbers found" << endl;
    }

    return 0;
}
*/



//5. Створіть двовимірний динамічний масив розміром 5х5:
//а. Визначіть в якому стовпчику сума елементів є максимальною
//в. Поміняйте місцями 3 та 4 рядок
//с. Зробіть реверс 5 рядку.
/*

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    int seed = 12345;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = (seed * 1103515245 + 12345) % 41 - 20;
            seed = (seed * 1103515245 + 12345) & 0x7fffffff;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int maxSum = -1000000, maxCol = 0;
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += arr[i][j];
        }
        if (colSum > maxSum) {
            maxSum = colSum;
            maxCol = j;
        }
    }
    cout << "Column with maximum sum: " << maxCol + 1 << ", Sum: " << maxSum << endl;

    for (int j = 0; j < n; j++) {
        int temp = arr[2][j];
        arr[2][j] = arr[3][j];
        arr[3][j] = temp;
    }

    cout << "Array after swapping rows 3 and 4:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int j = 0; j < n / 2; j++) {
        int temp = arr[4][j];
        arr[4][j] = arr[4][n - 1 - j];
        arr[4][n - 1 - j] = temp;
    }

    cout << "Array after reversing row 5:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

*/




//Створіть динамічний масив та реалізуйте наступні функції:
//а. Додавання нового елементу з будь-якої позиції
//В. Видалення елементу з будь-якої позиції
//с. Додавання блоку елементів у кінець масиву
/*
#include <iostream>
using namespace std;

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* addElement(int* arr, int& size, int element, int position) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < position; i++) {
        newArr[i] = arr[i];
    }
    newArr[position] = element;
    for (int i = position; i < size; i++) {
        newArr[i + 1] = arr[i];
    }
    size++;
    delete[] arr;
    return newArr;
}

int* removeElement(int* arr, int& size, int position) {
    if (size == 0 || position < 0 || position >= size) {
        return arr;
    }
    int* newArr = new int[size - 1];
    for (int i = 0; i < position; i++) {
        newArr[i] = arr[i];
    }
    for (int i = position + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    size--;
    delete[] arr;
    return newArr;
}

int* addBlock(int* arr, int& size, int* block, int blockSize) {
    int* newArr = new int[size + blockSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        newArr[size + i] = block[i];
    }
    size += blockSize;
    delete[] arr;
    return newArr;
}



int main() {
    int size = 5;
    int* arr = new int[size];
    int seed = 12345;
    for (int i = 0; i < size; i++) {
        arr[i] = (seed * 1103515245 + 12345) % 41 - 20;
        seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    }

    cout << "Initial array: ";
    printArray(arr, size);

    arr = addElement(arr, size, 100, 2);
    cout << "Array after adding 100 at position 2: ";
    printArray(arr, size);

    arr = removeElement(arr, size, 3);
    cout << "Array after removing element at position 3: ";
    printArray(arr, size);

    int block[] = {10, 20, 30};
    int blockSize = 3;
    arr = addBlock(arr, size, block, blockSize);
    cout << "Array after adding block [10, 20, 30] at the end: ";
    printArray(arr, size);

    delete[] arr;
    return 0;
}

*/



//7. Опишіть структуру автомобіль та реалізуйте наступні функції: (36)
//а. Вивести усі автомобілі
//b. Вивести конкретний автомобіль
//с. Створити новий автомобіль
//d. Записати автомобіль у текстовий файл
//е. Эчитати автомобіль з текстового файлу
/*
#include <iostream>
using namespace std;

struct Car {
    string brand;
    string model;
    int year;
    double price;
};

void printAllCars(Car* cars, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model
             << ", Year: " << cars[i].year << ", Price: $" << cars[i].price << endl;
    }
}

void printCar(Car* cars, int size, int index) {
    if (index >= 0 && index < size) {
        cout << "Car " << index + 1 << ": " << cars[index].brand << " " << cars[index].model
             << ", Year: " << cars[index].year << ", Price: $" << cars[index].price << endl;
    } else {
        cout << "Invalid car index" << endl;
    }
}

Car* addCar(Car* cars, int& size) {
    string brand, model;
    int year;
    double price;

    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter price: ";
    cin >> price;

    Car* newCars = new Car[size + 1];
    for (int i = 0; i < size; i++) {
        newCars[i] = cars[i];
    }
    newCars[size].brand = brand;
    newCars[size].model = model;
    newCars[size].year = year;
    newCars[size].price = price;
    size++;
    delete[] cars;
    return newCars;
}

int main() {
    int size = 0;
    Car* cars = new Car[size];
    char choice;

    do {
        cout << "\nOptions:" << endl;
        cout << "1. Add a new car" << endl;
        cout << "2. Print all cars" << endl;
        cout << "3. Print specific car (enter index)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cars = addCar(cars, size);
                cout << "Car added successfully!" << endl;
                break;
            case '2':
                if (size > 0) {
                    printAllCars(cars, size);
                } else {
                    cout << "No cars to display." << endl;
                }
                break;
            case '3':
                if (size > 0) {
                    int index;
                    cout << "Enter car index (1-" << size << "): ";
                    cin >> index;
                    printCar(cars, size, index - 1);
                } else {
                    cout << "No cars to display." << endl;
                }
                break;
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != '4');

    delete[] cars;
    return 0;
}
*/
