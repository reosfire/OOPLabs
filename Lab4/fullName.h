#pragma ones

#include <iostream>

class fullName {
private:
    friend std::ostream& operator<< (std::ostream& stream, fullName const& v);
    friend std::istream& operator>> (std::istream& stream, fullName& v);

    std::string name;
    std::string surname;
public:
    bool operator ==(const fullName& other);
    bool operator !=(const fullName& other);

    std::string getName() const;
    std::string getSurname() const;
};