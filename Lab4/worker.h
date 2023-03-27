#pragma ones

#include <vector>
#include <fstream>
#include "baseWorker.h"

class worker: public baseWorker {
private:
    friend std::ostream& operator<< (std::ostream& stream, worker const& v);
    friend std::istream& operator>> (std::istream& stream, worker& v);
public:
    bool operator == (const fullName& b) const;
    bool operator != (const fullName& b) const;

private:
    int department{};
    double salary{};

public:
    int getDepartment() const;
    double getSalary() const;

    void print() const;

    static std::vector<worker> getInitialWorkers(const std::string& fileName = "data.txt");
    static void saveWorkers(const std::vector<worker>& workers, const std::string& fileName = "data.txt");
};