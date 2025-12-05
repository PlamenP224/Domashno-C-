#include <string>
#include <sstream>
#include <iostream>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static const int MIN_YEAR = 1850;
    static const int MAX_YEAR = 2025;
    
    static int totalBooks;

public:

    Book() : title("Unknown Title"), author(), year(MIN_YEAR), price(0.0), isbn("N/A") {
        totalBooks++;
    }

    Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
        
        : title(t), author(a), year(MIN_YEAR), price(0.0), isbn(i)
    {
        setYear(y);
        setPrice(p);
        totalBooks++;
    }

    ~Book() {
        totalBooks--;
    }

    Book(const Book& other) = default;

    Book& operator=(const Book& other) = default;

    Book(Book&& other) = default;

    Book& operator=(Book&& other) = default;

    std::string getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    std::string getIsbn() const { return isbn; }

    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const Author& a) { author = a; }
    void setIsbn(const std::string& i) { isbn = i; }

    void setPrice(double p) {
        if (p >= 0.0) {
            price = p;
        } else {
            std::cerr << "Greshka: Cena " << p << " ne mozhe da e otritsatelna. Zadadena e 0.0." << std::endl;
            price = 0.0;
        }
    }

    void setYear(int y) {
        if (y >= MIN_YEAR && y <= MAX_YEAR) {
            year = y;
        } else {
            std::cerr << "Greshka: Godina " << y << " e izvun diapazon [" 
                      << MIN_YEAR << "-" << MAX_YEAR << "]. Zadadena e " << MIN_YEAR << "." << std::endl;
            year = MIN_YEAR;
        }
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "Kniga: " << title << "\n"
           << "  - " << author.toString() << "\n"
           << "  - Godina: " << year << ", Cena: " << price << " lv., ISBN: " << isbn;
        return ss.str();
    }

    static int getTotalBooks() {
        return totalBooks;
    }
};

int Book::totalBooks = 0;