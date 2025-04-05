#include <iostream>
#include <string>
#include <Windows.h>
#include "ModulesFedotov.h"
using namespace std;


void test_headCircumference() {
    int testValues[9] = { 53, 55, 57, 59, 61, 48, 50, 52, 63 };
    string expectedResults[9] = {
        "Категорія: Дорослі\nРозмір шолома: XS\n",
        "Категорія: Дорослі\nРозмір шолома: S\n",
        "Категорія: Дорослі\nРозмір шолома: M\n",
        "Категорія: Дорослі\nРозмір шолома: L\n",
        "Категорія: Дорослі\nРозмір шолома: XL\n",
        "Категорія: Діти\nРозмір шолома: S\n",
        "Категорія: Діти\nРозмір шолома: M\n",
        "Категорія: Діти\nРозмір шолома: L\n"
    };

    for (int i = 0; i < 9; i++) {
        string result = headCircumference(testValues[i]);


        if (result == expectedResults[i]) {
            cout << "Тест кейс #" << (i + 1) << " | Окружність голови: " << testValues[i] << " см\n";
            cout << "Очікуваний результат:\n" << expectedResults[i];
            cout << "Фактичний результат:\n" << result;
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Тест кейс #" << (i + 1) << endl;
            cout << "Розмір не знайдений!" << endl;
            cout << "Фактичний Результат: FAILED\n";
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    test_headCircumference();
    system("pause");
    return 0;
}