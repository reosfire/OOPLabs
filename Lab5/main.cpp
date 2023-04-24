#include <iostream>
#include "../Lib/mylocale.h"
#include "../Lib/myio.h"

template <class T>
class array {
public:
    T* data;
    int size;

    explicit array(int size) : size(size), data(new T[size]) {}
};

template<class T>
void initialize(array<T> a) {
    for (int i = 0; i < a.size; ++i) {
        while (std::cin.fail()) {
            std::cin >> a.data[i];
            
            std::cin.clear();
            std::cin.ignore();
        }
    }
}
void initialize(array<double> a) {
    double read;
    int i = 0;
    while (i < a.size) {
        std::cin >> read;
        if (read > 10) a.data[i] = read;
        else continue;
        i++;
    }
}

template<class T>
int zeroesCount(array<T> a) {
    int result = 0;
    for (int i = 0; i < a.size; ++i) {
        if (a.data[i] == 0) result++;
    }

    return result;
}

int main() {
    useRussian();

    std::cout << "Введите 5 интов";
    array<int> a1(5);
    initialize(a1);
    std::cout << "Колличество нулей в первом массиве: " << zeroesCount<int>(a1) << std::endl;

    array<double> a2(5);
    initialize(a2);
    std::cout << "Колличество нулей во втором массиве: " << zeroesCount<double>(a2) << std::endl;

    system("pause");
    return 0;
}