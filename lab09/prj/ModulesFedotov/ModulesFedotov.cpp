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

string headCircumference(int headCircumference) {

    stringstream result;
    string size, category;

    if (headCircumference >= 53 && headCircumference <= 54) { size = "XS"; category = "Дорослі"; }
    else if (headCircumference >= 55 && headCircumference <= 56) { size = "S"; category = "Дорослі"; }
    else if (headCircumference >= 57 && headCircumference <= 58) { size = "M"; category = "Дорослі"; }
    else if (headCircumference >= 59 && headCircumference <= 60) { size = "L"; category = "Дорослі"; }
    else if (headCircumference >= 61 && headCircumference <= 62) { size = "XL"; category = "Дорослі"; }
    else if (headCircumference >= 48 && headCircumference <= 49) { size = "S"; category = "Діти"; }
    else if (headCircumference >= 50 && headCircumference <= 51) { size = "M"; category = "Діти"; }
    else if (headCircumference >= 52 && headCircumference <= 53) { size = "L"; category = "Діти"; }
    else { size = "Розмір не знайдений!"; }

    result << "Категорія: " << category << "\nРозмір шолома: " << size << endl;

    return result.str();
}

unsigned int countBits(unsigned int number) {
    if (number > 8999) {
        return 0;
    }

    bool isD10Set = (number & (1 << 9)) != 0;
    unsigned int count = 0;

    for (int i = 0; i < 32; i++) {
        bool bitIsSet = (number & (1 << i)) != 0;
        count += (isD10Set ? bitIsSet : !bitIsSet) ? 1 : 0;
    }

    return count;
}
