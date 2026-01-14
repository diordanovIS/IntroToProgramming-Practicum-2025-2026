#include <iostream>

void rearrange(int* arr, int n, int pivot) {
    int pos = 0;

    for (size_t i = 0; i < n; i++) {
        if (arr[i] < pivot) {
            int temp = arr[i];
            for (int j = i; j > pos; j--) {
                arr[j] = arr[j - 1];
            }
            arr[pos] = temp;
            pos++;
        }
    }

    for (size_t i = pos; i < n; i++) {
        if (arr[i] == pivot) {
            int temp = arr[i];
            for (int j = i; j > pos; j--) {
                arr[j] = arr[j - 1];
            }
            arr[pos] = temp;
            pos++;
        }
    }
}

void getArray(int* arr, size_t size) {

    for (size_t i = 0; i < size; i++) {
        std::cout << "Enter element: " << std::endl;
        std::cin >> arr[i];
    }
    
}

void printArray(int* arr, size_t size) {
    
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    
}

int main() {
    
    size_t n;
    std::cout << "Enter count of array elements: " << std::endl;
    std::cin >> n;

    int* arr = new int[n];

    getArray(arr, n);

    int pivot;
    std::cout << "Enter pivot element: " << std::endl;
    std::cin >> pivot;

    rearrange(arr, n, pivot);

    printArray(arr, n);

    delete[] arr;
}
