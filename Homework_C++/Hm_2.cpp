#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    // 1. Розв’язання системи рівнянь
    double a, b, X;
    cout << "Введіть a і b: ";
    cin >> a >> b;
    if (a > b) X = b - 5 * a;
    else if (a == b) X = (5 - b) / a;
    else X = (a - 5) / b;
    cout << "Результат X = " << X << endl;

    // 2. Перевірка паралельності осі координат
    double x1, y1, x2, y2;
    cout << "Введіть координати двох точок (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) cout << "Пряма паралельна осі ординат" << endl;
    else if (y1 == y2) cout << "Пряма паралельна осі абсцис" << endl;
    else cout << "Пряма не паралельна осям координат" << endl;

    // 3. Розрахунок знижки
    int quantity;
    double price, discount = 0, total;
    cout << "Введіть кількість товару та ціну за штуку: ";
    cin >> quantity >> price;
    total = quantity * price;
    if (total >= 300) discount = 0.07;
    else if (total >= 200) discount = 0.05;
    else if (total >= 100) discount = 0.03;
    cout << "Сума знижки: " << total * discount << endl;

    // 4. Перевірка на наявність десяткової частини
    double num;
    cout << "Введіть дробове число: ";
    cin >> num;
    if (num == (int)num) cout << "Число не має десяткової частини." << endl;
    else cout << "Число має десяткову частину." << endl;

    // 5. День тижня
    int day;
    cout << "Введіть номер дня тижня (1-7): ";
    cin >> day;
    switch(day) {
        case 1: cout << "Понеділок"; break;
        case 2: cout << "Вівторок"; break;
        case 3: cout << "Середа"; break;
        case 4: cout << "Четвер"; break;
        case 5: cout << "П’ятниця"; break;
        case 6: cout << "Субота"; break;
        case 7: cout << "Неділя"; break;
        default: cout << "Невірний номер дня";
    }
    cout << endl;

    // 6. Визначення чверті
    double x, y;
    cout << "Введіть координати точки (x y): ";
    cin >> x >> y;
    if (x > 0 && y > 0) cout << "Перша чверть" << endl;
    else if (x < 0 && y > 0) cout << "Друга чверть" << endl;
    else if (x < 0 && y < 0) cout << "Третя чверть" << endl;
    else if (x > 0 && y < 0) cout << "Четверта чверть" << endl;
    else if (x == 0 && y == 0) cout << "Початок координат" << endl;
    else if (x == 0) cout << "На осі Y" << endl;
    else if (y == 0) cout << "На осі X" << endl;

    // 7. Конвертація валюти
    double uah;
    int currency;
    cout << "Введіть суму у гривнях: ";
    cin >> uah;
    cout << "Оберіть валюту (1 - євро, 2 - долар, 3 - рубль): ";
    cin >> currency;
    switch(currency) {
        case 1: cout << "У євро: " << uah / 39.0 << endl; break;
        case 2: cout << "У доларах: " << uah / 36.0 << endl; break;
        case 3: cout << "У рублях: " << uah * 2.5 << endl; break;
        default: cout << "Невірний вибір валюти" << endl;
    }

    // 8. Перевірка дати та часу
    int d, m, y_, h, min;
    cout << "Введіть день, місяць, рік, години та хвилини: ";
    cin >> d >> m >> y_ >> h >> min;
    if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && h >= 0 && h <= 23 && min >= 0 && min <= 59)
        cout << "Дата і час коректні." << endl;
    else cout << "Помилка у введенні." << endl;

    // 9. Щасливий квиток
    string ticket;
    cout << "Введіть номер квитка (6 цифр): ";
    cin >> ticket;
    if (ticket.length() == 6 && isdigit(ticket[0])) {
        int sum1 = ticket[0] + ticket[1] + ticket[2];
        int sum2 = ticket[3] + ticket[4] + ticket[5];
        if (sum1 == sum2) cout << "Щасливий квиток!" << endl;
        else cout << "Звичайний квиток." << endl;
    } else cout << "Некоректний номер квитка." << endl;

    // 10. Пенсійний вік
    int age;
    cout << "Введіть вік: ";
    cin >> age;
    if (age >= 60) cout << "Пора на пенсію." << endl;
    else cout << "Ще зарано на пенсію." << endl;

    // 11. Масть та гідність карти
    int card;
    cout << "Введіть номер карти (0-35): ";
    cin >> card;
    string suits[] = {"Піки", "Трефи", "Бубни", "Чирви"};
    string values[] = {"6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз"};
    if (card >= 0 && card <= 35) {
        cout << "Карта: " << values[card % 9] << " " << suits[card / 9] << endl;
    } else cout << "Некоректний номер карти." << endl;

    // 12. Вітання за часом
    int hour, minute;
    cout << "Введіть години та хвилини: ";
    cin >> hour >> minute;
    if (hour >= 5 && hour < 12) cout << "Доброго ранку!" << endl;
    else if (hour >= 12 && hour < 18) cout << "Добрий день!" << endl;
    else if (hour >= 18 && hour < 22) cout << "Добрий вечір!" << endl;
    else cout << "Доброї ночі!" << endl;

    // 13. Ідеальна вага
    double height, weight;
    cout << "Введіть зріст та вагу: ";
    cin >> height >> weight;
    double ideal = height - 110;
    if (weight > ideal) cout << "Треба скинути " << weight - ideal << " кг" << endl;
    else if (weight < ideal) cout << "Треба набрати " << ideal - weight << " кг" << endl;
    else cout << "Вага ідеальна!" << endl;

    // 14. Наступна дата
    int dd, mm, yy;
    cout << "Введіть дату (день місяць рік): ";
    cin >> dd >> mm >> yy;
    dd++;
    if ((mm == 2 && ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0)) && dd > 29) ||
        (mm == 2 && dd > 28)) { dd = 1; mm++; }
    else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) { dd = 1; mm++; }
    else if (dd > 31) { dd = 1; mm++; }
    if (mm > 12) { mm = 1; yy++; }
    cout << "Наступна дата: " << dd << "." << mm << "." << yy << endl;

    // 15. Прості цифри у числі
    int five_digit;
    cout << "Введіть п’ятизначне число: ";
    cin >> five_digit;
    string str = to_string(five_digit);
    bool all_prime = true;
    for (char c : str) {
        if (!(c == '2' || c == '3' || c == '5' || c == '7')) {
            all_prime = false;
            break;
        }
    }
    if (all_prime) cout << "Усі цифри є простими." << endl;
    else cout << "Є не прості цифри." << endl;

    return 0;
}
