#include "Book.h"
#include <iostream>
#include <ctime>  // Для получения текущего года

// Конструктор с валидацией года
Book::Book(const std::string& title,
    const std::string& author,
    int year,
    const std::string& isbn)
    : title(title), author(author), year(year), isbn(isbn) {

    // Валидация года (обязательное требование)
    time_t now = time(0);
    tm* localTime = localtime(&now);
    int currentYear = 1900 + localTime->tm_year;

    if (year < 1450 || year > currentYear) {
        throw std::invalid_argument("Некорректный год издания!");
    }

    // По умолчанию книга доступна
    isAvailable = true;
    borrowedBy = "";
}

// Getter-методы
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

std::string Book::getISBN() const {
    return isbn;
}

bool Book::getIsAvailable() const {
    return isAvailable;
}

std::string Book::getBorrowedBy() const {
    return borrowedBy;
}

// Выдать книгу
void Book::borrowBook(const std::string& userName) {
    if (!isAvailable) {
        throw std::runtime_error("Книга уже выдана!");
    }
    isAvailable = false;
    borrowedBy = userName;
}

// Вернуть книгу
void Book::returnBook() {
    if (isAvailable) {
        throw std::runtime_error("Книга уже в библиотеке!");
    }
    isAvailable = true;
    borrowedBy = "";
}

// Вывести информацию о книге
void Book::displayInfo() const {
    std::cout << "\n=== Информация о книге ===" << std::endl;
    std::cout << "Название: " << title << std::endl;
    std::cout << "Автор: " << author << std::endl;
    std::cout << "Год: " << year << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Статус: " << (isAvailable ? "Доступна" : "Выдана") << std::endl;
    if (!isAvailable) {
        std::cout << "Выдана: " << borrowedBy << std::endl;
    }
    std::cout << "=========================\n" << std::endl;
}