#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 9;

void printGrid(int** grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0)
                cout << "  "; 
            else
                cout << grid[i][j] << " ";
            if (j % 3 == 2 && j < N - 1) cout << "| ";
        }
        cout << endl;
        if (i % 3 == 2 && i < N - 1) {
            for (int k = 0; k < N + 2; k++) cout << "- ";
            cout << endl;
        }
    }
}


bool isSafe(int** grid, int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}


bool findUnassignedLocation(int** grid, int& row, int& col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}


bool solveSudoku(int** grid) {
    int row, col;
    if (!findUnassignedLocation(grid, row, col))
        return true; 

    
    int num[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(num[i], num[j]);
    }

    for (int i = 0; i < 9; i++) {
        if (isSafe(grid, row, col, num[i])) {
            grid[row][col] = num[i];
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0; 
        }
    }
    return false;
}


void fillGrid(int** grid) {
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 0;

 
    srand(time(0));

    
    solveSudoku(grid);

    
    int cellsToRemove = 40;
    while (cellsToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            cellsToRemove--;
        }
    }
}

bool isGridFull(int** grid) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 0)
                return false;
    return true;
}

int main() {
    setlocale(LC_ALL, "ukr");

   
    int** grid = new int* [N];
    for (int i = 0; i < N; i++)
        grid[i] = new int[N];

 
    fillGrid(grid);

    cout << "Судоку: введите числа в пустые клетки\n";
    printGrid(grid);


    while (!isGridFull(grid)) {
        int row, col, num;
        cout << "\nВведите строку (0-8), столбец (0-8) и число (1-9): ";
        cin >> row >> col >> num;

        if (row < 0 || row >= N || col < 0 || col >= N || num < 1 || num > 9) {
            cout << "Некорректный ввод! Попробуйте снова.\n";
            continue;
        }

        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            cout << "\nОбновленная сетка:\n";
            printGrid(grid);
        }
        else {
            cout << "Число " << num << " нельзя поставить в (" << row << "," << col << ")!\n";
        }
    }

    cout << "\nПоздравляем! Судоку решено!\n";

    
    for (int i = 0; i < N; i++)
        delete[] grid[i];
    delete[] grid;

    return 0;
}
