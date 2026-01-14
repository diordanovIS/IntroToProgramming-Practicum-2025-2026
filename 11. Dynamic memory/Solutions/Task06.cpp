#include <iostream>

unsigned long long extractNumber(const char* ptr) {
    
    if(!ptr)
        return 0;
        
    unsigned long long number = 0;

    while (*ptr) {
        if (*ptr >= '0' && *ptr <= '9') {
            number = number * 10 + (*ptr - '0');
        }
        ptr++;
    }

    return number;
}

int main() {
    char input[65];

    std::cout << "Enter a string (max 64 chars): ";
    std::cin.getline(input, 65);

    unsigned long long number = extractNumber(input);
    std::cout << "Number: " << number << std::endl;
}

