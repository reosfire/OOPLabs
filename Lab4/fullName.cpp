#include "fullName.h"

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
std::istream &operator>>(std::istream &stream, fullName &e) {
    stream >> e.name >> e.surname;
    return stream;
}

bool fullName::operator==(const fullName &other) {
    return name == other.name && surname == other.surname;
}
bool fullName::operator!=(const fullName &other) {
    return !(*this == other);
}
