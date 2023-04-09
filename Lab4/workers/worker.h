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

    void print() const override;
};