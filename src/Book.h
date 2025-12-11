#ifndef BOOK_H  // Защита от повторного включения
#define BOOK_H

#include <string>

class Book {
private:  // Приватные поля (инкапсуляция)
    std::string title;      // Название
    std::string author;     // Автор
    int year;               // Год издания
    std::string isbn;       // ISBN
    bool isAvailable;       // Доступна ли
    std::string borrowedBy; // Кто взял

public:  // Публичные методы
    // Конструктор
    Book(const std::string& title,
        const std::string& author,
        int year,
        const std::string& isbn);

    // Getter-методы (получить значения)
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getISBN() const;
    bool getIsAvailable() const;
    std::string getBorrowedBy() const;

    // Методы для работы с книгой
    void borrowBook(const std::string& userName);
    void returnBook();
    void displayInfo() const;
};

#endif // BOOK_H