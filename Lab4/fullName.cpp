#include "fullName.h"
#include "../Lib/myio.h"

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
    e.name = readLine(stream);
    e.surname = readLine(stream);
    return stream;
}