#include <iostream>

bool isPalindrome(const int* arr, int size) {
    const int* left = arr;          
    const int* right = arr + size - 1; 

    while (left < right) {
        if (*left != *right)
           return false; 
           
        left++;
        right--;
    }
    return true;
}

int main() {
    int arr[100];
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    if (isPalindrome(arr, size))
        std::cout << "The array is a palindrome." << std::endl;
    else
        std::cout << "The array is not a palindrome." << std::endl;
}
