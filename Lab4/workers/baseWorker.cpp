#include "baseWorker.h"

#include <utility>

fullName baseWorker::getName() const {
    return name;
}
double baseWorker::getSalary() const {
    return salary;
}
int baseWorker::getDepartment() const {
    return department;
}

baseWorker::baseWorker(fullName name, double salary, int department) : name(std::move(name)), salary(salary), department(department) { }

baseWorker::~baseWorker() {

}
