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

matrix& alokuj(int n) {
    if (data != nullptr) {
        if (size != n) {
            for (int i = 0; i < size; ++i) {
                delete[] data[i];
            }
            delete[] data;
            size = 0;
            data = nullptr;
        }
        else {
            return *this;
        }
    }

    size = n;
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
    }

    return *this;
}

matrix& wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        data[x][y] = wartosc;
    }
    return *this;
}

int pokaz(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return data[x][y];
    }
    else {
        // Tu można dodać obsługę błędu
        return -1;
    }
}

matrix& dowroc() {
    matrix tmp(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tmp.data[i][j] = data[j][i];
        }
    }
    return *this = tmp;
}
