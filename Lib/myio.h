#pragma once
#include <iostream>
#include <clocale>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "fullName.h"
#include "date.h"

char* readLine(std::istream& file = std::cin);
int readInt(std::istream& file = std::cin);
double readDouble(std::istream& file = std::cin);

fullName readFullNameFromConsole();
date readDateFromConsole();

std::string readNotEmptyLine(std::istream& stream = std::cin);

void writeString(FILE* file, const char* value);
void writeInt(FILE* file, int value);
void writeDouble(FILE* file, double value);

std::ifstream openFile(const std::string& fileName);
