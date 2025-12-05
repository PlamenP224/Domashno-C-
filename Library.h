#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

    std::vector<Book>::const_iterator findBook(const std::string& isbn) const {
        return std::find_if(books.begin(), books.end(), 
            [&isbn](const Book& b) { return b.getIsbn() == isbn; });
    }

    std::vector<Member>::const_iterator findMember(const std::string& memberId) const {
        return std::find_if(members.begin(), members.end(), 
            [&memberId](const Member& m) { return m.getMemberId() == memberId; });
    }

public:
    Library() = default;
    void addBook(const Book& b) {
        if (!hasBook(b.getIsbn())) {
            books.push_back(b);
            std::cout << "Yspeshno dobavena kniga: " << b.getTitle() << std::endl;
        } else {
            std::cout << "Greshka: Kniga s ISBN " << b.getIsbn() << " veche sushtestvuva." << std::endl;
        }
    }

    void addMember(const Member& m) {
        if (findMember(m.getMemberId()) == members.end()) {
            members.push_back(m);
            std::cout << "Yspeshno dobaven chitatel: " << m.getName() << std::endl;
        } else {
            std::cout << "Greshka: Chitatel s ID " << m.getMemberId() << " veche sushtestvuva." << std::endl;
        }
    }

    bool hasBook(const std::string& isbn) const {
        return findBook(isbn) != books.end();
    }

    bool isBookAvailable(const std::string& isbn) const {
        if (!hasBook(isbn)) {
            return false;
        }
        
        return std::none_of(loans.begin(), loans.end(), 
            [&isbn](const Loan& l) { 
                return l.getIsbn() == isbn && !l.isReturned(); 
            });
    }

    bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
        if (!hasBook(isbn)) {
            std::cout << "Greshka: Kniga s ISBN " << isbn << " ne e namerena." << std::endl;
            return false;
        }
        if (findMember(memberId) == members.end()) {
            std::cout << "Greshka: Chitatel s ID " << memberId << " ne e nameren." << std::endl;
            return false;
        }
        if (!isBookAvailable(isbn)) {
            std::cout << "Greshka: Kniga s ISBN " << isbn << " veche e zaeta." << std::endl;
            return false;
        }
        Loan newLoan(isbn, memberId, start, due);
        loans.push_back(newLoan);
        std::cout << "Yspeshno zaemane: Kniga " << isbn << " na chitatel " << memberId << std::endl;
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {

        auto it = std::find_if(loans.begin(), loans.end(), 
            [&isbn, &memberId](const Loan& l) {
                return l.getIsbn() == isbn && l.getMemberId() == memberId && !l.isReturned();
            });

        if (it != loans.end()) {

            it->markReturned();
            return true;
        }

        std::cout << "Greshka: Ne e nameren aktivен zaem za ISBN " << isbn 
                  << " ot chitatel " << memberId << "." << std::endl;
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& book : books) {
            if (book.getAuthor().getName() == authorName) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::string toString() const {
        std::stringstream ss;
        
        int activeLoans = 0;
        for (const auto& loan : loans) {
            if (!loan.isReturned()) {
                activeLoans++;
            }
        }

        ss << "--- Obobshtena informatsiya za Bibliotekata ---" << "\n"
           << "Obsht broy knigi: " << books.size() << "\n"
           << "Obsht broy registrirani chlenove: " << members.size() << "\n"
           << "Obsht broy zaemi (istoriya): " << loans.size() << "\n"
           << "Aktivni (nepriklyucheni) zaemi: " << activeLoans;
        return ss.str();
    }
};