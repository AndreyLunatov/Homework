#include <iostream>
using namespace std;

// Завдання 1: Видалення символу за номером
void deleteCharAtIndex(char* str, int index) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (index < 0 || index >= len) {
        cout << "Неправильний індекс!" << endl;
        return;
    }
    for (int i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
}

// Завдання 2: Видалення всіх входжень заданого символу
void deleteAllChars(char* str, char ch) {
    int len = 0, j = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len; i++) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Завдання 3: Вставка символу у вказану позицію
void insertCharAtIndex(char* str, int index, char ch) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (index < 0 || index > len) {
        cout << "Неправильний індекс!" << endl;
        return;
    }
    for (int i = len; i >= index; i--) {
        str[i + 1] = str[i];
    }
    str[index] = ch;
    str[len + 1] = '\0';
}

// Завдання 4: Заміна крапок на знаки оклику
void replaceDotsWithExclamations(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}

// Завдання 5: Підрахунок входжень символу
int countCharOccurrences(char* str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) count++;
    }
    return count;
}

// Завдання 6: Підрахунок літер, цифр та інших символів
void countCharacters(char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            letters++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else {
            others++;
        }
    }
}

// Завдання 7: Бібліотека функцій

int mystrcmp(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    if (*str1 == *str2) return 0;
    return (*str1 > *str2) ? 1 : -1;
}


int StringToNumber(char* str) {
    int result = 0, sign = 1, i = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }
    return result * sign;
}


char* NumberToString(int number) {
    bool isNegative = number < 0;
    if (isNegative) number = -number;
    int temp = number, digits = 0;
    do {
        digits++;
        temp /= 10;
    } while (temp);
    char* result = new char[digits + isNegative + 1];
    int i = digits + isNegative - 1;
    result[digits + isNegative] = '\0';
    do {
        result[i--] = (number % 10) + '0';
        number /= 10;
    } while (number);
    if (isNegative) result[0] = '-';
    return result;
}

// Перетворення рядка у верхній регістр
char* Uppercase(char* str) {
    char* result = new char[100];
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            result[i] = str[i] - 32;
        } else {
            result[i] = str[i];
        }
        i++;
    }
    result[i] = '\0';
    return result;
}


char* Lowercase(char* str) {
    char* result = new char[100];
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            result[i] = str[i] + 32;
        } else {
            result[i] = str[i];
        }
        i++;
    }
    result[i] = '\0';
    return result;
}


char* mystrrev(char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    char* result = new char[len + 1];
    for (int i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

int main() {
    char str[100];
    cout << "Введіть рядок: ";
    cin.getline(str, 100);

    // Завдання 1
    int index;
    cout << "Введіть індекс для видалення символу: ";
    cin >> index;
    deleteCharAtIndex(str, index);
    cout << "Рядок після видалення символу: " << str << endl;

    // Завдання 2
    char ch;
    cout << "Введіть символ для видалення всіх входжень: ";
    cin >> ch;
    deleteAllChars(str, ch);
    cout << "Рядок після видалення всіх '" << ch << "': " << str << endl;

    // Завдання 3
    cout << "Введіть індекс для вставки символу: ";
    cin >> index;
    cout << "Введіть символ для вставки: ";
    cin >> ch;
    insertCharAtIndex(str, index, ch);
    cout << "Рядок після вставки символу: " << str << endl;

    // Завдання 4
    replaceDotsWithExclamations(str);
    cout << "Рядок після заміни крапок на '!': " << str << endl;

    // Завдання 5
    cout << "Введіть шуканий символ: ";
    cin >> ch;
    cout << "Символ '" << ch << "' зустрічається " << countCharOccurrences(str, ch) << " разів" << endl;

    // Завдання 6
    int letters, digits, others;
    countCharacters(str, letters, digits, others);
    cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших символів: " << others << endl;

    // Завдання 7
    char str2[100];
    cout << "Введіть другий рядок для порівняння: ";
    cin.ignore();
    cin.getline(str2, 100);
    cout << "Порівняння рядків: " << mystrcmp(str, str2) << endl;

    cout << "Введіть рядок для конвертації в число: ";
    cin.getline(str2, 100);
    cout << "Число: " << StringToNumber(str2) << endl;

    int number;
    cout << "Введіть число для конвертації в рядок: ";
    cin >> number;
    char* numStr = NumberToString(number);
    cout << "Рядок: " << numStr << endl;

    char* upperStr = Uppercase(str);
    cout << "Рядок у верхньому регістрі: " << upperStr << endl;

    char* lowerStr = Lowercase(str);
    cout << "Рядок у нижньому регістрі: " << lowerStr << endl;

    char* revStr = mystrrev(str);
    cout << "Реверсований рядок: " << revStr << endl;

    delete[] numStr;
    delete[] upperStr;
    delete[] lowerStr;
    delete[] revStr;

    return 0;
}
