#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

    static const int MIN_JOIN_YEAR = 1950;
    static const int MAX_JOIN_YEAR = 2025;

public:
    
    Member() : name("Noname"), memberId("000000"), yearJoined(2000) {}

    Member(const std::string& n, const std::string& id, int yj)

        : name(n), memberId(""), yearJoined(MIN_JOIN_YEAR) 
    {
        setMemberId(id);
        setYearJoined(yj);
    }

    std::string getName() const { return name; }
    std::string getMemberId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    void setName(const std::string& n) { name = n; }
    
    void setMemberId(const std::string& id) {
        if (id.empty()) {
            std::cerr << "Greshka: Member ID ne mozhe da bade prazhen. Zadaden e '000000'." << std::endl;
            memberId = "000000";
        } else {
            memberId = id;
        }
    }

    void setYearJoined(int yj) {
        if (yj >= MIN_JOIN_YEAR && yj <= MAX_JOIN_YEAR) {
            yearJoined = yj;
        } else {
            std::cerr << "Greshka: Godinata na chlenstvo (" << yj << ") e izvun diapazon ["
                      << MIN_JOIN_YEAR << "-" << MAX_JOIN_YEAR << "]. Zadadena e 2000." << std::endl;
            yearJoined = 2000;
        }
    }
    
    std::string toString() const {
        std::stringstream ss;
        ss << "Chitatel: " << name << ", ID: " << memberId << ", Chlen ot: " << yearJoined;
        return ss.str();
    }
};