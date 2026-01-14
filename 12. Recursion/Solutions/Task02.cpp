#include <iostream>

unsigned long long fibonacci(unsigned n) {
    
    if(n == 1 || n == 2)
        return 1;
        
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << fibonacci(4);
}
