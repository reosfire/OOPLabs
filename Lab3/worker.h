#pragma ones

#include <vector>
#include <fstream>
#include "man.h"

class worker: public man {
private:
    friend std::ostream& operator<< (std::ostream& stream, worker const& v);
    friend std::istream& operator>> (std::istream& stream, worker& v);
public:
    bool operator == (const man& b) const;

private:
    int department{};
    double salary{};

public:
    int getDepartment() const;
    double getSalary() const;

    static std::vector<worker> getInitialWorkers(const std::string& fileName = "data.txt");
    static void saveWorkers(const std::vector<worker>& workers, const std::string& fileName = "data.txt");
};