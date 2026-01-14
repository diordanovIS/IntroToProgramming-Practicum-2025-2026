#include <iostream>

const size_t SIZE = 7;

bool binarySearch(int* arr, int left, int right, int elToSearch) {
    if(left > right)  
        return false;
    
    int mid = left + (right - left) / 2;

    if(arr[mid] == elToSearch)
        return true;          
    else if(elToSearch < arr[mid])
        return binarySearch(arr, left, mid - 1, elToSearch);  
    else
        return binarySearch(arr, mid + 1, right, elToSearch); 
}

int main() {
    int arr[] = { 3, 4, 5, 2, 1, 7, 8 };
    int elToSearch = 6;

    std::cout << elToSearch << " is found: " << std::boolalpha << binarySearch(arr, 0, SIZE -1, elToSearch);
}
