#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "ModulesFedotov.h"

using namespace std;

struct TestSuite {
    float a = 0;
    float b = 0;
    float expArea = 0;
    float expPerimeter = 0;
    float resultArea = 0;
    float resultPerimeter = 0;
};

void createInputFile(const string& filename, const vector<TestSuite>& tests) {
    ofstream file(filename);
    if (file.is_open()) {
        file << setw(10) << left << "Action" << "|"
            << setw(10) << left << "Action2" << "|"
            << setw(15) << left << "Expected Area" << "|"
            << setw(18) << left << "Expected Perimeter" << "|"
            << setw(15) << left << "Result Area" << "|"
            << setw(18) << left << "Result Perimeter" << "|\n";
        file << string(90, '-') << "\n";
        for (const auto& test : tests) {
            file << fixed << setprecision(2)
                << setw(10) << left << test.a << "|"
                << setw(10) << left << test.b << "|"
                << setw(15) << left << test.expArea << "|"
                << setw(18) << left << test.expPerimeter << "|"
                << setw(15) << left << "" << "|"
                << setw(18) << left << "" << "|\n";
        }
        file.close();
    }
}

string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            content += line + "\n";
        }
        file.close();
    }
    return content;
}

vector<TestSuite> readCVSFiles(const string& filePath) {
    ifstream testSuite(filePath);
    vector<string> row;
    vector<TestSuite> autotest;
    TestSuite ts;
    string line, value;
    if (testSuite.is_open()) {
        getline(testSuite, line); 
        getline(testSuite, line); 
        while (getline(testSuite, line)) {
            row.clear();
            stringstream s(line);
            int count = 0;
            while (getline(s, value, '|')) {
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                if (!value.empty() && count < 6) {
                    if (count == 0) ts.a = stof(value);
                    else if (count == 1) ts.b = stof(value);
                    else if (count == 2) ts.expArea = stof(value);
                    else if (count == 3) ts.expPerimeter = stof(value);
                    else if (count == 4) ts.resultArea = !value.empty() ? stof(value) : 0;
                    else if (count == 5) ts.resultPerimeter = !value.empty() ? stof(value) : 0;
                    count++;
                }
            }
            if (count >= 4) { 
                autotest.push_back(ts);
            }
        }
        testSuite.close();
    }
    return autotest;
}

void printTable(const vector<TestSuite>& tests) {
    cout << setw(10) << left << "Action" << "|"
        << setw(10) << left << "Action2" << "|"
        << setw(15) << left << "Expected Area" << "|"
        << setw(18) << left << "Expected Perimeter" << "|"
        << setw(15) << left << "Result Area" << "|"
        << setw(18) << left << "Result Perimeter" << "|\n";
    cout << string(90, '-') << "\n";
    for (size_t i = 0; i < tests.size(); i++) {
        cout << fixed << setprecision(2)
            << setw(10) << left << tests[i].a << "|"
            << setw(10) << left << tests[i].b << "|"
            << setw(15) << left << tests[i].expArea << "|"
            << setw(18) << left << tests[i].expPerimeter << "|"
            << setw(15) << left << tests[i].resultArea << "|"
            << setw(18) << left << tests[i].resultPerimeter << "|\n";
    }
    cout << endl;
}

void updateInputFile(const string& filename, const vector<TestSuite>& tests) {
    ofstream file(filename);
    if (file.is_open()) {
        file << setw(10) << left << "Action" << "|"
            << setw(10) << left << "Action2" << "|"
            << setw(15) << left << "Expected Area" << "|"
            << setw(18) << left << "Expected Perimeter" << "|"
            << setw(15) << left << "Result Area" << "|"
            << setw(18) << left << "Result Perimeter" << "|\n";
        file << string(90, '-') << "\n";
        for (const auto& test : tests) {
            file << fixed << setprecision(2)
                << setw(10) << left << test.a << "|"
                << setw(10) << left << test.b << "|"
                << setw(15) << left << test.expArea << "|"
                << setw(18) << left << test.expPerimeter << "|"
                << setw(15) << left << test.resultArea << "|"
                << setw(18) << left << test.resultPerimeter << "|\n";
        }
        file.close();
    }
}

int main() {
    const string inputFilePath = "TS.txt";
    ifstream checkFile(inputFilePath);
    vector<TestSuite> defaultTests = {
        {5.25, 4.0, 21.0, 18.5},
        {15.5, 2.0, 31.0, 35.0},
        {25.75, 3.0, 77.25, 57.5},
        {36.0, 5.0, 180.0, 82.0},
        {46.25, 2.0, 92.5, 96.5}
    };
    if (!checkFile.is_open()) {
        createInputFile(inputFilePath, defaultTests);
    }
    checkFile.close();

    ofstream testResult("TestResult.txt");
    if (!testResult.is_open()) {
        cout << "Не вдалося створити файл результатів!" << endl;
        return -1;
    }

    vector<TestSuite> autotest = readCVSFiles(inputFilePath);

    if (!autotest.empty()) {
        printTable(autotest);
    }
    else {
        cout << "Помилка: файл TS.txt порожній або не знайдено!" << endl;
    }

    ClassLab12_Fedotov rect;
    if (autotest.empty()) {
        testResult << "Помилка: файл TS.txt порожній або не знайдено!" << endl;
    }
    else {
        for (size_t i = 0; i < autotest.size(); i++) {
            rect.setA(autotest[i].a);
            rect.setB(autotest[i].b);
            autotest[i].resultArea = rect.getArea();
            autotest[i].resultPerimeter = rect.getPerimeter();
            float expectedArea = autotest[i].expArea;
            if (fabs(autotest[i].resultArea - expectedArea) < 0.01) {
                testResult << "test №" << i + 1 << " (Area) -> passed" << endl;
            }
            else {
                testResult << "test №" << i + 1 << " (Area) -> failed" << endl
                    << "answers don't match" << endl
                    << "It should be -> " << fixed << setprecision(2) << expectedArea << endl
                    << "Received response -> " << fixed << setprecision(2) << autotest[i].resultArea << endl;
            }
            float expectedPerimeter = autotest[i].expPerimeter;
            if (fabs(autotest[i].resultPerimeter - expectedPerimeter) < 0.01) {
                testResult << "test №" << i + 1 << " (Perimeter) -> passed" << endl << endl;
            }
            else {
                testResult << "test №" << i + 1 << " (Perimeter) -> failed" << endl
                    << "answers don't match" << endl
                    << "It should be -> " << fixed << setprecision(2) << expectedPerimeter << endl
                    << "Received response -> " << fixed << setprecision(2) << autotest[i].resultPerimeter << endl << endl;
            }
        }
        updateInputFile(inputFilePath, autotest);
    }

    testResult.close();

    string outputContent = readOutputFile("TestResult.txt");
    cout << outputContent;

    system("pause");
    return 0;
}