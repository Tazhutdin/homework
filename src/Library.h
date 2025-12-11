#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;      // Каталог книг
    std::vector<User> users;      // Список пользователей
    std::string dataFile;         // Путь к файлу данных

public:
    // Конструктор
    Library(const std::string& filename = "data/library_data.txt");

    // Методы для книг
    void addBook(const Book& book);
    Book* findBookByISBN(const std::string& isbn);
    void displayAllBooks() const;

    // Методы для пользователей
    void addUser(const User& user);
    User* findUserByName(const std::string& name);
    void displayAllUsers() const;

    // Методы выдачи/возврата
    void borrowBook(const std::string& userName, const std::string& isbn);
    void returnBook(const std::string& isbn);

    // Методы работы с файлами
    void saveToFile() const;
    void loadFromFile();

private:
    // Вспомогательные методы для работы с файлами
    void saveBooks(std::ofstream& file) const;
    void saveUsers(std::ofstream& file) const;
    void loadBooks(std::ifstream& file);
    void loadUsers(std::ifstream& file);
};

#endif // LIBRARY_H