
#include <clocale>
#include <iostream>
using namespace std;


struct Student {
    string name;
    string surname;
    string group;
    int marks[100]; 
    int markCount;  
};


Student students[100];
int studentCount = 0;


void addStudent(string name, string surname, string group) {
    if (studentCount < 100) {
        students[studentCount].name = name;
        students[studentCount].surname = surname;
        students[studentCount].group = group;
        students[studentCount].markCount = 0;
        studentCount++;
    } else {
        cout << "Неможливо додати студента: масив повний" << endl;
    }
}


void removeStudent(int index) {
    if (index >= 0 && index < studentCount) {
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
    } else {
        cout << "Неправильний індекс студента" << endl;
    }
}


void updateStudentInfo(int index, string name, string surname, string group) {
    if (index >= 0 && index < studentCount) {
        students[index].name = name;
        students[index].surname = surname;
        students[index].group = group;
    } else {
        cout << "Неправильний індекс студента" << endl;
    }
}


void addMark(int studentIndex, int mark) {
    if (studentIndex >= 0 && studentIndex < studentCount) {
        if (mark >= 0 && mark <= 100 && students[studentIndex].markCount < 100) {
            students[studentIndex].marks[students[studentIndex].markCount] = mark;
            students[studentIndex].markCount++;
        } else {
            cout << "Неправильна оцінка або масив оцінок повний" << endl;
        }
    } else {
        cout << "Неправильний індекс студента" << endl;
    }
}


void removeMark(int studentIndex, int markIndex) {
    if (studentIndex >= 0 && studentIndex < studentCount) {
        if (markIndex >= 0 && markIndex < students[studentIndex].markCount) {
            for (int i = markIndex; i < students[studentIndex].markCount - 1; i++) {
                students[studentIndex].marks[i] = students[studentIndex].marks[i + 1];
            }
            students[studentIndex].markCount--;
        } else {
            cout << "Неправильний індекс оцінки" << endl;
        }
    } else {
        cout << "Неправильний індекс студента" << endl;
    }
}


void updateMark(int studentIndex, int markIndex, int newMark) {
    if (studentIndex >= 0 && studentIndex < studentCount) {
        if (markIndex >= 0 && markIndex < students[studentIndex].markCount && newMark >= 0 && newMark <= 100) {
            students[studentIndex].marks[markIndex] = newMark;
        } else {
            cout << "Неправильний індекс оцінки або неправильна оцінка" << endl;
        }
    } else {
        cout << "Неправильний індекс студента" << endl;
    }
}


void printStudent(int index) {
    if (index >= 0 && index < studentCount) {
        cout << "Ім'я: " << students[index].name << endl;
        cout << "Прізвище: " << students[index].surname << endl;
        cout << "Група: " << students[index].group << endl;
        cout << "Оцінки: ";
        for (int i = 0; i < students[index].markCount; i++) {
            cout << students[index].marks[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Неправильний індекс студента" << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ukr");
 
    addStudent("Іван", "Петров", "КН-101");
    addStudent("Марія", "Сидорова", "КН-102");


    addMark(0, 85);
    addMark(0, 90);
    addMark(1, 95);


    cout << "Інформація про студентів:" << endl;
    printStudent(0);
    printStudent(1);


    updateStudentInfo(0, "Іван", "Іванов", "КН-103");

   
    updateMark(0, 0, 88);

   
    removeMark(0, 1);

    
    cout << "\nОновлена інформація про першого студента:" << endl;
    printStudent(0);

    
    removeStudent(1);

   
    cout << "\nІнформація після видалення другого студента:" << endl;
    printStudent(0);
    printStudent(1); // Повинно вивести помилку

    return 0;
}
