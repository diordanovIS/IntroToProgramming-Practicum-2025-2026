#include <iostream>

const unsigned MAX_LEN = 100;

void printWord(const char* word)
{
    while(*word)
    {
        std::cout<<*word;
        word++;
    }
}

void print(char** matrix, size_t n)
{
    for(int i = n-1; i >= 0; i--)
    {
        printWord(matrix[i]);
        std::cout<<std::endl;
    }
}

size_t myStrLen(const char* str)
{
     if (!str)
        return 0; 
        
    size_t len = 0; 
    while(*str != '\0')
    {
        len++;
        str++;
    }
    
    return len;
}

char* compressWord(char* word, size_t len)
{
    size_t i = 0; 
    char* compressedWord = new char[len + 1];
    compressedWord[i] = word[i];
    for(size_t j = 1; j < len;j++)
    {
        if(!(compressedWord[i] == word[j]))
        {
            i++;
            compressedWord[i] = word[j];
        }
    }
    
    compressedWord[++i] = '\0';
    return compressedWord;
}

int myStrCmp(const char* fst,const char* snd)
{
    if (!fst || !snd)
        return 0;

    while (*fst && *snd && (*fst == *snd))
    {
        fst++;
        snd++;
    }

    return (*fst - *snd);
}

void freeMatChar(char** matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    int n;
    std::cin >> n;

    char** words = new char*[n]; 
    char temp[MAX_LEN + 1];      

    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        size_t len = myStrLen(temp);
        words[i] = compressWord(temp,len); 
    }

    print(words, n);
    freeMatChar(words, n);
}