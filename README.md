# Библиотечна система (Library System)

## Описание
Проектът „Библиотечна система“ е малка C++ система, която моделира работа с книги, автори и читатели, включително управление на заеми.  
Той демонстрира използването на основни обектно-ориентирани концепции:

- Конструктори и деструктори  
- Капсулация и достъп чрез getters и setters  
- Const-коректност и валидация на данни  
- Статични членове и методи  
- Работа с вектори за колекции  

---

## Структура на проекта

|
├── src/
|   ├── Author.h
|   ├── Book.h
|   ├── Member.h
|   ├── Loan.h
|   ├── Library.h
|   └── main.cpp  // Съдържа main() функцията за демонстрация
|
└── README.md


## Класове

### **Author**
Представя автор на книги.

**Членове:**
- `std::string name` — име на автора  
- `int birthYear` — година на раждане  
- `static const int MIN_BIRTH_YEAR, MAX_BIRTH_YEAR` — валиден диапазон

**Методи:**
- Конструктори: по подразбиране и с параметри  
- `getName()`, `getBirthYear()`  
- `setName()`, `setBirthYear(int)` с валидация  
- `toString()` — текстово описание  

---

### **Book**
Представя книга.

**Членове:**
- `std::string title` — заглавие  
- `Author author` — автор  
- `int year` — година на издаване  
- `double price` — цена  
- `std::string isbn` — уникален идентификатор  
- `static int totalBooks` — брой създадени книги

**Методи:**
- Конструктори и деструктори  
- Getters и setters с валидация  
- `toString()` — текстово описание  
- `static int getTotalBooks()`  

---

### **Member**
Представя читател на библиотеката.

**Членове:**
- `std::string name` — име  
- `std::string memberId` — уникален идентификатор  
- `int yearJoined` — година на присъединяване  

**Методи:**
- Конструктори  
- Getters и setters с валидация  
- `toString()`  

---

### **Loan**
Представя заем на книга.

**Членове:**
- `std::string isbn`  
- `std::string memberId`  
- `std::string startDate, dueDate`  
- `bool returned`  

**Методи:**
- Конструктор с валидация на дати  
- `markReturned()` — маркира като върната  
- `isOverdue(const std::string& today)` — проверка за просрочие  
- `toString()`  

---

### **Library**
Управлява колекцията от книги, членове и заеми.

**Членове:**
- `std::vector<Book> books`  
- `std::vector<Member> members`  
- `std::vector<Loan> loans`  

**Методи:**
- `addBook(const Book&)`  
- `addMember(const Member&)`  
- `hasBook(const std::string& isbn)`  
- `isBookAvailable(const std::string& isbn)`  
- `loanBook(...)`  
- `returnBook(...)`  
- `findByAuthor(const std::string&)`  
- `toString()` — обобщена информация  

---

## Компилация и изпълнение

Отворете терминал в директорията на проекта и изпълнете:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o main
./main
Примерен изход
yaml
Копиране на код
Dneshna data za testove: 2025-11-20

==========================================
  1. INITSIALIZATSIYA I DOBAVYANE
==========================================
Yspeshno dobavena kniga: Pod igoto
Yspeshno dobavena kniga: Nemili-nedragi
Yspeshno dobavena kniga: Bai Ganyo
Yspeshno dobaven chitatel: Petar Petrov
Yspeshno dobaven chitatel: Maria Dimova
Greshka: Member ID ne mozhe da bade prazhen. Zadaden e '000000'.

--- Obobshtena informatsiya za Bibliotekata ---
Obsht broy knigi: 3
Obsht broy registrirani chlenove: 3
Obsht broy zaemi (istoriya): 0
Aktivni (nepriklyucheni) zaemi: 0

==========================================
  2. OPERATSII PO ZAEMANE
==========================================
Yspeshno zaemane: Kniga ISBN-001 na chitatel M001
Greshka: Kniga s ISBN ISBN-001 veche e zaeta.
Greshka: Chitatel s ID M999 ne e nameren.

==========================================
  3. PROVERKA NA NALICHNOST I PROSROCHVANE
==========================================
Nalichna ISBN-001 (zaeta)? false
Nalichna ISBN-003 (svobodna)? true

Zaemat na kniga s ISBN ISBN-001 e markiran kato vurnat.
Nalichna ISBN-001 sled vrashtane? true

==========================================
  4. TARSENE PO AVTOR
==========================================
Knigi ot Ivan Vazov:
 -> Kniga: Pod igoto
  - Avtor: Ivan Vazov, Godina na razhdane: 1850
  - Godina: 1894, Cena: 25.5 lv., ISBN: ISBN-001
 -> Kniga: Nemili-nedragi
  - Avtor: Ivan Vazov, Godina na razhdane: 1850
  - Godina: 1895, Cena: 18.9 lv., ISBN: ISBN-002

==========================================
  5. FINALEN STATUS
==========================================
--- Obobshtena informatsiya za Bibliotekata ---
Obsht broy knigi: 3
Obsht broy registrirani chlenove: 3
Obsht broy zaemi (istoriya): 2
Aktivni (nepriklyucheni) zaemi: 1


Автор
Име: [Plamen Petkov]

Курс: 22425

Дата: [05.12.2025]
