#include <iostream>
using namespace std;

struct Film {
    char name[50];
    char date[50];
};

void inputAndWriteFilms() {
    Film films[2];
    for (int i = 0; i < 2; i++) {
        cin >> films[i].name;
        cin >> films[i].date;
    }
    ofstream file("films.dat", ios::binary);
    file.write((char*)films, sizeof(films));
    file.close();
}

void readAndOutputFilms() {
    Film films[2];
    ifstream file("films.dat", ios::binary);
    file.read((char*)films, sizeof(films));
    ofstream out("Films.txt");
    for (int i = 0; i < 2; i++) {
        cout << "------ FILM " << i + 1 << " ------" << endl;
        cout << "Name: " << films[i].name << endl;
        cout << "Date: " << films[i].date << endl;
        cout << "--------------------" << endl;
        out << "------ FILM " << i + 1 << " ------" << endl;
        out << "Name: " << films[i].name << endl;
        out << "Date: " << films[i].date << endl;
        out << "--------------------" << endl;
    }
    file.close();
    out.close();
}

int main() {
    inputAndWriteFilms();
    readAndOutputFilms();
    return 0;
}
