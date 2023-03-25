#pragma ones

#include <vector>
#include <fstream>
#include "man.h"

class worker: public man {
    friend std::ostream& operator<< (std::ostream& stream, worker const& v);
    friend std::istream& operator>> (std::istream& stream, worker& v);
    bool operator == (const man& b);

private:
    int departmentNumber{};
    double salary{};

public:
    static std::vector<worker> getInitialWorkers(const std::string& fileName = "data.txt");
    static void saveWorkers(const std::vector<worker>& workers, const std::string& fileName = "data.txt");
};