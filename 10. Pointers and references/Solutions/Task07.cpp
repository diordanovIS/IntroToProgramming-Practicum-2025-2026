#include <iostream>

bool isUpper(char ch){
    return ch>= 'A' && ch <= 'Z';
}

bool isLower(char ch){
    return ch>= 'a' && ch <= 'z';
}

void toUpper(char* str) {
    while (*str) {
        if (isLower(*str)) {
            *str = *str - ('a' - 'A'); 
        }
        str++;
    }
}

void toLower(char* str) {
    while (*str) {
        if (isUpper(*str)) {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

int main() {
    char str[100];

    std::cout << "Enter string: ";
    std::cin >> str;

    toUpper(str);
    std::cout << "After toUpper: " << str << std::endl;

    toLower(str);
    std::cout << "After toLower: " << str << std::endl;
}
