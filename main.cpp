#include <iostream>
#include <iomanip>
#include <string>
#include "Library.h"

using namespace std;

void separator(const string& title) {
    cout << "\n==========================================" << endl;
    cout << "  " << title << endl;
    cout << "==========================================" << endl;
}

int main() {

    const string TODAY = "2025-11-20"; 
    cout << "Dneshna data za testove: " << TODAY << endl;

    Library lib;

    separator("1. INITSIALIZATSIYA I DOBAVYANE");
    
    Author a1{"Ivan Vazov", 1850};
    Author a2{"Aleko Konstantinov", 1863};

    Book b1{"Pod igoto", a1, 1894, 25.50, "ISBN-001"};
    Book b2{"Nemili-nedragi", a1, 1895, 18.90, "ISBN-002"};
    Book b3{"Bai Ganyo", a2, 1895, 12.00, "ISBN-003"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.addMember(Member{"Petar Petrov", "M001", 2023});
    lib.addMember(Member{"Maria Dimova", "M002", 2024});
    lib.addMember(Member{"Nevaliden ID", "", 2020});  

    cout << "\n" << lib.toString() << "\n";

    separator("2. OPERATSII PO ZAEMANE");

    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17")) {
        cout << "Zaem: ISBN-001 za M001 uspeshno sazdaden." << endl;
    }
    
    lib.loanBook("ISBN-001", "M002", "2025-11-20", "2025-12-05");

    lib.loanBook("ISBN-002", "M999", "2025-11-20", "2025-12-05");

    separator("3. PROVERKA NA NALICHNOST I PROSROCHVANE");

    cout << "Nalichna ISBN-001 (zaeta)? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";

    cout << "Nalichna ISBN-003 (svobodna)? " << boolalpha << lib.isBookAvailable("ISBN-003") << "\n";
    
    cout << "\n";
    lib.returnBook("ISBN-001", "M001");
    
    cout << "Nalichna ISBN-001 sled vrashtane? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    
    separator("4. TARSENE PO AVTOR");
    
    cout << "Knigi ot Ivan Vazov:" << endl;
    auto vazovBooks = lib.findByAuthor("Ivan Vazov");
    for (const auto& bk : vazovBooks) {
        cout << " -> " << bk.toString() << "\n";
    }

    separator("5. FINALEN STATUS");
    cout << lib.toString() << "\n";

    return 0;
}