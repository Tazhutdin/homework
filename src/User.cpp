#include "User.h"
#include <iostream>
#include <algorithm>  // Для find()

// Конструктор
User::User(const std::string& name, const std::string& userId)
    : name(name), userId(userId), maxBooksAllowed(3) {
    // borrowedBooks пустой по умолчанию
}

// Getter-методы
std::string User::getName() const {
    return name;
}

std::string User::getUserId() const {
    return userId;
}

std::vector<std::string> User::getBorrowedBooks() const {
    return borrowedBooks;
}

int User::getMaxBooksAllowed() const {
    return maxBooksAllowed;
}

// Проверка, может ли взять еще книги
bool User::canBorrowMore() const {
    return borrowedBooks.size() < maxBooksAllowed;
}

// Добавить книгу (по ISBN)
void User::addBook(const std::string& isbn) {
    // Проверяем, не превышен ли лимит
    if (!canBorrowMore()) {
        throw std::runtime_error("Достигнут лимит книг!");
    }

    // Проверяем, нет ли уже этой книги
    if (std::find(borrowedBooks.begin(), borrowedBooks.end(), isbn)
        != borrowedBooks.end()) {
        throw std::runtime_error("Эта книга уже у пользователя!");
    }

    borrowedBooks.push_back(isbn);
}

// Убрать книгу из списка
void User::removeBook(const std::string& isbn) {
    // Ищем книгу в списке
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), isbn);

    if (it == borrowedBooks.end()) {
        throw std::runtime_error("У пользователя нет такой книги!");
    }

    borrowedBooks.erase(it);
}

// Вывести профиль пользователя
void User::displayProfile() const {
    std::cout << "\n=== Профиль пользователя ===" << std::endl;
    std::cout << "Фамилия: " << name << std::endl;
    std::cout << "ID: " << userId << std::endl;
    std::cout << "Лимит книг: " << borrowedBooks.size()
        << "/" << maxBooksAllowed << std::endl;

    std::cout << "Взятые книги (ISBN): ";
    if (borrowedBooks.empty()) {
        std::cout << "нет";
    }
    else {
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            std::cout << borrowedBooks[i];
            if (i != borrowedBooks.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << "\n============================\n" << std::endl;
}

// Установить максимальное количество книг
void User::setMaxBooksAllowed(int max) {
    if (max < 0) {
        throw std::invalid_argument("Лимит не может быть отрицательным!");
    }
    maxBooksAllowed = max;
}