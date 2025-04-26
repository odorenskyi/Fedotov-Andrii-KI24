#pragma once
#include <string>  
using namespace std;
double s_calculation(double x, double y, double z);
string printWindSpeedInfo(int bofort);
string headCircumference(int headCircumference);
unsigned int countBits(unsigned int number);
void processSentence(ifstream& input_file, ofstream& output_file);
void transliterateAndAppend(ifstream& input_file, ofstream& output_file);
void writeCalculationAndBinary(ifstream& input_file, ofstream& output_file);