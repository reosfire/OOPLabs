#pragma ones

#include "man.h"

class worker: man {
    friend std::ostream& operator<< (std::ostream& stream, worker const& v);
    friend std::istream& operator>> (std::istream& stream, worker& v);

private:
    int departmentNumber{};
    double salary{};
};