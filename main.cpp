#include "matrix.cpp"
#include <iostream>


int main() {
    // Testowanie funkcji
    matrix A(3);
    A.losuj();
    std::cout << "Macierz A:\n" << A << "\n";

    matrix B(3);
    B.losuj();
    std::cout << "Macierz B:\n" << B << "\n";
