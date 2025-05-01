#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU-UA"); 

    const int Steck = 20;
    int arr[Steck];

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < Steck; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    
    cout << "Парни значення масиву:" << endl;
    for (int i = 0; i < Steck; i++) {
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Вид'ємни значення масиву:" << endl;
    for (int i = 0; i < Steck; i++) {
        if (arr[i] < 0)
            cout << arr[i] << " ";
    }
    cout << endl;

    
    int sum = 0;
    for (int i = 0; i < Steck; i++) {
        sum += arr[i];
    }
    cout << "Сума елементив масиву: " << sum << endl;

    
    double average = static_cast<double>(sum) / Steck;
    cout << "Середнє значення: " << average << endl;

    int user_number;
    cout << "Введить число для пошуку в масиви: ";
    cin >> user_number;

    bool found = false;
    for (int i = 0; i < Steck; i++) {
        if (arr[i] == user_number) {
            cout << "Число знайдено на индекси: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Числа не є частиною массива." << endl;
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < Steck; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    cout << "Минимальне значення: " << min << endl;
    cout << "Максимальне значення: " << max << endl;

    cout << "Масив у зворотному порядку:" << endl;
    for (int i = Steck - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int original[Steck];
    for (int i = 0; i < Steck; i++) {
        original[i] = arr[i];
    }

    char choice;
    cout << "Хочете зминити елемент за индексом? [y\\n]: ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int index, newValue;
        cout << "Введить индекс (0–" << Steck - 1 << "): ";
        cin >> index;

        if (index >= 0 && index < Steck) {
            cout << "Було: arr[" << index << "] = " << arr[index] << endl;
            cout << "Введить нове значення: ";
            cin >> newValue;
            arr[index] = newValue;
            cout << "Стало: arr[" << index << "] = " << arr[index] << endl;

            
            cout << "\nПоривняння масиву (Було -> Стало):" << endl;
            for (int i = 0; i < Steck; i++) {
                cout << "arr[" << i << "]: " << original[i] << " -> " << arr[i] << endl;
            }
        }
        else {
            cout << "Некоректний индекс!" << endl;
        }
    }
    arr[0] = 0;
    arr[1] = 1;

    
    for (int i = 2; i < Steck; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

  
    cout << "Першe " << Steck << " чисел Фібоначчи:" << endl;
    for (int i = 0; i < Steck; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    int insertIndex, newValue;
    cout << "Введіть індекс для вставки (0–" << Steck - 2 << "): ";
    cin >> insertIndex;

    if (insertIndex >= 0 && insertIndex < Steck - 1) {
        cout << "Введіть нове значення: ";
        cin >> newValue;

        for (int i = Steck - 1; i > insertIndex; --i) {
            arr[i] = arr[i - 1];
        }

        arr[insertIndex] = newValue;

        cout << "Масив після вставки:" << endl;
        for (int i = 0; i < Steck; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Некоректний індекс для вставки!" << endl;
    }




    return 0;
}
