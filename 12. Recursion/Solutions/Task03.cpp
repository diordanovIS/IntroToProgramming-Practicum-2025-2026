#include <iostream>

unsigned long long myPoweRec(unsigned num, unsigned p) {
    if(p == 0)
        return 1;
        
    return num * myPoweRec(num, p - 1);
}

int main() {
    std::cout << myPoweRec(3, 4); 
}
