#include <iostream>
#include <locale>
#include <windows.h>
#include "Book.h"
#include "User.h"

void setRussianLocale() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
}

int main() {
    setRussianLocale();

    try {
        // Создаем пользователя
        User user("Иванов", "USR_001");
        user.displayProfile();

        // Добавляем книги
        user.addBook("978-5-17-70490-8");
        user.addBook("978-5-17-77192-5");
        user.displayProfile();

        // Пробуем добавить третью книгу
        user.addBook("978-0-13-110388-8");
        user.displayProfile();

        // Пробуем добавить четвертую (должна быть ошибка)
        user.addBook("123");

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }


    return 0;
}