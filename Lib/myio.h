#pragma once
#include <iostream>
#include <clocale>
#include <cstring>
#include <algorithm>

char* readLine(std::istream& file = std::cin);
int readInt(std::istream& file = std::cin);
double readDouble(std::istream& file = std::cin);

std::string readNotEmptyLine();

void writeString(FILE* file, const char* value);
void writeInt(FILE* file, int value);
void writeDouble(FILE* file, double value);
