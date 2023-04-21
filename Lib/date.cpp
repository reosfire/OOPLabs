#include "date.h"

#include <utility>

const std::string date::months[] = { "янв", "фев", "март", "апр", "май", "июнь", "июль", "авг", "сент", "окт", "ноя", "дек" };

date::date(int day, std::string month, int year) : day(day), month(std::move(month)), year(year) { }
date::date(): day(0), month(months[0]), year(0) { }

std::ostream& operator<<(std::ostream& stream, const date& e) {
    stream << e.day << std::endl;
    stream << e.month << std::endl;
    stream << e.year << std::endl;
    return stream;
}
std::istream& operator>>(std::istream& stream, date& e) {
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
void date::print() const {
    std::cout << toString() << std::endl;
}
void date::serialize(std::ostream &stream) const {
    stream << toString() << std::endl;
}

int date::monthToInt(const std::string &month) {
    int result = -1;

    for (int i = 0; i < 12; ++i) {
        if (months[i] == month) result = i + 1;
    }

    return result;
}
bool date::isCorrectMonth(const std::string& month) {
    return monthToInt(month) != -1;
}

