//1. Сумма чисел от 0 до введённого пользователем

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU-UA");
    int n;
    do {
        cout << "Введите число (не меньше 1): ";
        cin >> n;
    } while (n < 1);

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }
    cout << "Сумма чисел от 0 до " << n << " = " << sum << endl;
    return 0;
}


//2. Факториал числа
#include <iostream>
using namespace std;

int main() {
     setlocale(LC_ALL, "RU-UA");
    int n;
    do {
        cout << "Введите число (не меньше 1): ";
        cin >> n;
    } while (n < 1);

    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    cout << n << "! = " << fact << endl;
    return 0;
}

//3. Таблица умножения
#include <iostream>
using namespace std;


int main() {
    setlocale(LC_ALL, "RU-UA");
    int n;
    do {
        cout << "Введите число (не меньше 1): ";
        cin >> n;
    } while (n < 1);

    for (int i = 1; i <= 10; ++i) {
        cout << n << " * " << i << " = " << n * i << endl << endl;
    }
    return 0;
}

//4. Горизонтальная линия с цветом(только Windows)
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU-UA");
    int width;
    do {
        cout << "Введите ширину линии (не меньше 1): ";
        cin >> width;
    } while (width < 1);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

    for (int i = 0; i < width; i++) {
        cout << " ";
    }
    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}

//5. Вертикальная линия с цветом(только Windows)
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU-UA");
    int height;
    do {
        cout << "Введите высоту линии (не меньше 1): ";
        cin >> height;
    } while (height < 1);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    for (int i = 0; i < height; i++) {
        cout << "|" << endl;
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
