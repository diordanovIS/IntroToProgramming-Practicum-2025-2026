#include <iostream>

void fillCounts(const char* ptr, int* counts) {
    
    if(!ptr || !counts)
        return;

    while (*ptr) {
        if (*ptr >= '0' && *ptr <= '9') {
            counts[*ptr - '0']++;
        }
        ptr++;
    }
}

void countsToString(const int* counts, char* resPtr) {

    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            *resPtr++ = '0' + i;
            *resPtr++ = ':';

            int n = counts[i];
            char buffer[5];
            int idx = 0;
            while (n > 0) {
                buffer[idx++] = '0' + (n % 10);
                n /= 10;
            }
            
            for (int j = idx - 1; j >= 0; j--) {
                *resPtr++ = buffer[j];
            }

            *resPtr++ = ' ';
        }
    }

    *resPtr = '\0';
}

int main() {
    char input[256], result[256];
    int counts[10]{ 0 };

    std::cout << "Enter digits: ";
    std::cin.getline(input, 256);

    fillCounts(input, counts);      
    countsToString(counts, result);  

    std::cout << "Output: " << result << std::endl;
}
