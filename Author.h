#include <string>
#include <sstream>
#include <iostream>

class Author {
private:
    std::string name;
    int birthYear;

    static const int MIN_BIRTH_YEAR = 1850;
    static const int MAX_BIRTH_YEAR = 2025;

public:
    
    Author() : name("Unknown"), birthYear(MIN_BIRTH_YEAR) {}

    Author(const std::string& n, int by)
        : name(n), birthYear(MIN_BIRTH_YEAR)
    {
        setBirthYear(by);
    }

    std::string getName() const {
        return name;
    }

    int getBirthYear() const {
        return birthYear;
    }

    void setName(const std::string& n) {
        name = n;
    }

    void setBirthYear(int by) {
        if (by >= MIN_BIRTH_YEAR && by <= MAX_BIRTH_YEAR) {
            birthYear = by;
        } else {
        
            std::cerr << "Greshka: Godinata na razhdane (" << by << ") e izvun razumniya diapazon ["
                      << MIN_BIRTH_YEAR << "-" << MAX_BIRTH_YEAR << "]. Zadadena e stoynost "
                      << MIN_BIRTH_YEAR << "." << std::endl;
            birthYear = MIN_BIRTH_YEAR;
        }
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "Avtor: " << name << ", Godina na razhdane: " << birthYear;
        return ss.str();
    }
};