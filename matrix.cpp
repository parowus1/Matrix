#include <iostream>
#include <cstdlib>
#include <ctime>

class matrix {
private:
    int size;
    int** data;

public:

matrix() : size(0), data(nullptr) {}
matrix(int n) : size(0), data(nullptr) {
    alokuj(n);
}
matrix(int n, int* t) : size(0), data(nullptr) {
    alokuj(n);
    for (int i = 0; i < n * n; ++i) {
        data[i / n][i % n] = t[i];
    }
}
matrix(const matrix& m) : size(0), data(nullptr) {
    alokuj(m.size);
    for (int i = 0; i < size * size; ++i) {
        data[i / size][i % size] = m.data[i / m.size][i % m.size];
    }
}
~matrix() {
    if (data != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}
