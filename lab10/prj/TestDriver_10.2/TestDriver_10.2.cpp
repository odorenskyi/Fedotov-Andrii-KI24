#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "ModulesFedotov.h"
using namespace std;

// Допоміжна функція для створення тимчасового вхідного файлу
void createInputFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

// Допоміжна функція для читання вмісту вихідного файлу
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back(); // Видаляємо \r для Windows
        }
        content += line + "\n";
    }
    file.close();
    return content;
}

void test_transliterateAndAppend() {
    // Тестові кейси
    struct TestCase {
        string inputContent;
        string expectedOutputPrefix; // Очікуваний вміст без дати/часу
    };

    TestCase testCases[] = {
        // Тест 1: Речення з різними літерами
        {
            "Привіт, як справи? Їжа та ґудзики!",
            "Транслітерований текст:\n"
            "Pryvit, yak spravy? Yizha ta gudzyky!\n"
        },
        // Тест 2: Текст із початковими є, ї, й, ю, я
        {
            "Євген Їв Юлія Яна",
            "Транслітерований текст:\n"
            "Yevhen Yiv Yuliya Yana\n"
        },
        // Тест 3: Текст із апострофом і м’яким знаком
        {
            "Привіт, друже як справи?",
            "Транслітерований текст:\n"
            "Pryvit, druzhe yak spravy?\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        // Створення тимчасових вхідного та вихідного файлів
        string inputFile = "test_input_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_" + to_string(i + 1) + ".txt";

        // Підготовка вхідного файлу
        createInputFile(inputFile, testCases[i].inputContent);

        // Відкриття файлів і виклик функції
        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        transliterateAndAppend(inFile, outFile);
        inFile.close();
        outFile.close();

        // Зчитування фактичного вмісту вихідного файлу
        string actualOutput = readOutputFile(outputFile);

        // Очікуваний вміст (префікс + дата/час)
        string expectedOutputPrefix = testCases[i].expectedOutputPrefix;

        // Виведення результатів
        cout << "Тест кейс " << (i + 1) << " | Вхідний файл: " << inputFile << " | Вихідний файл: " << outputFile << "\n";
        cout << "Вхідний вміст:\n" << testCases[i].inputContent << "\n";
        cout << "Очікуваний вміст (префікс):\n" << expectedOutputPrefix << "<дата й час>\n";
        cout << "Фактичний вміст:\n" << actualOutput << "\n";

        // Перевірка, чи фактичний вміст починається з очікуваного префікса
        bool passed = actualOutput.find(expectedOutputPrefix) == 0 &&
            actualOutput.find("Дата й час дозапису: ") != string::npos;

        if (passed) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
            if (actualOutput.find(expectedOutputPrefix) != 0) {
                cout << "Помилка: Фактичний вміст не починається з очікуваного префікса\n";
            }
            if (actualOutput.find("Дата й час дозапису: ") == string::npos) {
                cout << "Помилка: Рядок 'Дата й час дозапису: ' не знайдено\n";
            }
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251); // Підтримка українських символів
    test_transliterateAndAppend();
    system("pause");
    return 0;
}