#include <iostream>

bool isSubsequence(const char* p1, const char* p2) {

    while (*p1 && *p2) {
        if (*p1 == *p2) {
            p1++; 
        }
        p2++;
    }

    return *p1 == '\0';
}

int main() {
    char str1[257], str2[257];

    std::cout << "Enter first string: ";
    std::cin.getline(str1, 257);

    std::cout << "Enter second string: ";
    std::cin.getline(str2, 257);

        std::cout << std::boolalpha << isSubsequence(str1, str2) << std::endl;
}
