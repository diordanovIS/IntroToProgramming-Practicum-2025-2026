#include <iostream>

unsigned myStrlen(const char* str) {
    
    if(!str)
     return 0;
    
    if(*str == '\0')
        return 0;
        
    return 1 + myStrlen(str + 1);
}

bool isPalindrome(const char* str, int left, int right) {
    if(left >= right)       
        return true;
    if(str[left] != str[right]) 
        return false;
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    const char* str = "eopoe";

    int len = myStrlen(str);
    
    std::cout << str << " is palindrome: " 
                     << std::boolalpha << isPalindrome(str, 0, len - 1);
}
