#include "date.h"

std::ostream &operator<<(std::ostream& stream, const date& e) {
    stream << e.day << std::endl;
    stream << e.month << std::endl;
    stream << e.year << std::endl;
    return stream;
}
std::istream &operator>>(std::istream& stream, date& e) {
    stream >> e.day >> e.month >> e.year;
    return stream;
}

int date::getDay() const {
    return day;
}
std::string date::getMonth() const {
    return month;
}
int date::getYear() const {
    return year;
}
std::string date::toString() const {
    return std::to_string(day) + " " + month + " " + std::to_string(year);
}

void date::print() {
    std::cout << toString() << std::endl;
}
