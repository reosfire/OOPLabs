#pragma ones
#include <string>

class man {
private:
    friend std::istream& operator>> (std::istream& stream, man& v);

protected:
    std::string name;
    std::string surname;
public:
    std::string getName() const;
    std::string getSurname() const;
};
