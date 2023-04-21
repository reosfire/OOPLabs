#pragma once

#include <iostream>
#include <vector>

class date {
private:
    friend std::ostream& operator<< (std::ostream& stream, date const& v);
    friend std::istream& operator>> (std::istream& stream, date& v);

    int day;
    std::string month;
    int year;

public:
    date(int day, std::string month, int year);
    date();

    int getDay() const;
    std::string getMonth() const;
    int getYear() const;

    std::string toString() const;
    void print() const;
    void serialize(std::ostream& stream) const;

    static const std::string months[];
    static int monthToInt(const std::string& month);
    static bool isCorrectMonth(const std::string& month);
};