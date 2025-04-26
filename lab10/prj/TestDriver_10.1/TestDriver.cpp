#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ModulesFedotov.h>
using namespace std;

//�������� ������� ��� ��������� ����������� �������� ����� � ������� ������ 
void createInputFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

// �������� ������� ��� ������� ����� ��������� �����
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

void test_processSentence() {
    // ������ �����
    struct TestCase {
        string inputContent;
        string expectedOutput;
    };

    TestCase testCases[] = {
        {
            "Hello! How are you? Great!!",
            "���������: ����� �������\n"
            "��������: ����\n"
            "̳���: �������������\n"
            "�����: ������\n"
            "г� ��������: 2025\n\n"
            "ʳ������ ����� '!': 3\n"
            "ʳ������ ����� '?': 1\n\n"
            "������� ��� �������� ����:\n"
            "Hll! Hw r y? Grt!!\n"
        },
        {
            "�� ������� �������.",
            "���������: ����� �������\n"
            "��������: ����\n"
            "̳���: �������������\n"
            "�����: ������\n"
            "г� ��������: 2025\n\n"
            "ʳ������ ����� '!': 0\n"
            "ʳ������ ����� '?': 0\n\n"
            "������� ��� �������� ����:\n"
            "� ���� �����.\n"
        },
        {
            "aeiouAEIOU�����",
            "���������: ����� �������\n"
            "��������: ����\n"
            "̳���: �������������\n"
            "�����: ������\n"
            "г� ��������: 2025\n\n"
            "ʳ������ ����� '!': 0\n"
            "ʳ������ ����� '?': 0\n\n"
            "������� ��� �������� ����:\n"
            "\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        // ��������� ���������� ������� � �������� �����
        string inputFile = "test_input_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_" + to_string(i + 1) + ".txt";

        // ϳ�������� ������� ����
        createInputFile(inputFile, testCases[i].inputContent);

        // ³������� ����� �� �������� �������
        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        processSentence(inFile, outFile);
        inFile.close();
        outFile.close();

        // �������� ��������� �����
        string actualOutput = readOutputFile(outputFile);

        // ������� �������� ���������� ��� �������� �������
        cout << "���� ���� " << (i + 1) << " | ����: \"" << testCases[i].inputContent << "\"\n";
        cout << "���������� ���������:\n" << testCases[i].expectedOutput << "\n";
        cout << "��������� ���������:\n" << actualOutput << "\n";

        // ��������, �� �������� ����
        if (actualOutput == testCases[i].expectedOutput) {
            cout << "���������: PASSED\n";
        }
        else {
            cout << "���������: FAILED\n";
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251); 
    test_processSentence();
    system("pause");
    return 0;
}