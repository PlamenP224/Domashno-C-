#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

    void validateDates() {
        
        if (dueDate < startDate) {
            std::cerr << "Greshka vuv validatsiyata: Kraynata data (" << dueDate 
                      << ") ne mozhe da bade predi nachalnata data (" << startDate 
                      << "). Zadadeni sa ednakvi dati." << std::endl;
        
            dueDate = startDate;
        }
    }

public:
    Loan(const std::string& i, const std::string& mId, const std::string& sDate, const std::string& dDate)
        : isbn(i), memberId(mId), startDate(sDate), dueDate(dDate), returned(false)
    {
        validateDates();
    }

    void markReturned() {
        returned = true;
        std::cout << "Zaemat na kniga s ISBN " << isbn << " e markiran kato vurnat." << std::endl;
    }

    bool isOverdue(const std::string& today) const {
        if (returned) {
            return false;
        }
        
        return today > dueDate;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "Zaem | ISBN: " << isbn 
           << " | Chitatel ID: " << memberId 
           << " | Nachalo: " << startDate 
           << " | Kraen srok: " << dueDate 
           << " | Status: " << (returned ? "VURNATA" : "NEVURNATA");
        return ss.str();
    }
    
    std::string getIsbn() const { return isbn; }
    std::string getMemberId() const { return memberId; }
    std::string getStartDate() const { return startDate; }
    std::string getDueDate() const { return dueDate; }
    bool isReturned() const { return returned; }
    
};