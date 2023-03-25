#include <clocale>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <fstream>

#include "../Lib/mylocale.h"
#include "worker.h"
#include "../Lib/myio.h"

#define RAW_PROVIDER 1
#define EQUIPMENT_PROVIDER 2

using namespace std;

vector<worker> getInitialWorkers() {
    ifstream file("data.txt");

    if (!file.is_open()) return {};

    int count = readInt(file);
    vector<worker> result(count);

    for (int i = 0; i < count; ++i) {
        cin >> result[i];
    }

    file.close();
    return result;
}

void save(vector<worker>& workers) {

}

int main() {
    useRussian();

    vector<worker> workers = getInitialWorkers();

    while (true) {
        int command = readInt();
    }

exit:
    save(workers);
    return 0;
}