#include <iostream>

void swap(char& ch1, char& ch2){
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void reverseString(char* str) {
    if (!str) 
       return;

    char* end = str;
    while (*end) {
        end++;
    }
    end--; 

    while (str < end) {
        swap(*str,*end);
        
        str++;
        end--;
    }
}

int main() {
    char str[100];

    std::cout << "Enter a string: " << std::endl;
    std::cin.getline(str, 100);

    reverseString(str);

    std::cout << "Reversed string: " << str << std::endl;
}
