#pragma ones
#include <string>

class man {
protected:
    std::string name;
    std::string surname;
public:
    std::string getName() const {
        return name;
    }
    std::string getSurname() const {
        return surname;
    }
};
