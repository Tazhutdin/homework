#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string name;                     // Фамилия
    std::string userId;                   // ID вида "USR_001"
    std::vector<std::string> borrowedBooks; // ISBN взятых книг
    int maxBooksAllowed;                  // Максимум книг

public:
    // Конструктор
    User(const std::string& name, const std::string& userId);

    // Getter-методы
    std::string getName() const;
    std::string getUserId() const;
    std::vector<std::string> getBorrowedBooks() const;
    int getMaxBooksAllowed() const;

    // Методы для работы с книгами
    bool canBorrowMore() const;
    void addBook(const std::string& isbn);
    void removeBook(const std::string& isbn);

    // Вывод профиля
    void displayProfile() const;

    // Установить максимальное количество книг
    void setMaxBooksAllowed(int max);
};

#endif // USER_H