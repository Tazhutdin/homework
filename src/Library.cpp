#include "Library.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

// Конструктор с загрузкой данных
Library::Library(const std::string& filename) : dataFile(filename) {
    try {
        loadFromFile();
        std::cout << "Данные загружены из файла: " << filename << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Файл не найден или поврежден. Создана пустая библиотека."
            << std::endl;
        // Создаем пустые векторы
        books.clear();
        users.clear();
    }
}

// Добавить книгу
void Library::addBook(const Book& book) {
    // Проверяем уникальность ISBN
    for (const auto& b : books) {
        if (b.getISBN() == book.getISBN()) {
            throw std::runtime_error("Книга с таким ISBN уже существует!");
        }
    }
    books.push_back(book);
}

// Найти книгу по ISBN (возвращает указатель!)
Book* Library::findBookByISBN(const std::string& isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;  // Возвращаем указатель на книгу
        }
    }
    return nullptr;  // Не нашли
}

// Показать все книги
void Library::displayAllBooks() const {
    std::cout << "\n=== КАТАЛОГ КНИГ ===" << std::endl;
    if (books.empty()) {
        std::cout << "Каталог пуст." << std::endl;
    }
    else {
        for (size_t i = 0; i < books.size(); ++i) {
            std::cout << "\nКнига #" << i + 1 << ":";
            books[i].displayInfo();
        }
    }
    std::cout << "===================\n" << std::endl;
}

// Добавить пользователя
void Library::addUser(const User& user) {
    // Проверяем уникальность имени
    for (const auto& u : users) {
        if (u.getName() == user.getName()) {
            throw std::runtime_error("Пользователь с такой фамилией уже существует!");
        }
    }
    users.push_back(user);
}

// Найти пользователя по фамилии
User* Library::findUserByName(const std::string& name) {
    for (auto& user : users) {
        if (user.getName() == name) {
            return &user;  // Возвращаем указатель на пользователя
        }
    }
    return nullptr;  // Не нашли
}

// Показать всех пользователей
void Library::displayAllUsers() const {
    std::cout << "\n=== СПИСОК ПОЛЬЗОВАТЕЛЕЙ ===" << std::endl;
    if (users.empty()) {
        std::cout << "Нет зарегистрированных пользователей." << std::endl;
    }
    else {
        for (size_t i = 0; i < users.size(); ++i) {
            std::cout << "\nПользователь #" << i + 1 << ":";
            users[i].displayProfile();
        }
    }
    std::cout << "=============================\n" << std::endl;
}

// Выдать книгу пользователю
void Library::borrowBook(const std::string& userName, const std::string& isbn) {
    // Находим пользователя
    User* user = findUserByName(userName);
    if (!user) {
        throw std::runtime_error("Пользователь не найден!");
    }

    // Находим книгу
    Book* book = findBookByISBN(isbn);
    if (!book) {
        throw std::runtime_error("Книга не найдена!");
    }

    // Проверяем, может ли пользователь взять книгу
    if (!user->canBorrowMore()) {
        throw std::runtime_error("Достигнут лимит книг у пользователя!");
    }

    // Выдаем книгу
    book->borrowBook(userName);
    user->addBook(isbn);

    std::cout << "Книга успешно выдана!" << std::endl;
}

// Вернуть книгу
void Library::returnBook(const std::string& isbn) {
    // Находим книгу
    Book* book = findBookByISBN(isbn);
    if (!book) {
        throw std::runtime_error("Книга не найдена!");
    }

    // Проверяем, выдана ли книга
    if (book->getIsAvailable()) {
        throw std::runtime_error("Книга уже в библиотеке!");
    }

    // Находим пользователя, который взял книгу
    std::string userName = book->getBorrowedBy();
    User* user = findUserByName(userName);

    if (user) {
        user->removeBook(isbn);
    }

    // Возвращаем книгу
    book->returnBook();

    std::cout << "Книга успешно возвращена!" << std::endl;
}

// СОХРАНЕНИЕ В ФАЙЛ (частично - полную реализацию сделаем на неделе 5)
void Library::saveToFile() const {
    std::cout << "Сохранение будет реализовано на следующем этапе" << std::endl;
}

// ЗАГРУЗКА ИЗ ФАЙЛА (частично)
void Library::loadFromFile() {
    std::cout << "Загрузка будет реализована на следующем этапе" << std::endl;
}