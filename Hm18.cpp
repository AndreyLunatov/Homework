#include <iostream>
#include <fstream>

using namespace std;

void saveNumbers() {
    int data[] = {18, 30, 21, 22, 13, 25, 23, 14, 30, 21};
    ofstream file("data.bin", ios::binary);
    file.write((char*)data, 10 * sizeof(int));
    file.close();
}

void displayNumbers() {
    ifstream file("data.bin", ios::binary);
    int data[10];
    file.read((char*)data, 10 * sizeof(int));
    for (int idx = 0; idx < 10; idx++) {
        cout << data[idx] << " Hello " << idx << endl;
    }
    file.close();
}

int main() {
    saveNumbers();
    displayNumbers();
    return 0;
}
