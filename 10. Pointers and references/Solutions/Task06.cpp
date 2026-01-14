#include <iostream>

bool containsString(const char* str, const char* substr) {
    
    if(!str || !substr)
       return false;

    if (!*substr) 
        return true; 

    while (*str) {
        const char* strCpy = str;
        const char* subStrCpy = substr;

        while (*subStrCpy && *strCpy == *subStrCpy) {
            strCpy++;
            subStrCpy++;
        }

        if (!*subStrCpy) 
           return true; 

        str++;
    }

    return false;
}

int main() {
    char str[100], substr[100];

    std::cout << "Enter string: " << std::endl;
    std::cin >> str;
    std::cout << "Enter string to search: " << std::endl;
    std::cin >> substr;

    std::cout << std::boolalpha << containsString(str, substr) << std::endl;
}
