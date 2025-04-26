#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <iomanip>
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
void processSentence(ifstream& input_file, ofstream& output_file) {
    output_file << "Розробник: Андрій Фкдотов\n"
        << "Установа: ЦНТУ\n"
        << "Місто: Кропивницький\n"
        << "Країна: Україна\n"
        << "Рік розробки: 2025\n\n";

    string sentence;
    if (getline(input_file, sentence)) {
        int exclamation = 0, question = 0;
        for (char c : sentence) {
            if (c == '!') exclamation++;
            else if (c == '?') question++;
        }
        output_file << "Кількість знаків '!': " << exclamation << endl;
        output_file << "Кількість знаків '?': " << question << endl << endl;

        string no_vowels;
        for (char c : sentence) {
            char lower = tolower(c);
            if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' ||
                lower == 'а' || lower == 'е' || lower == 'и' || lower == 'і' || lower == 'о' || lower == 'у')) {
                no_vowels += c;
            }
        }
        output_file << "Речення без голосних літер:\n" << no_vowels << endl;
    }
    else {
        output_file << "Помилка: вхідний файл порожній або не містить речення." << endl;
    }
}
void transliterateAndAppend(ifstream& input_file, ofstream& output_file) {
    string content;
    string line;
    while (getline(input_file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        content += line + "\n";
    }

    string transliterated;
    bool isWordStart = true;
    for (size_t i = 0; i < content.length(); ++i) {
        char c = content[i];
        string lowerC(1, tolower(c));
        string upperC(1, toupper(c));

        if (c == 'А' || c == 'а') transliterated += (c == 'А' ? "A" : "a");
        else if (c == 'Б' || c == 'б') transliterated += (c == 'Б' ? "B" : "b");
        else if (c == 'В' || c == 'в') transliterated += (c == 'В' ? "V" : "v");
        else if (c == 'Г' || c == 'г') transliterated += (c == 'Г' ? "H" : "h");
        else if (c == 'Ґ' || c == 'ґ') transliterated += (c == 'Ґ' ? "G" : "g");
        else if (c == 'Д' || c == 'д') transliterated += (c == 'Д' ? "D" : "d");
        else if (c == 'Е' || c == 'е') transliterated += (c == 'Е' ? "E" : "e");
        else if (c == 'Є' || c == 'є') transliterated += (isWordStart ? (c == 'Є' ? "Ye" : "ye") : (c == 'Є' ? "Ie" : "ie"));
        else if (c == 'Ж' || c == 'ж') transliterated += (c == 'Ж' ? "Zh" : "zh");
        else if (c == 'З' || c == 'з') transliterated += (c == 'З' ? "Z" : "z");
        else if (c == 'И' || c == 'и') transliterated += (c == 'И' ? "Y" : "y");
        else if (c == 'І' || c == 'і') transliterated += (c == 'І' ? "I" : "i");
        else if (c == 'Ї' || c == 'ї') transliterated += (isWordStart ? (c == 'Ї' ? "Yi" : "yi") : (c == 'Ї' ? "I" : "i"));
        else if (c == 'Й' || c == 'й') transliterated += (isWordStart ? (c == 'Й' ? "Y" : "y") : (c == 'Й' ? "I" : "i"));
        else if (c == 'К' || c == 'к') transliterated += (c == 'К' ? "K" : "k");
        else if (c == 'Л' || c == 'л') transliterated += (c == 'Л' ? "L" : "l");
        else if (c == 'М' || c == 'м') transliterated += (c == 'М' ? "M" : "m");
        else if (c == 'Н' || c == 'н') transliterated += (c == 'Н' ? "N" : "n");
        else if (c == 'О' || c == 'о') transliterated += (c == 'О' ? "O" : "o");
        else if (c == 'П' || c == 'п') transliterated += (c == 'П' ? "P" : "p");
        else if (c == 'Р' || c == 'р') transliterated += (c == 'Р' ? "R" : "r");
        else if (c == 'С' || c == 'с') transliterated += (c == 'С' ? "S" : "s");
        else if (c == 'Т' || c == 'т') transliterated += (c == 'Т' ? "T" : "t");
        else if (c == 'У' || c == 'у') transliterated += (c == 'У' ? "U" : "u");
        else if (c == 'Ф' || c == 'ф') transliterated += (c == 'Ф' ? "F" : "f");
        else if (c == 'Х' || c == 'х') transliterated += (c == 'Х' ? "Kh" : "kh");
        else if (c == 'Ц' || c == 'ц') transliterated += (c == 'Ц' ? "Ts" : "ts");
        else if (c == 'Ч' || c == 'ч') transliterated += (c == 'Ч' ? "Ch" : "ch");
        else if (c == 'Ш' || c == 'ш') transliterated += (c == 'Ш' ? "Sh" : "sh");
        else if (c == 'Щ' || c == 'щ') transliterated += (c == 'Щ' ? "Shch" : "shch");
        else if (c == 'Ь' || c == 'ь') transliterated += "";
        else if (c == 'Ю' || c == 'ю') transliterated += (isWordStart ? (c == 'Ю' ? "Yu" : "yu") : (c == 'Ю' ? "Iu" : "iu"));
        else if (c == 'Я' || c == 'я') transliterated += (isWordStart ? (c == 'Я' ? "Ya" : "ya") : (c == 'Я' ? "Ia" : "ia"));
        else if (c == '\'') transliterated += "";
        else transliterated += c;

        isWordStart = !isalpha(static_cast<unsigned char>(c)) && c != '\'';
    }

    time_t now = time(nullptr);
    char timeStr[100];
    struct tm timeInfo;
    localtime_s(&timeInfo, &now);
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &timeInfo);

    output_file << "Транслітерований текст:\n" << transliterated;
    output_file << "Дата й час дозапису: " << timeStr << "\n";
}