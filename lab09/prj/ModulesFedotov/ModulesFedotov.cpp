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

