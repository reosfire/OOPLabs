#include "myio.h"

char* readLine(std::istream& stream) {
    int length = 0;
    int bufferSize = 2;
    char* buffer = new char[bufferSize];

    while (true) {
        char readChar = (char) stream.get();
        if (readChar == '\n') break;

        if (length >= bufferSize) {
            bufferSize *= 2;
            char* newBuffer = new char[bufferSize];
            for (int i = 0; i < length; ++i) {
                newBuffer[i] = buffer[i];
            }
            delete[] buffer;

            buffer = newBuffer;

        }

        buffer[length] = readChar;

        length++;
    }

    char* result = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        result[i] = buffer[i];
    }
    result[length] = '\0';

    delete[] buffer;
    return result;
}
int readInt(std::istream& file) {
    int result;
    while (true) {
        char* line = readLine(file);
        int n;
        int readCount = sscanf_s(line, "%i%n", &result, &n);
        if (readCount == 1 && n == strlen(line)) break;

        std::cout << "То, что вы ввели не является целым числом! Введите число: ";
        delete[] line;
    }
    return result;
}
double readDouble(std::istream& file) {
    double result;
    while (true) {
        char* line = readLine(file);
        int n;
        int readCount = sscanf_s(line, "%lf%n", &result, &n);
        if (readCount == 1 && n == strlen(line)) break;

        std::cout << "То, что вы ввели не является десятичной дробью! Введите число: ";
        delete[] line;
    }
    return result;
}

bool is_space(char c) { return isspace(c); }
std::string readNotEmptyLine() {
    while (true) {
        std::string result = readLine();
        if (!all_of(result.begin(), result.end(), is_space)) return result;
        std::cout << "Вы ввели пустую строку. Введите не пустую: ";
    }
}

void writeString(FILE* file, const char* value) {
    fputs(value, file);
    fputc('\n', file);
}
void writeInt(FILE* file, int value) {
    char buff[20];
    _itoa_s(value, buff, 20, 10);
    writeString(file, buff);
}
void writeDouble(FILE* file, double value) {
    char buff[1000];
    sprintf_s(buff, 1000,"%lf", value);
    writeString(file, buff);
}
