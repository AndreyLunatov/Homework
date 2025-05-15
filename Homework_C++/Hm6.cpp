#include <iostream>
using namespace std;

// 1. Обчислення квадрата числа
int square(int num) {
    return num * num;
}

// 2. Перевірка парності
bool isEven(int num) {
    return num % 2 == 0;
}

// 3. Максимум із двох чисел
int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

// 4. Сума чисел від 1 до n
int sumToN(int n) {
    if (n <= 0) return 0;
    return (n * (n + 1)) / 2; // Формула суми арифметичної прогресії
}

// 5. Факторіал
unsigned long long factorial(int n) {
    if (n < 0) return 0; // Для негативних чисел повертаємо 0
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 6. Перевірка простого числа
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// 7. Сума цифр числа
int sumOfDigits(int num) {
    int sum = 0;
    num = abs(num); // Для роботи з негативними числами
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// 8. Реверс числа
int reverseNumber(int num) {
    int reversed = 0;
    bool isNegative = num < 0;
    num = abs(num); // Працюємо з абсолютним значенням
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return isNegative ? -reversed : reversed;
}

// 9. Переведення в двійкову систему
string toBinary(int num) {
    if (num == 0) return "0";
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary;
}

// 10. Обчислення степеня
long long power(int base, int exp) {
    if (exp < 0) return 0; // Не обробляємо від'ємні степені
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// 11. Числа Фібоначчі
long long fibonacci(int n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long prev = 0, curr = 1;
    for (int i = 2; i <= helpless; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// 12. Сума елементів масиву
int arraySum(int arr[], int size) {
    if (size <= 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Функція для тестування всіх функцій
int main() {
    // 1. Тест квадрата числа
    cout << "square(5): " << square(5) << endl; // 25

    // 2. Тест парності
    cout << "isEven(4): " << isEven(4) << endl; // 1 (true)
    cout << "isEven(7): " << isEven(7) << endl; // 0 (false)

    // 3. Тест максимуму
    cout << "maxOfTwo(3, 8): " << maxOfTwo(3, 8) << endl; // 8

    // 4. Тест суми до n
    cout << "sumToN(5): " << sumToN(5) << endl; // 15

    // 5. Тест факторіалу
    cout << "factorial(5): " << factorial(5) << endl; // 120

    // 6. Тест простого числа
    cout << "isPrime(7): " << isPrime(7) << endl; // 1 (true)
    cout << "isPrime(4): " << isPrime(4) << endl; // 0 (false)

    // 7. Тест суми цифр
    cout << "sumOfDigits(123): " << sumOfDigits(123) << endl; // 6

    // 8. Тест реверсу числа
    cout << "reverseNumber(123): " << reverseNumber(123) << endl; // 321

    // 9. Тест двійкової системи
    cout << "toBinary(10): " << toBinary(10) << endl; // 1010

    // 10. Тест степеня
    cout << "power(2, 3): " << power(2, 3) << endl; // 8

    // 11. Тест Фібоначчі
    cout << "fibonacci(6): " << fibonacci(6) << endl; // 8

    // 12. Тест суми масиву
    int arr[] = {1, 2, 3, 4};
    cout << "arraySum({1, 2, 3, 4}, 4): " << arraySum(arr, 4) << endl; // 10

    return 0;
}
