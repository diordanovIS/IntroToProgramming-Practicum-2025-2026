#include <iostream>

bool isUpper(char ch) { return ch >= 'A' && ch <= 'Z'; }
bool isLower(char ch) { return ch >= 'a' && ch <= 'z'; }

char toLowerChar(char ch) {
    if (isUpper(ch)) 
       return ch + ('a' - 'A');
       
    return ch;
}

void toLowerString(const char* str, char* lowerStr) {
    while (*str) {
        *lowerStr = toLowerChar(*str);
        str++;
        lowerStr++;
    }
    *lowerStr = '\0';
}

bool isLetter(char ch) {
    return isUpper(ch) || isLower(ch);
}

int myStrcmp(const char* fst, const char* snd) {
    if (!fst || !snd) 
       return 0;
       
    while (*fst && *snd && *fst == *snd) { 
        fst++; 
        snd++;
    }
    
    return (*fst - *snd);
}

char* getWord(const char*& string) {
    while (*string && !isLetter(*string))
       string++;
       
    const char* start = string;
    while (*string && isLetter(*string))
       string++;
       
    unsigned length = string - start;
    if (length == 0) 
       return nullptr;
       
    char* word = new char[length + 1];
    for (unsigned i = 0; i < length; i++) 
       word[i] = start[i];
       
    word[length] = '\0';
    
    return word;
}

char* getSmallestWord(const char* string) {
    if (!string || *string == '\0') 
       return nullptr;
       
    char* smallestWord = nullptr;
    while (*string) {
        char* currentWord = getWord(string);
        if (currentWord) {
            if (!smallestWord || myStrcmp(currentWord, smallestWord) < 0) {
                delete[] smallestWord;
                smallestWord = currentWord;
            } else {
                delete[] currentWord;
            }
        }
    }
    return smallestWord;
}

int main() {
    const char* myString = "\"Things do not change; we Change.\" - Henry David    Thoreau";
    
    char lowerStr[300];
    toLowerString(myString, lowerStr);
    
    char* smallestWord = getSmallestWord(lowerStr);

    std::cout << "Smallest word: " << smallestWord << std::endl;
    delete[] smallestWord;
}
