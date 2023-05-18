#pragma once

#include "baseWorker.h"
#include "factory/IWorkerCreator.h"
#include <vector>
#include <fstream>
#include "../../Lib/myio.h"

class worker1 : public baseWorker {
private:
    std::string profession;
    date receiptDate;
public:
    worker1(const fullName &name, double salary, int department, std::string profession, date receiptDate);

    std::string getProfession();
    date getReceiptDate();

    void print() const override;
    void serialize(std::ofstream& stream) const override;
};
