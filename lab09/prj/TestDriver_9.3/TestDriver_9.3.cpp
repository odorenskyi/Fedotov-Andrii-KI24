#include <iostream>
#include <string>
#include <Windows.h>
#include "ModulesFedotov.h"
using namespace std;

void test_countBits() {
    unsigned int testInputs[] = { 1, 3, 255, 1024, 2047, 1023, 512, 10000, 500, 8999 };
    unsigned int expectedOutputs[] = { 31,  30, 24, 31, 11, 10, 1, 0, 26,  7 };

    for (int i = 0; i < 10; i++) {
        unsigned int result = countBits(testInputs[i]);
        cout << "Тест кейс " << (i + 1) << " | Вхід: " << testInputs[i] << "\n";
        cout << "Очікуваний результат: " << expectedOutputs[i] << "\n";
        cout << "Фактичний результат: " << result << "\n";

        if (result == expectedOutputs[i]) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    test_countBits();
    system("pause");
    return 0;
}