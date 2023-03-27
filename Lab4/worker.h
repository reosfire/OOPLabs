#pragma ones

#include <vector>
#include <fstream>
#include "fullName.h"

class worker {
private:
    friend std::ostream& operator<< (std::ostream& stream, worker const& v);
    friend std::istream& operator>> (std::istream& stream, worker& v);
public:
    bool operator == (const fullName& b) const;
    bool operator != (const fullName& b) const;

private:
    int department{};
    double salary{};
    fullName name{};

public:
    int getDepartment() const;
    double getSalary() const;
    fullName getName() const;

    void print() const;

    static std::vector<worker> getInitialWorkers(const std::string& fileName = "data.txt");
    static void saveWorkers(const std::vector<worker>& workers, const std::string& fileName = "data.txt");
};