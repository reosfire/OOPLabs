#include <iostream>
#include "man.h"
#include "../Lib/myio.h"

std::string man::getName() const {
    return name;
}

std::string man::getSurname() const {
    return surname;
}

std::istream &operator>>(std::istream& stream, man& man) {
    if (stream.rdbuf() == std::cin.rdbuf()) {
        std::cout << "������� ���: ";
        man.name = readLine(stream);
        std::cout << "������� �������: ";
        man.surname = readLine(stream);
    }
    else {
        man.name = readLine(stream);
        man.surname = readLine(stream);
    }
    return stream;
}
