#include <iostream>
#include <string>

int main() {
    std::string str;

    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::cout << "Вы ввели: " << str << std::endl;

    return 0;
}

