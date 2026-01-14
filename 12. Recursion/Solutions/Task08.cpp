#include <iostream>

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

void swapCase(char* str) {
    
    if(!str)
       return;
    
    if(*str == '\0')  
        return;

    if(isLower(*str))      
        *str = *str - 'a' + 'A';
    else if(isUpper(*str)) 
        *str = *str - 'A' + 'a';

    swapCase(str + 1); 
}

int main() {
    
    char str[] = "eoPoEr";

    swapCase(str);

    std::cout << "Result: " << str << std::endl;
}
