#include <iostream>

bool isSpace(char ch) { return ch == ' '; }
bool isTab(char ch) { return ch == '\t'; }
bool isComma(char ch) { return ch == ','; }
bool isDot(char ch) { return ch == '.'; }
bool isExcl(char ch) { return ch == '!'; }
bool isQuest(char ch) { return ch == '?'; }
bool isTwoDots(char ch) { return ch == ':'; }
bool isDotComma(char ch) { return ch == ';'; }


bool isDelimiter(char ch) {
    return isSpace(ch) || isTab(ch)  || 
           isComma(ch) || isDot(ch) || 
           isExcl(ch) ||  isQuest(ch) ||
           isTwoDots(ch) || isDotComma(ch);
}

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;

    while (*str) {
        if (!isDelimiter(*str)) {
            if (!inWord) {
                count++;     
                inWord = true;
            }
        } else {
            inWord = false; 
        }
        str++;
    }

    return count;
}

int main() {
    char str[200];

    std::cout << "Enter a string: ";
    std::cin.getline(str, 200); 

    std::cout << "Number of words: " << countWords(str) << std::endl;
}
