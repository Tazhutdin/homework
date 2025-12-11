#include <iostream>
#include <locale>
#include <windows.h>
#include "Book.h"

void setRussianLocale() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
}

int main() {
    setRussianLocale();

    try {
        // Создаем книгу
        Book book("Война и мир", "Лев Толстой", 1869, "978-5-17-70490-8");

        // Тестируем методы
        book.displayInfo();

        // Пробуем выдать книгу
        book.borrowBook("Иванов");
        book.displayInfo();

        // Пробуем вернуть книгу
        book.returnBook();
        book.displayInfo();

        // Пробуем ошибочный год
        Book badBook("Тест", "Автор", 1000, "123");

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}