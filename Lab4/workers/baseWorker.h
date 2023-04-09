#pragma ones

#include <vector>
#include <utility>
#include <fstream>
#include "../fullName.h"

class baseWorker {
protected:
    fullName name;
    double salary;
    int department;

public:
    fullName getName() const;
    double getSalary() const;
    int getDepartment() const;

    virtual ~baseWorker();

    virtual void print() const = 0;
    virtual void serialize(std::ofstream& stream) const = 0;

    static void saveWorkers(const std::vector<baseWorker*>& workers, const std::string& fileName = "data.txt");
};
