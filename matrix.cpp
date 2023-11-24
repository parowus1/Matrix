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

matrix& losuj() {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = rand() % 10;
        }
    }
    return *this;
}

matrix& losuj(int x) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int k = 0; k < x; ++k) {
        int i = rand() % size;
        int j = rand() % size;
        data[i][j] = rand() % 10;
    }
    return *this;
}

matrix& diagonalna(int* t) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                data[i][j] = t[i];
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& diagonalna_k(int k, int* t) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i - j == k) {
                data[i][j] = t[i];
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& kolumna(int x, int* t) {
    for (int i = 0; i < size; ++i) {
        data[i][x] = t[i];
    }
    return *this;
}

matrix& wiersz(int y, int* t) {
    for (int j = 0; j < size; ++j) {
        data[y][j] = t[j];
    }
    return *this;
}

matrix& przekatna() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& pod_przekatna() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i > j) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& nad_przekatna() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i < j) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& szachownica() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = (i + j) % 2;
        }
    }
    return *this;
}

    matrix& operator+(matrix& m);
    matrix& operator*(matrix& m);
    matrix& operator+(int a);
    matrix& operator*(int a);
    matrix& operator-(int a);
    friend matrix operator+(int a, matrix& m);
    friend matrix operator*(int a, matrix& m);
    friend matrix operator-(int a, matrix& m);
    matrix& operator++(int);
    matrix& operator--(int);
    matrix& operator+=(int a);
    matrix& operator-=(int a);
    matrix& operator*=(int a);
    matrix& operator+(double a);
    friend std::ostream& operator<<(std::ostream& o, matrix& m);
    bool operator==(const matrix& m);
    bool operator>(const matrix& m);
    bool operator<(const matrix& m);

};
