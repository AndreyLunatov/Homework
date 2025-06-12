#include <iostream>
using namespace std;

// Завдання 1: Структура Point
struct Point {
    int x, y;
};

void workWithPoint() {
    Point p;
    p.x = 5;
    p.y = 10;
    cout << "Point coordinates: (" << p.x << ", " << p.y << ")" << endl;
}

// Завдання 2: Структура Student
struct Student {
    char name[50];
    int age;
    float averageGrade;
};

void workWithStudent() {
    Student s;
    cout << "Enter student name: ";
    cin.getline(s.name, 50);
    cout << "Enter student age: ";
    cin >> s.age;
    cout << "Enter student average grade: ";
    cin >> s.averageGrade;
    cout << "Student info: Name = " << s.name << ", Age = " << s.age << ", Average Grade = " << s.averageGrade << endl;
}

// Завдання 3: Структура Rectangle
struct Rectangle {
    float width, height;
};

void workWithRectangle() {
    Rectangle r = {4.5, 3.2};
    float area = r.width * r.height;
    cout << "Rectangle area: " << area << endl;
}

// Завдання 4: Структура Time
struct Time {
    int hours, minutes, seconds;
};

void workWithTime() {
    Time t = {14, 30, 45};
    cout << "Time: ";
    if (t.hours < 10) cout << "0";
    cout << t.hours << ":";
    if (t.minutes < 10) cout << "0";
    cout << t.minutes << ":";
    if (t.seconds < 10) cout << "0";
    cout << t.seconds << endl;
}

// Завдання 5: Структура Car
struct Car {
    char brand[50];
    int year;
    float price;
};

void workWithCar() {
    Car c = {"Toyota", 2020, 25000.0};
    cout << "Car info: Brand = " << c.brand << ", Year = " << c.year << ", Price = " << c.price << endl;
}

// Завдання 6: Структура Date
struct Date {
    int day, month, year;
};

void workWithDate() {
    Date d = {12, 6, 2025};
    cout << "Date: ";
    if (d.day < 10) cout << "0";
    cout << d.day << ".";
    if (d.month < 10) cout << "0";
    cout << d.month << "." << d.year << endl;
}

// Завдання 7: Структура Person
struct Person {
    char name[50];
    int age;
    float height;
};

void workWithPerson() {
    Person p;
    cout << "Enter person name: ";
    cin.ignore(); // Очищення буфера після попереднього введення
    cin.getline(p.name, 50);
    cout << "Enter person age: ";
    cin >> p.age;
    cout << "Enter person height (in meters): ";
    cin >> p.height;
    cout << "Person info: Name = " << p.name << ", Age = " << p.age << ", Height = " << p.height << endl;
}

// Завдання 8: Структура Book
struct Book {
    char title[50];
    char author[50];
    int year;
};

void workWithBook() {
    Book b = {"The Hobbit", "J.R.R. Tolkien", 1937};
    cout << "Book info: Title = " << b.title << ", Author = " << b.author << ", Year = " << b.year << endl;
}

// Завдання 9: Структура Employee
struct Employee {
    char name[50];
    char position[50];
    float salary;
};

void workWithEmployee() {
    Employee e = {"John Doe", "Manager", 50000.0};
    cout << "Employee info: Name = " << e.name << ", Position = " << e.position << ", Salary = " << e.salary << endl;
}

// Завдання 10: Структура Triangle
struct Triangle {
    float side1, side2, side3;
};

void workWithTriangle() {
    Triangle t = {3, 4, 5};
    bool isTriangle = (t.side1 + t.side2 > t.side3) && 
                     (t.side2 + t.side3 > t.side1) && 
                     (t.side1 + t.side3 > t.side2);
    cout << "Can form a triangle: " << (isTriangle ? "Yes" : "No") << endl;
}

int main() {
    workWithPoint();
    workWithStudent();
    workWithRectangle();
    workWithTime();
    workWithCar();
    workWithDate();
    workWithPerson();
    workWithBook();
    workWithEmployee();
    workWithTriangle();
    return 0;
}
