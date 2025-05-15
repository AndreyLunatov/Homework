#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}

int binarySearchHelper(int arr[], int size, int target) {
    return binarySearch(arr, 0, size - 1, target);
}

void shiftRowRight(int row[], int size, int shifts) {
    if (shifts == 0 || size <= 1) return;
    int temp = row[size - 1];
    for (int i = size - 1; i > 0; i--) {
        row[i] = row[i - 1];
    }
    row[0] = temp;
    shiftRowRight(row, size, shifts - 1);
}

void shift2DArrayRight(int** arr, int rows, int cols, int shifts, int currentRow = 0) {
    if (currentRow >= rows) return;
    shiftRowRight(arr[currentRow], cols, shifts % cols);
    shift2DArrayRight(arr, rows, cols, shifts, currentRow + 1);
}

void shiftRowLeft(int row[], int size, int shifts) {
    if (shifts == 0 || size <= 1) return;
    int temp = row[0];
    for (int i = 0; i < size - 1; i++) {
        row[i] = row[i + 1];
    }
    row[size - 1] = temp;
    shiftRowLeft(row, size, shifts - 1);
}

void shift2DArrayLeft(int** arr, int rows, int cols, int shifts, int currentRow = 0) {
    if (currentRow >= rows) return;
    shiftRowLeft(arr[currentRow], cols, shifts % cols);
    shift2DArrayLeft(arr, rows, cols, shifts, currentRow + 1);
}

template <typename T>
double arrayAverage(T arr[], int size) {
    if (size <= 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

template <typename T>
bool solveLinear(T a, T b, double& root) {
    if (a == 0) return false;
    root = -b / static_cast<double>(a);
    return true;
}

template <typename T>
bool solveQuadratic(T a, T b, T c, double& root1, double& root2) {
    if (a == 0) return false;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);
    return true;
}

void print2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Task 1: Binary Search\n";
    int arr[] = { 2, 3, 4, 10, 40, 50, 60, 70 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    cout << "Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\nSearching for " << target << "\n";
    int result = binarySearchHelper(arr, size, target);
    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found\n";
    cout << endl;

    int rows = 3, cols = 4;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    int initial[3][4] = {
        {4, 5, 6, 7},
        {1, 2, 4, 1},
        {4, 5, 6, 9}
    };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = initial[i][j];
        }
    }

    cout << "Task 2: Circular Shift Right by 3\n";
    cout << "Original Matrix:\n";
    print2DArray(matrix, rows, cols);
    shift2DArrayRight(matrix, rows, cols, 3);
    cout << "After shifting right by 3:\n";
    print2DArray(matrix, rows, cols);
    cout << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = initial[i][j];
        }
    }

    cout << "Task 3: Circular Shift Left by 2\n";
    cout << "Original Matrix:\n";
    print2DArray(matrix, rows, cols);
    shift2DArrayLeft(matrix, rows, cols, 2);
    cout << "After shifting left by 2:\n";
    print2DArray(matrix, rows, cols);
    cout << endl;

    cout << "Task 4.1: Array Average\n";
    int intArr[] = { 1, 2, 3, 4, 5 };
    double doubleArr[] = { 1.5, 2.5, 3.5 };
    cout << "Average of int array {1, 2, 3, 4, 5}: " << arrayAverage(intArr, 5) << endl;
    cout << "Average of double array {1.5, 2.5, 3.5}: " << arrayAverage(doubleArr, 3) << endl;
    cout << endl;

    cout << "Task 4.2: Solving Equations\n";
    double root, root1, root2;
    if (solveLinear(2, 4, root)) {
        cout << "Linear equation 2x + 4 = 0, root: " << root << endl;
    } else {
        cout << "No solution for linear equation\n";
    }
    if (solveQuadratic(1, -5, 6, root1, root2)) {
        cout << "Quadratic equation x^2 - 5x + 6 = 0, roots: " << root1 << ", " << root2 << endl;
    } else {
        cout << "No real roots for quadratic equation\n";
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
