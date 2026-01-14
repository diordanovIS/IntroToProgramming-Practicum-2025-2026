#include <iostream>

void replaceSpaces(char* str) {
    while (*str) {           
        if (*str == ' ') {   
            *str = '_';     
        }
        str++;               
    }
}

int main() {
    char str[100];

    std::cout << "Enter a string: ";
    // използваме getline за да прочетем цял ред с интервали
    std::cin.getline(str, 100); 

    replaceSpaces(str);

    std::cout << "After replacing spaces: " << str << std::endl;
}
