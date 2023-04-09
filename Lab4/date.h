#pragma once

#include <iostream>

class date {
private:
    friend std::ostream& operator<< (std::ostream& stream, date const& v);
    friend std::istream& operator>> (std::istream& stream, date& v);

    int day;
    std::string month;
    int year;

public:
    int getDay() const;
    std::string getMonth() const;
    int getYear() const;

    std::string toString() const;
    void print() const;
    void serialize(std::ostream& stream) const;
};