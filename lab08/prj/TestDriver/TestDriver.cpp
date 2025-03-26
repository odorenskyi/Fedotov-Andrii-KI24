#include <iostream>
#include "ModulesFedotov.h"
#include <windows.h>
#include <iomanip>
using namespace std;
void test_s_calculation() {

    double x[10] = { 1.0,  0.5,  0.25,  1.5,  2.0,
                     1.25, 3.0,  3.05,  4.5,  5.0 };
    double y[10] = { 2.0,  1.5,  0.5,   1.0,  2.5,
                     3.5,  0.75, 2.2,   4.0,  1.1 };
    double z[10] = { 3.0,  2.5,  1.5,   4.0,  5.0,
                     2.75, 4.5,  3.85,  6.0,  2.2 };
    double expected[10] = { 0.090702573174318291, 1.2013159535175217, 0.99804689486815434, 0.28591523359145032, 0.22482574478822936 ,
                           1.2308436108288900 , 0.94352072703151180, 1.7486858333711237, 5.3774263630994401,2.0001652954438924 };
    cout << "Запуск тестів для функції s_calculation:\n";
    for (int i = 0; i < 10; i++) {
        double result = s_calculation(x[i], y[i], z[i]);
         cout << "Тест кейс #" << (i + 1)
            << " | x = " << x[i]
            << ", y = " << y[i]
                << ", z = " << z[i]
                    << " | Результат = "<< result
                        << " | Очікуваний результат = " << expected[i];
    if (result == expected[i]) {
        cout << " -> PASSED\n";
    }
    else {
        cout << " -> FAILED\n";
    }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    test_s_calculation();
    system("pause");
    return 0;
}
