#include <iostream>

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

void countLetters(const char* str, int& lower, int& upper) {
    
    if(!str)
       return;
    
    if(*str == '\0') 
        return;

    if(isLower(*str))
        lower++;
    else if(isUpper(*str))
        upper++;

    countLetters(str + 1, lower, upper); 
}

int main() {
    const char* str = "eoPoEr";

    int lower = 0;
    int upper = 0;

    countLetters(str, lower, upper);

    std::cout << "Lower letters: " << lower << std::endl;
    std::cout << "Upper letters: " << upper << std::endl;
}
