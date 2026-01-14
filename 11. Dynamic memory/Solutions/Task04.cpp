#include <iostream>

unsigned myStrlen(const char* str) {
    if (!str) return 0;
    
    unsigned len = 0;
    while (*str) {
        str++;
        len++;
    }
    return len;
}

void myStrncpy(const char* src, char* dest, unsigned length) {
    for (unsigned i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void mergeSortedStrings(const char* str1, const char* str2, char* result) {

    while (*str1 && *str2) {
        if (*str1 <= *str2) {
            *result = *str1;
            str1++;
        } else {
           *result = *str2;
           str2++;
        }
        result++;
    }

    while (*str1){
         *result = *str1;
         result++;
         str1++;
    }
    
    while (*str2){
         *result = *str2;
         result++;
         str2++;
    }

    *result = '\0';
}

int main() {
    char str1[256], str2[256];

    std::cout << "Enter first sorted string: ";
    std::cin.getline(str1, 256);

    std::cout << "Enter second sorted string: ";
    std::cin.getline(str2, 256);

    unsigned len1 = myStrlen(str1);
    unsigned len2 = myStrlen(str2);

    char* result = new char[len1 + len2 + 1];

    mergeSortedStrings(str1, str2, result);

    std::cout << "Merged string: " << result << std::endl;

    delete[] result;
}
