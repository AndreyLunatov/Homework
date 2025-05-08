#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ukrainian");
    const int ROWS = 5;
    const int COLS = 5;
    int arr[ROWS][COLS];
    srand(time(0));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 21 - 10;
        }
    }

   
    cout << "Масив:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

  
    int col;
    cout << "\nВведи номер стовпця (0-" << COLS - 1 << "): ";
    cin >> col;
    int maxCol = arr[0][col];
    for (int i = 1; i < ROWS; i++) {
        if (arr[i][col] > maxCol) maxCol = arr[i][col];
    }
    cout << "Максимум у стовпці: " << maxCol << endl;

 
    int row;
    cout << "\nВведи номер рядка (0-" << ROWS - 1 << "): ";
    cin >> row;
    int maxRow = arr[row][0];
    for (int j = 1; j < COLS; j++) {
        if (arr[row][j] > maxRow) maxRow = arr[row][j];
    }
    cout << "Максимум у рядку: " << maxRow << endl;

    
    cout << "\nВведи номер стовпця: ";
    cin >> col;
    int sumNeg = 0, sumPos = 0, countPos = 0;
    for (int i = 0; i < ROWS; i++) {
        if (arr[i][col] < 0) sumNeg += arr[i][col];
        if (arr[i][col] > 0) {
            sumPos += arr[i][col];
            countPos++;
        }
    }
    cout << "Сума негативних: " << sumNeg << endl;
    if (countPos > 0)
        cout << "Середнє позитивних: " << (sumPos / countPos) << endl;
    else
        cout << "Позитивних немає\n";

  
    int c1, c2, temp;
    cout << "\nВведи два стовпці для обміну: ";
    cin >> c1 >> c2;
    for (int i = 0; i < ROWS; i++) {
        temp = arr[i][c1];
        arr[i][c1] = arr[i][c2];
        arr[i][c2] = temp;
    }

    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    
    int r1, r2;
    cout << "\nВведи два рядки для обміну: ";
    cin >> r1 >> r2;
    for (int j = 0; j < COLS; j++) {
        temp = arr[r1][j];
        arr[r1][j] = arr[r2][j];
        arr[r2][j] = temp;
    }

    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    
    cout << "\nВведи номер рядка для реверсу: ";
    cin >> row;
    for (int j = 0; j < COLS / 2; j++) {
        temp = arr[row][j];
        arr[row][j] = arr[row][COLS - 1 - j];
        arr[row][COLS - 1 - j] = temp;
    }

   
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
