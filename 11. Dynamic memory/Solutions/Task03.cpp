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

unsigned countDigits(unsigned num){
    unsigned cnt = 0;
    
    while(num > 0){
        cnt++;
        num/=10;
    }
    
    return cnt;
}

char* intToStr(int number) {
  
    if (number == 0) {
        char* zeroStr = new char[2];
        zeroStr[0] = '0';
        zeroStr[1] = '\0';
        return zeroStr;
    }

    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    int temp = number;
    int digits = countDigits(temp);

    int size = digits + (isNegative ? 1 : 0) + 1;
    char* str = new char[size];
    str[size - 1] = '\0';

    int index = size - 2;
    while (number > 0) {
        str[index--] = '0' + (number % 10);
        number /= 10;
    }

    if (isNegative)
        str[0] = '-';

    return str;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    char* str = intToStr(n);

    std::cout << "Output: " << str << std::endl;

    delete[] str;
}
