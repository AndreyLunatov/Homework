
//film.h
#include <iostream>
using namespace std;


struct Film {
    char* title;     // Динамічне поле: назва фільму
    char* director;  // Динамічне поле: режисер
    char* genre;     // Динамічне поле: жанр
    int year;        // Статичне поле: рік випуску
    float rating;    // Статичне поле: рейтинг
};


void addFilm(Film*& films, int& size, int& capacity);
void showAllFilms(const Film* films, int size);
void showFilmByIndex(const Film* films, int size, int index);
void deleteAllFilms(Film*& films, int& size, int& capacity);
void deleteFilmByIndex(Film*& films, int& size, int index);
void searchFilms(const Film* films, int size);
void freeFilms(Film*& films, int& size, int& capacity);





//main Film
#include "film.h"


char* copyString(const char* src) {
    int len = 0;
    while (src[len] != '\0') len++;
    char* dest = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}


void addFilm(Film*& films, int& size, int& capacity) {
    if (size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        Film* newFilms = new Film[capacity];
        for (int i = 0; i < size; i++) {
            newFilms[i] = films[i];
        }
        delete[] films;
        films = newFilms;
    }

    Film newFilm;
    char buffer[100];

    cout << "Enter film title: ";
    cin.ignore();
    cin.getline(buffer, 100);
    newFilm.title = copyString(buffer);

    cout << "Enter film director: ";
    cin.getline(buffer, 100);
    newFilm.director = copyString(buffer);

    cout << "Enter film genre: ";
    cin.getline(buffer, 100);
    newFilm.genre = copyString(buffer);

    cout << "Enter film year: ";
    cin >> newFilm.year;

    cout << "Enter film rating: ";
    cin >> newFilm.rating;

    films[size] = newFilm;
    size++;
}


void showAllFilms(const Film* films, int size) {
    if (size == 0) {
        cout << "No films available." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "Film " << i + 1 << ":\n";
        cout << "Title: " << films[i].title << endl;
        cout << "Director: " << films[i].director << endl;
        cout << "Genre: " << films[i].genre << endl;
        cout << "Year: " << films[i].year << endl;
        cout << "Rating: " << films[i].rating << endl;
        cout << "------------------------" << endl;
    }
}

// Виведення фільму за індексом
void showFilmByIndex(const Film* films, int size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Film " << index + 1 << ":\n";
    cout << "Title: " << films[index].title << endl;
    cout << "Director: " << films[index].director << endl;
    cout << "Genre: " << films[index].genre << endl;
    cout << "Year: " << films[index].year << endl;
    cout << "Rating: " << films[index].rating << endl;
}

// Видалення всіх фільмів
void deleteAllFilms(Film*& films, int& size, int& capacity) {
    for (int i = 0; i < size; i++) {
        delete[] films[i].title;
        delete[] films[i].director;
        delete[] films[i].genre;
    }
    delete[] films;
    films = nullptr;
    size = 0;
    capacity = 0;
    cout << "All films deleted." << endl;
}

// Видалення фільму за індексом
void deleteFilmByIndex(Film*& films, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    delete[] films[index].title;
    delete[] films[index].director;
    delete[] films[index].genre;

    for (int i = index; i < size - 1; i++) {
        films[i] = films[i + 1];
    }
    size--;
    cout << "Film at index " << index + 1 << " deleted." << endl;
}

// Пошук фільмів за режисером або роком
void searchFilms(const Film* films, int size) {
    char director[100];
    int year;
    cout << "Enter director name to search (or press Enter to skip): ";
    cin.ignore();
    cin.getline(director, 100);
    cout << "Enter year to search (or enter 0 to skip): ";
    cin >> year;

    bool found = false;
    for (int i = 0; i < size; i++) {
        bool match = false;
        if (director[0] != '\0') {
            int j = 0;
            while (director[j] == films[i].director[j] && director[j] != '\0') j++;
            if (director[j] == '\0' && films[i].director[j] == '\0') match = true;
        }
        if (year != 0 && films[i].year == year) match = true;
        if (match) {
            cout << "Film " << i + 1 << ":\n";
            cout << "Title: " << films[i].title << endl;
            cout << "Director: " << films[i].director << endl;
            cout << "Genre: " << films[i].genre << endl;
            cout << "Year: " << films[i].year << endl;
            cout << "Rating: " << films[i].rating << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No films found matching the criteria." << endl;
}

// Очищення всіх ресурсів
void freeFilms(Film*& films, int& size, int& capacity) {
    deleteAllFilms(films, size, capacity);
}

int main() {
    Film* films = nullptr;
    int size = 0, capacity = 0;
    int choice;

    do {
        cout << "\nFilm Library Menu:\n";
        cout << "1. Add a new film\n";
        cout << "2. Show all films\n";
        cout << "3. Show film by index\n";
        cout << "4. Delete all films\n";
        cout << "5. Delete film by index\n";
        cout << "6. Search films\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFilm(films, size, capacity);
                break;
            case 2:
                showAllFilms(films, size);
                break;
            case 3: {
                int index;
                cout << "Enter film index: ";
                cin >> index;
                showFilmByIndex(films, size, index - 1);
                break;
            }
            case 4:
                deleteAllFilms(films, size, capacity);
                break;
            case 5: {
                int index;
                cout << "Enter film index: ";
                cin >> index;
                deleteFilmByIndex(films, size, index - 1);
                break;
            }
            case 6:
                searchFilms(films, size);
                break;
            case 7:
                freeFilms(films, size, capacity);
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
