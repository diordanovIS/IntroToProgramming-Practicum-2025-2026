#include <iostream>

const unsigned MAX_SIZE = 100;

void readMatrix(double a[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
             std::cin >> a[i][j];
}

void transpose(double a[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = i + 1; j < n; j++){
            size_t temp = a[i][j];
            a[i][j] =a[j][i];
            a[j][i] = temp;
        }
}

void avgEachEvenRow(double a[][MAX_SIZE], size_t n) {
    std::cout << "even rows: ";
    for (size_t i = 0; i < n; i += 2) {
        double sum = 0;
        for (size_t j = 0; j < n; j++)
            sum += a[i][j];
         std::cout << sum / n << " ";
    }
     std::cout <<  std::endl;
}

void avgEachOddCol(double a[][MAX_SIZE], size_t n) {
     std::cout << "odd columns: ";
    for (size_t j = 1; j < n; j += 2) {
        double sum = 0;
        for (size_t i = 0; i < n; i++)
            sum += a[i][j];
         std::cout << sum / n << " ";
    }
     std::cout <<  std::endl;
}

void printMatrix(double a[][100], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++)
             std::cout << a[i][j] << " ";
         std::cout <<  std::endl;
    }
}

int main() {
    size_t n;
    
    std::cin >> n;

    double a[MAX_SIZE][MAX_SIZE];

    readMatrix(a, n);
    transpose(a, n);

    printMatrix(a, n);
    avgEachEvenRow(a, n);
    avgEachOddCol(a, n);
}