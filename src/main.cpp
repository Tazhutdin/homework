#include <iostream>
#include <locale>
#include <windows.h>
#include "Book.h"
#include "User.h"
#include "Library.h"

void setRussianLocale() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
}

int main() {
    setRussianLocale();

    try {
        // Создаем библиотеку
        Library library;

        // Добавляем книги
        Book book1("Война и мир", "Лев Толстой", 1869, "978-5-17-70490-8");
        Book book2("C++ Primer", "Stanley Lippman", 2012, "978-0-13-110388-8");

        library.addBook(book1);
        library.addBook(book2);

        // Добавляем пользователей
        User user1("Иванов", "USR_001");
        User user2("Петров", "USR_002");

        library.addUser(user1);
        library.addUser(user2);

        // Показываем все
        library.displayAllBooks();
        library.displayAllUsers();

        // Выдаем книгу
        library.borrowBook("Иванов", "978-5-17-70490-8");

        // Показываем снова
        library.displayAllBooks();
        library.displayAllUsers();

        // Возвращаем книгу
        library.returnBook("978-5-17-70490-8");

        // Показываем финальное состояние
        library.displayAllBooks();

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    

    return 0;
}