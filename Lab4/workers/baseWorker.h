#pragma once

#include <vector>
#include <utility>
#include <fstream>
#include "../../Lib/fullName.h"

class baseWorker {
protected:
    fullName name;
    double salary;
    int department;

public:
    baseWorker(fullName name, double salary, int department);

    fullName getName() const;
    double getSalary() const;
    int getDepartment() const;

    virtual ~baseWorker();

    virtual void print() const = 0;
    virtual void serialize(std::ofstream& stream) const = 0;
};
