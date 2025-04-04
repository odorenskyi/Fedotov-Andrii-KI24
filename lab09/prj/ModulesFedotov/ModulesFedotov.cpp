#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
double s_calculation(double x, double y, double z) {
    double term1 = sqrt(abs(z - 2 * x));
    double term2 = x * sin(pow(x, 2 * z) * y);

    return abs(term1 - term2);
}

string printWindSpeedInfo(int bofort) {
    stringstream result;
    double minSpeed = 0, maxSpeed = 0;
    string description;

    switch (bofort) {
    case 0: minSpeed = 0; maxSpeed = 0.3; description = "Відсутність вітру. Дим піднімається прямо. Листя дерев нерухомі."; break;
    case 1: minSpeed = 0.3; maxSpeed = 1.5; description = "Дим 'пливе'. Флюгер не обертається."; break;
    case 2: minSpeed = 1.6; maxSpeed = 3.4; description = "Рух повітря відчувається обличчям. Шелестить листя."; break;
    case 3: minSpeed = 3.5; maxSpeed = 5.4; description = "Тріпоче листя, хитаються дрібні гілки. Майорять прапори."; break;
    case 4: minSpeed = 5.5; maxSpeed = 7.9; description = "Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу."; break;
    case 5: minSpeed = 8.0; maxSpeed = 10.7; description = "Хитаються великі гілки. На воді з’являються хвилі."; break;
    case 6: minSpeed = 10.8; maxSpeed = 13.8; description = "Хитаються великі гілки."; break;
    case 7: minSpeed = 13.9; maxSpeed = 17.1; description = "Хитаються невеликі стовбури дерев. На морі здіймаються хвилі."; break;
    case 8: minSpeed = 17.2; maxSpeed = 20.7; description = "Ламаються гілки дерев. Важко йти проти вітру."; break;
    case 9: minSpeed = 20.8; maxSpeed = 24.4; description = "Невеликі руйнування. Зриває покрівлі, руйнує димарі."; break;
    case 10: minSpeed = 24.5; maxSpeed = 28.4; description = "Значні руйнування. Дерева вириваються з корінням."; break;
    case 11: minSpeed = 28.5; maxSpeed = 32.6; description = "Великі руйнування."; break;
    case 12: minSpeed = 32.7; maxSpeed = 50.0; description = "Призводить до спустошень."; break;
    default:
        result << "Незадовільний бал Бофорда!" << endl;
        return result.str();
    }

    result << "Швидкість вітру: " << minSpeed << " - " << maxSpeed << " м/с ("
        << minSpeed * 3.6 << " - " << maxSpeed * 3.6 << " км/ч)\n"
        << "Опис: " << description << endl;

    return result.str(); 
}

