#pragma ones

#include <vector>
#include <list>
#include <fstream>
#include "man.h"
#include "../Lib/myio.h"

class worker: public man {
private:
    friend std::ostream& operator<< (std::ostream& stream, worker const& v);
    friend std::istream& operator>> (std::istream& stream, worker& v);
public:
    bool operator == (const man& b) const;
    bool operator != (const man& b) const;

private:
    int department{};
    double salary{};

public:
    int getDepartment() const;
    double getSalary() const;

    void print() const;

    static std::list<worker> getInitialWorkers(const std::string& fileName = "data.txt");
    static void saveWorkers(const std::list<worker>& workers, const std::string& fileName = "data.txt");
};