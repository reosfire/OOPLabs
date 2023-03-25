#include "worker.h"
#include "../Lib/myio.h"

std::ostream &operator<<(std::ostream &stream, const worker &worker) {
    stream << worker.salary;
    stream << worker.departmentNumber;
    return stream;
}

std::istream &operator>>(std::istream &stream, worker &worker) {
    worker.departmentNumber = readInt(stream);
    worker.salary = readDouble(stream);
    return stream;
}
