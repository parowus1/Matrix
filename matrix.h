#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class matrix {
private:
    int size;
    int** data;

public:
    // Konstruktory i destruktor
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
    

    matrix& alokuj(int n);
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    matrix& operator=(const matrix& m);
    matrix& dowroc();
    matrix& losuj();
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int y, int* t);
    matrix& przekatna();
    matrix& pod_przekatna();
    matrix& nad_przekatna();
    matrix& szachownica();
    friend matrix operator+(int a, matrix& m);
    matrix& operator+(matrix& m);
    matrix& operator+(int a);
    matrix& operator+(double a);
    friend matrix operator*(int a, const matrix& m);
    matrix operator*(const matrix& m) const ;
    matrix operator*(int a) const ;
    matrix operator-(int a) const ;
    friend matrix operator-(int a, const matrix& m);
    matrix& operator-=(int a);
    matrix operator++(int);
    matrix operator--(int);
    matrix& operator+=(int a);
    matrix& operator*=(int a);
    bool operator==(const matrix& m) ;
    bool operator>(const matrix& m);
    bool operator<(const matrix& m);
    friend std::ostream& operator<<(std::ostream& o, matrix& m);

    void wczytajMacierzZPliku(const std::string& nazwaPliku);
};




