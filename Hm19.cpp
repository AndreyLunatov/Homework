#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr"); 
    const int MAX_LINES = 100; 
    string lines[MAX_LINES];
    int lineCount = 0;

    cout << "Введіть рядки (порожній рядок для завершення):\n";
    while (lineCount < MAX_LINES) {
        getline(cin, lines[lineCount]);
        if (lines[lineCount].empty()) break;
        lineCount++;
    }

    if (lineCount == 0) {
        cout << "Немає рядків для обробки!" << std::endl;
        return 1;
    }

    cout << "Рядки без останнього:\n";
    for (int i = 0; i < lineCount - 1; i++) {
        cout << lines[i] << endl;
    }
    return 0;
}
///////////////////////////
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    const int MAX_LINES = 100;
    string lines[MAX_LINES];
    int lineCount = 0;
    int maxLength = 0;

    cout << "Введіть рядки (порожній рядок для завершення):\n";
    while (lineCount < MAX_LINES) {
        getline(cin, lines[lineCount]);
        if (lines[lineCount].empty()) break;
        if (lines[lineCount].length() > maxLength) {
            maxLength = lines[lineCount].length();
        }
        lineCount++;
    }

    cout << "Довжина найдовшого рядка: " << maxLength << " символів" << endl;
    return 0;
}

///////////////////////////////////////

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr"); 
    const int MAX_TEXT = 1000;
    char text[MAX_TEXT];
    string searchWord;

    cout << "Введіть текст (до " << MAX_TEXT << " символів):\n";
    cin.getline(text, MAX_TEXT);

    cout << "Введіть слово для пошуку: ";
    cin >> searchWord;

    int count = 0;
    string textStr(text);
    size_t pos = 0;
    while ((pos = textStr.find(searchWord, pos)) != string::npos) {
        count++;
        pos += searchWord.length();
    }

    cout << "Слово '" << searchWord << "' зустрічається " << count << " разів" << endl;
    return 0;
}

////////////////////////////////////////

    #include <iostream>
    using namespace std;

    int main() {
        setlocale(LC_ALL, "ukr"); 
        const int MAX_TEXT = 1000;
        char text[MAX_TEXT];
        string searchWord;

        cout << "Введіть текст (до " << MAX_TEXT << " символів):\n";
        cin.getline(text, MAX_TEXT);

        cout << "Введіть слово для пошуку: ";
        cin >> searchWord;

        int count = 0;
        string textStr(text);
        size_t pos = 0;
        while ((pos = textStr.find(searchWord, pos)) != string::npos) {
            count++;
            pos += searchWord.length();
        }

        cout << "Слово '" << searchWord << "' зустрічається " << count << " разів" << endl;
        return 0;
    }
////////////////////////////////
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr"); 
    const int MAX_TEXT = 1000;
    char text[MAX_TEXT];
    string searchWord, replaceWord;

    cout << "Введіть текст (до " << MAX_TEXT << " символів):\n";
    cin.getline(text, MAX_TEXT);

    cout << "Введіть слово для пошуку: ";
    cin >> searchWord;
    cout << "Введіть слово для заміни: ";
    cin >> replaceWord;

    string textStr(text);
    size_t pos = 0;
    while ((pos = textStr.find(searchWord, pos)) != string::npos) {
        textStr.replace(pos, searchWord.length(), replaceWord);
        pos += replaceWord.length();
    }

    cout << "Результат заміни:\n" << textStr << endl;
    return 0;
}
////////////////////////////////
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr"); 
    const int MAX_LINES = 100;
    string lines1[MAX_LINES], lines2[MAX_LINES];
    int count1 = 0, count2 = 0;

    cout << "Введіть рядки для першого набору (порожній рядок для завершення):\n";
    while (count1 < MAX_LINES) {
        getline(cin, lines1[count1]);
        if (lines1[count1].empty()) break;
        count1++;
    }

    cout << "Введіть рядки для другого набору (порожній рядок для завершення):\n";
    while (count2 < MAX_LINES) {
        getline(cin, lines2[count2]);
        if (lines2[count2].empty()) break;
        count2++;
    }

    bool match = true;
    int minCount = (count1 < count2) ? count1 : count2;
    for (int i = 0; i < minCount; i++) {
        if (lines1[i] != lines2[i]) {
            match = false;
            cout << "Рядок " << i + 1 << " не збігається:\n";
            cout << "Набір 1: " << lines1[i] << "\n";
            cout << "Набір 2: " << lines2[i] << "\n";
        }
    }

    if (count1 != count2) {
        match = false;
        cout << "Кількість рядків різна!\n";
        if (count1 > count2) cout << "Додатковий рядок у наборі 1: " << lines1[count2] << endl;
        else cout << "Додатковий рядок у наборі 2: " << lines2[count1] << endl;
    }

    if (match) cout << "Рядки збігаються" << endl;
    return 0;
}
////////////////////////////
   #include <iostream>
using namespace std;

string caesarCipher(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)(((c - base + shift) % 26 + 26) % 26 + base);
        } else {
            result += c; // Залишаємо неалфавітні символи без змін
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ukr"); 
    string text;
    int shift;

    cout << "Введіть текст для шифрування:\n";
    cin.ignore(); 
    getline(cin, text);

    cout << "Введіть зсув (ключ): ";
    cin >> shift;

    string encrypted = caesarCipher(text, shift);
    cout << "Зашифрований текст: " << encrypted << endl;
    return 0;
}
