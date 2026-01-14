#include <iostream>

const size_t SIZE = 7;

int sumArray(int* arr, size_t n) {
    
    if(n == 0)  
        return 0;
        
    return arr[n-1] + sumArray(arr, n-1); 
}

int main() {
    int arr[] = { 3, 4, 5, 2, 1, 7, 8 };

    std::cout << "Sum of elements is: " << sumArray(arr, SIZE);
}
