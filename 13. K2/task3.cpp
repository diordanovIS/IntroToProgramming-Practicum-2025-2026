#include <iostream>

void encrypt(char* str, int k) {

    if (!str || *str == '\0')
        return;

    if (*str >= 'a' && *str <= 'z') {
        char c = *str + k;

       if (c > 'z')
            c = c - 26;

        *str = c;
    }

    encrypt(str + 1, k);
} 

int main()
{
    char str1[] = "abc xyz";
    char str2[] = "hello world!";
    int k;
    std::cin >> k;
    encrypt(str1,k);
    std::cout << str1;
    encrypt(str2,k);
    std::cout << str2;
}
