#include <iostream>

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

unsigned myStrlen(const char* str) {
    if (!str) return 0;
    unsigned len = 0;
    while (*str) {
        str++;
        len++;
    }
    return len;
}

unsigned getWordLength(const char* sentence, unsigned i,unsigned& j, unsigned sentenceLen) {
    if (!sentence) return 0;
    
     unsigned length = 0;
     j = i;
     while (j < sentenceLen && isLetter(sentence[j])) {
        length++;
        j++;
    }
    
    return length;
}


void myStrncpy(const char* src, char* dest, unsigned length) {
    for (unsigned i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void splitWords(const char* sentence) {
    unsigned i = 0;
    unsigned sentenceLen = myStrlen(sentence);

    while (i < sentenceLen) {
        if (isLetter(sentence[i])) {
            
            unsigned j;           
            unsigned length = getWordLength(sentence, i, j,  sentenceLen);
             
            char* word = new char[length + 1];
            myStrncpy(sentence + i, word, length);

            std::cout << word << std::endl;

            delete[] word;

            i = j;
        } else {
            i++;
        }
    }
}

int main() {
    char* sentence = new char[256];
    std::cout << "Enter a sentence: " << std::endl;
    std::cin.getline(sentence, 256);

    splitWords(sentence);

    delete[] sentence;
}
