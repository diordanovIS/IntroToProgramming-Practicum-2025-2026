#include <iostream>

bool isUpper(char ch) { return ch >= 'A' && ch <= 'Z'; }
bool isLower(char ch) { return ch >= 'a' && ch <= 'z'; }

bool isLetter(char ch) {
    return isUpper(ch)  || isLower(ch);
}

char toLower(char ch) {
    return isUpper(ch) ? ch + ('a' - 'A') : ch;
}

bool areWordsEqual(const char* start1, const char* end1, const char* start2, const char* end2) {
    while (start1 < end1 && start2 < end2) {
        if (toLower(*start1) != toLower(*start2)) 
           return false;
           
        start1++;
        start2++;
    }
    return (start1 == end1 && start2 == end2);
}

void copyWord(const char* start, const char* end, char* dest) {
    while (start < end) 
       *dest++ = *start++;
       
    *dest = '\0';
}

bool nextWord(const char*& ptr, const char*& start, const char*& end) {
    while (*ptr && !isLetter(*ptr)) 
       ptr++; 
       
    if (!*ptr) 
       return false;

    start = ptr;
    
    while (*ptr && isLetter(*ptr)) 
       ptr++;
       
    end = ptr;
    return true;
}

void findMostFrequentWord(const char* str, char* result) {
    
    if(!str || !result)
       return;
     
    result[0] = '\0';
    const char* freqStart = nullptr;
    const char* freqEnd = nullptr;
    int maxCount = 0;

    const char* ptr1 = str;
    const char *start1, *end1;

    while (nextWord(ptr1, start1, end1)) {
        int count = 0;
        const char* ptr2 = str;
        const char *start2, *end2;

        while (nextWord(ptr2, start2, end2)) {
            if (areWordsEqual(start1, end1, start2, end2))
               count++;
        }

        if (count > maxCount) {
            maxCount = count;
            freqStart = start1;
            freqEnd = end1;
        }
    }

    if (freqStart && freqEnd) 
       copyWord(freqStart, freqEnd, result);
}

int main() {
    char str[200];
    char result[100];

    std::cout << "Enter a string: ";
    std::cin.getline(str, 200);

    findMostFrequentWord(str, result);

    std::cout << "Most frequent word: " << result << std::endl;
}
