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
    case 0: minSpeed = 0; maxSpeed = 0.3; description = "³�������� ����. ��� ��������� �����. ����� ����� �������."; break;
    case 1: minSpeed = 0.3; maxSpeed = 1.5; description = "��� '�����'. ������ �� ����������."; break;
    case 2: minSpeed = 1.6; maxSpeed = 3.4; description = "��� ������ ���������� ��������. ��������� �����."; break;
    case 3: minSpeed = 3.5; maxSpeed = 5.4; description = "������ �����, ��������� ���� ����. �������� �������."; break;
    case 4: minSpeed = 5.5; maxSpeed = 7.9; description = "��������� ���� ���� �����. ³��� ����� ��� �� ������ ������."; break;
    case 5: minSpeed = 8.0; maxSpeed = 10.7; description = "��������� ����� ����. �� ��� ���������� ����."; break;
    case 6: minSpeed = 10.8; maxSpeed = 13.8; description = "��������� ����� ����."; break;
    case 7: minSpeed = 13.9; maxSpeed = 17.1; description = "��������� ������� �������� �����. �� ��� ���������� ����."; break;
    case 8: minSpeed = 17.2; maxSpeed = 20.7; description = "��������� ���� �����. ����� ��� ����� ����."; break;
    case 9: minSpeed = 20.8; maxSpeed = 24.4; description = "������� ����������. ����� ������, ����� �����."; break;
    case 10: minSpeed = 24.5; maxSpeed = 28.4; description = "����� ����������. ������ ����������� � �������."; break;
    case 11: minSpeed = 28.5; maxSpeed = 32.6; description = "����� ����������."; break;
    case 12: minSpeed = 32.7; maxSpeed = 50.0; description = "���������� �� ����������."; break;
    default:
        result << "������������ ��� �������!" << endl;
        return result.str();
    }

    result << "�������� ����: " << minSpeed << " - " << maxSpeed << " �/� ("
        << minSpeed * 3.6 << " - " << maxSpeed * 3.6 << " ��/�)\n"
        << "����: " << description << endl;

    return result.str(); 
}

string headCircumference(int headCircumference) {

    stringstream result;
    string size, category;

    if (headCircumference >= 53 && headCircumference <= 54) { size = "XS"; category = "������"; }
    else if (headCircumference >= 55 && headCircumference <= 56) { size = "S"; category = "������"; }
    else if (headCircumference >= 57 && headCircumference <= 58) { size = "M"; category = "������"; }
    else if (headCircumference >= 59 && headCircumference <= 60) { size = "L"; category = "������"; }
    else if (headCircumference >= 61 && headCircumference <= 62) { size = "XL"; category = "������"; }
    else if (headCircumference >= 48 && headCircumference <= 49) { size = "S"; category = "ĳ��"; }
    else if (headCircumference >= 50 && headCircumference <= 51) { size = "M"; category = "ĳ��"; }
    else if (headCircumference >= 52 && headCircumference <= 53) { size = "L"; category = "ĳ��"; }
    else { size = "����� �� ���������!"; }

    result << "��������: " << category << "\n����� ������: " << size << endl;

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
