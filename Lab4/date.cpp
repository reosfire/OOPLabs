#include "date.h"

std::ostream &operator<<(std::ostream &stream, const date &e) {
    stream << e.day << std::endl;
    stream << e.month << std::endl;
    stream << e.year << std::endl;
    return stream;
}
std::istream &operator>>(std::istream &stream, date &e) {
    stream >> e.day >> e.month >> e.year;
    return stream;
}

int date::getDay() const {
    return 0;
}
std::string date::getMonth() const {
    return std::string();
}
int date::getYear() const {
    return 0;
}
void date::print() {

}
