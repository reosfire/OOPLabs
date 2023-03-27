#include "consoleInteractor.h"
#include "../Lib/mylocale.h"

int main() {
    useRussian();

    consoleInteractor interactor;
    interactor.start();

    return 0;
}