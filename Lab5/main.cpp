#include <iostream>
#include "../Lib/mylocale.h"
#include "../Lib/myio.h"

template <class T>
class array {
public:
    T* data;
    int size;

    friend std::ostream& operator<< (std::ostream& stream, const array& v) {
        for (int i = 0; i < v.size; ++i) {
            stream << v.data[i] << ' ';
        }
        return stream;
    }

    explicit array(int size) : size(size), data(new T[size]) {}
    virtual ~array() {
        delete[] data;
    }
};

template<class T>
void initialize(const array<T>& a) {
    for (int i = 0; i < a.size; ++i) {
        std::cout << i + 1 << ": ";
        std::cin >> a.data[i];

        while (std::cin.fail()) {
            std::cout << "Вы ввели не то что ожидалось!!" << std::endl;
            std::cout << i + 1 << ": ";

            rewind(stdin);
            std::cin.clear();

            std::cin >> a.data[i];
        }
    }
}
double readDouble(int i) {
    double result;
    std::cout << i + 1 << ": ";
    std::cin >> result;

    while (std::cin.fail()) {
        std::cout << "Вы ввели не дабл!!" << std::endl;
        std::cout << i + 1 << ": ";

        rewind(stdin);
        std::cin.clear();

        std::cin >> result;
    }

    return result;
}
void initialize(const array<double>& a) {
    for (int i = 0; i < a.size; ++i) {
        double read = readDouble(i);

        while (read <= 10) {
            std::cout << "Числа должны быть больше 10!" << std::endl;
            read = readDouble(i);
        }

        a.data[i] = read;
    }
}

template<class T>
int zeroesCount(const array<T>& a) {
    int result = 0;
    for (int i = 0; i < a.size; ++i) {
        if (a.data[i] == 0) result++;
    }

    return result;
}

int main() {
    useRussian();

    std::cout << "Введите 5 интов" << std::endl;
    array<int> a1(5);
    initialize(a1);
    std::cout << "Массив: " << a1 << std::endl;
    std::cout << "Колличество нулей в первом массиве: " << zeroesCount<int>(a1) << std::endl << std::endl;

    std::cout << "Введите 5 даблов" << std::endl;
    array<double> a2(5);
    initialize(a2);
    std::cout << "Массив: " << a2 << std::endl;
    std::cout << "Колличество нулей во втором массиве: " << zeroesCount<double>(a2) << std::endl;

    system("pause");
    return 0;
}