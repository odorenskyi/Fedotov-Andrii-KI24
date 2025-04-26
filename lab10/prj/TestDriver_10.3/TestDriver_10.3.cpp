#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include "ModulesFedotov.h"
using namespace std;

// Хелпер для створення тимчасового вхідного файлу
void createInputFile(const string& filename, double x, double y, double z, unsigned int b) {
    ofstream file(filename);
    file << fixed << setprecision(6) << x << " " << y << " " << z << " " << b << "\n";
    file.close();
}

// Хелпер для читання вмісту вихідного файлу з нормалізацією кінців рядків
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

// Хелпер для форматування double із фіксованою точністю
string formatDouble(double value) {
    stringstream ss;
    ss << fixed << setprecision(6) << value;
    return ss.str();
}

void test_writeCalculationAndBinary() {
    // Структура для тест-кейсів
    struct TestCase {
        double x, y, z;
        unsigned int b;
        string expectedOutput; // Очікуваний вміст вихідного файлу
    };

    TestCase testCases[] = {
        // Тест 1: Звичайні значення
        {
            1.0, 2.0, 3.0,
            5,
            "s_calculation(" + formatDouble(1.0) + ", " + formatDouble(2.0) + ", " + formatDouble(3.0) + ") = " +
            formatDouble(s_calculation(1.0, 2.0, 3.0)) + "\n"
            "Число 5 у двійковому коді: 101\n"
        },
        // Тест 2: Нульове b і від’ємні значення
        {
            -1.5, 0.5, -2.0,
            0,
            "s_calculation(" + formatDouble(-1.5) + ", " + formatDouble(0.5) + ", " + formatDouble(-2.0) + ") = " +
            formatDouble(s_calculation(-1.5, 0.5, -2.0)) + "\n"
            "Число 0 у двійковому коді: 0\n"
        },
        // Тест 3: Велике b і дробові значення
        {
            0.75, -1.25, 1.5,
            13,
            "s_calculation(" + formatDouble(0.75) + ", " + formatDouble(-1.25) + ", " + formatDouble(1.5) + ") = " +
            formatDouble(s_calculation(0.75, -1.25, 1.5)) + "\n"
            "Число 13 у двійковому коді: 1101\n"
        }
    };

    // Виконання тестів
    for (int i = 0; i < 3; i++) {
        // Створення тимчасових вхідного та вихідного файлів
        string inputFile = "test_input_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_" + to_string(i + 1) + ".txt";

        // Підготовка вхідного файлу
        createInputFile(inputFile, testCases[i].x, testCases[i].y, testCases[i].z, testCases[i].b);

        // Відкриття файлів і виклик функції
        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        writeCalculationAndBinary(inFile, outFile);
        inFile.close();
        outFile.close();

        // Зчитування фактичного вмісту вихідного файлу
        string actualOutput = readOutputFile(outputFile);

        // Виведення результатів
        cout << "Тест кейс " << (i + 1) << " | Вхідний файл: " << inputFile << " | Вихідний файл: " << outputFile << "\n";
        cout << "Вхідні дані: x=" << testCases[i].x << ", y=" << testCases[i].y << ", z=" << testCases[i].z << ", b=" << testCases[i].b << "\n";
        cout << "Очікуваний вміст:\n" << testCases[i].expectedOutput << "\n";
        cout << "Фактичний вміст:\n" << actualOutput << "\n";

        // Перевірка, чи фактичний вміст відповідає очікуваному
        bool passed = actualOutput == testCases[i].expectedOutput;

        if (passed) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
            if (actualOutput != testCases[i].expectedOutput) {
                cout << "Помилка: Фактичний вміст не відповідає очікуваному\n";
            }
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251); // Підтримка українських символів
    test_writeCalculationAndBinary();
    system("pause");
    return 0;
}