#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
using namespace std;



void task1() {
    int totalSeconds;
    cout << "Введіть час у секундах: ";
    cin >> totalSeconds;
    int days = totalSeconds / 86400;
    int hours = (totalSeconds % 86400) / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;
    cout << days << " днів " << hours ______<< " годин " << minutes << " хвилин " << seconds << " секунд.\n";
}

void task2() {
    int d, h, m, s;
    cout << "Введіть дні, години, хвилини, секунди: ";
    cin >> d >> h >> m >> s;
    cout << "Загальна кількість секунд: " << (d * 86400 + h * 3600 + m * 60 + s) << endl;
}

void task3() {
    float dist, time;
    cout << "Введіть відстань (км) та час (години): ";
    cin >> dist >> time;
    cout << "Швидкість: " << fixed << setprecision(2) << dist / time << " км/год\n";
}

void task4() {
    int h1, m1, s1, h2, m2, s2;
    cout << "Введіть час початку та кінця розмови (год хв сек год хв сек): ";
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    int duration = t2 - t1;
    if (duration < 0) duration += 86400;
    cout << "Вартість: " << (duration / 60) * 30 << " копійок\n";
}

void task5() {
    float uah, usd, eur, rub;
    cout << "Введіть суму в грн та курси $ € ₽: ";
    cin >> uah >> usd >> eur >> rub;
    int u = uah / usd, e = uah / eur, r = uah / rub;
    float rest = uah - (u * usd + e * eur + r * rub);
    cout << "Можна купити: $" << u << " €" << e << " ₽" << r << ". Решта: " << rest << " грн.\n";
}

void task6() {
    int sec;
    cout << "Скільки секунд минуло з початку робочого дня: ";
    cin >> sec;
    int left = 28800 - sec;
    cout << "Залишилось: " << left / 3600 << " год " << (left % 3600) / 60 << " хв " << left % 60 << " сек\n";
}

void task7() {
    float price, discount;
    int qty;
    cout << "Введіть ціну, кількість та знижку (%): ";
    cin >> price >> qty >> discount;
    cout << "Загальна сума: " << fixed << setprecision(2) << price * qty * (1 - discount / 100) << " грн\n";
}

void task8() {
    float sales;
    cout << "Введіть суму угод: ";
    cin >> sales;
    cout << "Зарплата: $" << fixed << setprecision(2) << (100 + sales * 0.05) << endl;
}

void task9() {
    float size, speed;
    cout << "Введіть розмір фільму (ГБ) та швидкість (біт/с): ";
    cin >> size >> speed;
    float time = size * 8 * 1024 * 1024 * 1024 / speed;
    cout << "Час завантаження: " << int(time / 3600) << " год " << int(time / 60) % 60 << " хв " << int(time) % 60 << " сек\n";
}

void task10() {
    int flash;
    cout << "Введіть розмір флешки (ГБ): ";
    cin >> flash;
    cout << "Фільмів поміститься: " << flash * 1024 / 760 << endl;
}

void task11() {
    float num;
    cout << "Введіть число: ";
    cin >> num;
    cout << "Округлене: " << fixed << setprecision(2) << num << endl;
}

void task12() {
    int p, f;
    cout << "Введіть кількість студентів, які склали та не склали: ";
    cin >> p >> f;
    int total = p + f;
    cout << "Склали: " << fixed << setprecision(2) << float(p) / total * 100 << "%\n";
    cout << "Не склали: " << float(f) / total * 100 << "%\n";
}

void task13() {
    int passed;
    cout << "Введіть кількість секунд, що пройшли від початку дня: ";
    cin >> passed;
    int left = 86400 - passed;
    cout << "До опівночі: " << left / 3600 << " год " << (left % 3600) / 60 << " хв " << left % 60 << " сек\n";
}

void task14() {
    float size;
    cout << "Введіть розмір фільму (ГБ): ";
    cin >> size;
    cout << "Потрібно дискет: " << ceil(size * 1024 / 1.44) << endl;
}

void task15() {
    float sum, rate;
    int months;
    cout << "Введіть суму, термін (міс) та річну % ставку: ";
    cin >> sum >> months >> rate;
    cout << "Підсумкова сума: " << fixed << setprecision(2) << sum * (1 + rate / 100 * (months / 12.0)) << " грн\n";
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    int choice;
    do {
        cout << "\nОберіть завдання (1–15, 0 – вихід): ";
        cin >> choice;
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            case 11: task11(); break;
            case 12: task12(); break;
            case 13: task13(); break;
            case 14: task14(); break;
            case 15: task15(); break;
            case 0: cout << "Вихід з програми.\n"; break;
            default: cout << "Невірний номер завдання.\n";
        }
    } while (choice != 0);
    return 0;
}
