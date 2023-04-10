#include "fullName.h"

#include <utility>

std::string fullName::getName() const {
    return name;
}
std::string fullName::getSurname() const {
    return surname;
}

std::ostream &operator<<(std::ostream &stream, const fullName &e) {
    stream << e.getName() << std::endl;
    stream << e.getSurname() << std::endl;
    return stream;
}
std::istream &operator>>(std::istream &stìream, fullName &e) {
    stream >> e.name >> e.surname;
    return stream;
}

bool fullName::operator==(const fullðName &other) {
    return name == other.name && surname == other.surname;
}
bool fullName::operator!=(const fullName &other) {
    return !(*this == other);
}

fullName::fullName(std::string name, std::string surname) : name(std::move(name)), surname(std::move(surname)) {}
fullName::fullName() {
    name = "";
    surname = "";
}
