#include "matrix.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


matrix& matrix::alokuj(int n) {
    if (data == nullptr) {
        // Macierz nie ma jeszcze zaalokowanej pamieci, alokuj ja w zadanym rozmiarze
        size = n;
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
            // Inicjowanie wartości elementow macierzy na zero
            for (int j = 0; j < size; ++j) {
                data[i][j] = 0;
            }
        }
    } else {
        if (size != n) {
            // Macierz ma zaalokowana pamiec, ale inny rozmiar, zwolnij i zaalokuj ponownie
            for (int i = 0; i < size; ++i) {
                delete[] data[i];
            }
            delete[] data;

            size = n;
            data = new int*[size];
            for (int i = 0; i < size; ++i) {
                data[i] = new int[size];
                // Inicjowanie wartości elementow macierzy na zero
                for (int j = 0; j < size; ++j) {
                    data[i][j] = 0;
                }
            }
        } else {
            // Macierz ma zaalokowana pamiec i jest odpowiedniego rozmiaru, nie rob nic
            return *this;
        }
    }

    return *this;
}

    matrix& matrix::wstaw(int x, int y, int wartosc) {
        if (x >= 0 && x < size && y >= 0 && y < size) {
            data[x][y] = wartosc;
        }
        return *this;
    }

    int matrix::pokaz(int x, int y) {
        if (x >= 0 && x < size && y >= 0 && y < size) {
            return data[x][y];
        }
        else {
            // Tu mo�na doda� obs�ug� b��du
            throw std::out_of_range("Indeksy macierzy sa poza zakresem.");
        }
    }

    matrix& matrix::operator=(const matrix& m) {
    if (this != &m) {
        // Deallocate existing memory
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Allocate new memory
        size = m.size;
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
        }

        // Copy data
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = m.data[i][j];
            }
        }
    }
    return *this;
}

matrix& matrix::dowroc() {
    matrix tmp(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tmp.data[j][i] = data[i][j];  // Swap indices to exchange columns with rows
        }
    }
    return *this = tmp;
}

    matrix& matrix::losuj() {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = rand() % 10;
            }
        }
        return *this;
    }

        matrix& matrix::losuj(int x) {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int k = 0; k < x; ++k) {
            int i = rand() % size;
            int j = rand() % size;
            data[i][j] = rand() % 10;
        }
        return *this;
    }

    matrix& matrix::diagonalna(int* t) {
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

        matrix& matrix::diagonalna_k(int k, int* t) {
        k=-k; //
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

        matrix& matrix::kolumna(int x, int* t) {
        for (int i = 0; i < size; ++i) {
            data[i][x] = t[i];
        }
        return *this;
    }

    matrix& matrix::wiersz(int y, int* t) {
        for (int j = 0; j < size; ++j) {
            data[y][j] = t[j];
        }
        return *this;
    }

        matrix& matrix::przekatna() {
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

    matrix& matrix::pod_przekatna() {
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

        matrix& matrix::nad_przekatna() {
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

    matrix& matrix::szachownica() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = (i + j) % 2;
            }
        }
        return *this;
    }

    matrix operator+(int a, matrix& m){
    // Tworzymy nowa macierz, aby nie zmieniac oryginalnej
    matrix result = m;
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] += a;
        }
    }
    return result;
};

    matrix& matrix::operator+(matrix& m) {
    if (size != m.size) {
        // Throw an exception
        throw std::invalid_argument("Macierze musza miec takie same rozmiary, aby mozna bylo je dodawac.");
    } else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] += m.data[i][j];
            }
        }
    }
    return *this;
};



    matrix& matrix::operator+(int a){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += a;
        }
    }
    return *this;
};

    matrix& matrix::operator+(double a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += static_cast<int>(a); // Rzutujemy na int, aby zachowac spojnośc z typem macierzy
        }
    }
    return *this;
};

matrix operator*(int a, const matrix& m) {
        matrix result(m.size);

        for (int i = 0; i < m.size; ++i) {
            for (int j = 0; j < m.size; ++j) {
                result.data[i][j] = a * m.data[i][j];
            }
        }

        return result;
    }


    matrix matrix::operator*(const matrix& m) const {
        if (size != m.size) {
            // Throw an exception
            throw std::invalid_argument("Macierze musza miec odpowiednie rozmiary do przemnozenia.");

        } else {
            matrix result(size);

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    result.data[i][j] = 0;
                    for (int k = 0; k < size; ++k) {
                        result.data[i][j] += data[i][k] * m.data[k][j];
                    }
                }
            }

            return result;
        }
    }

        matrix matrix::operator*(int a) const {
        matrix result(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = a * data[i][j];
            }
        }

        return result;
    }

    matrix matrix::operator-(int a) const {
    matrix result = *this;  // Create a new matrix to avoid modifying the original
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] -= a;
        }
    }
    return result;
}

matrix operator-(int a, const matrix& m) {
    matrix result = m;  // Create a new matrix to avoid modifying the original
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = m.data[i][j] - a;
        }
    }
    return result;
}

matrix& matrix::operator-=(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= a;
        }
    }
    return *this;
}

 matrix matrix::operator++(int) {
        matrix tmp(*this); // Create a copy of the current matrix
        // Increment each element in the matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j]++;
            }
        }
        return tmp; // Return the original matrix (before increment)
    }

    matrix matrix::operator--(int) {
        matrix tmp(*this); // Create a copy of the current matrix
        // Decrement each element in the matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j]--;
            }
        }
        return tmp; // Return the original matrix (before decrement)
    }


    matrix& matrix::operator+=(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += a;
        }
    }
    return *this;
}

matrix& matrix::operator*=(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] *= a;
        }
    }
    return *this;
}

    bool matrix::operator==(const matrix& m) {
        if (size != m.size) {
            return false;
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (data[i][j] != m.data[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

bool matrix::operator>(const matrix& m) {
    if (size != m.size) {
        // Throw an exception
        throw std::invalid_argument("Macierze musza miec takie same rozmiary do porownania.");
    }

    bool isGreater = true;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] <= m.data[i][j]) {
                isGreater = false;
                break;
            }
        }
        if (!isGreater) {
            break;
        }
    }

    return isGreater;
}

bool matrix::operator<(const matrix& m) {
    if (size != m.size) {
        // Throw an exception
        throw std::invalid_argument("Macierze musza miec takie same rozmiary do porownania.");
    }
    bool isLess = true;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] >= m.data[i][j]) {
                isLess = false;
                break;
            }
        }
        if (!isLess) {
            break;
        }
    }

    return isLess;
}

    std::ostream& operator<<(std::ostream& o, matrix& m) {
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            o << m.data[i][j] << " ";
        }
        o << std::endl;
    }
    return o;
}

void matrix::wczytajMacierzZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku: " + nazwaPliku);
    }

        // Zwolnienie pamięci, jeśli została już zaalokowana
    if (data != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    std::vector<std::vector<int>> tempData;
    std::string linia;
    while (std::getline(plik, linia)) {
        std::vector<int> wiersz;
        std::stringstream ss(linia);
        int liczba;

        while (ss >> liczba) {
            wiersz.push_back(liczba);
        }

        if (!ss.eof()) {
            throw std::runtime_error("Nieprawidłowy format danych w pliku: " + nazwaPliku);
        }

        tempData.push_back(wiersz);
    }

    size = tempData.size();
    data = new int*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = tempData[i][j];
        }
    }

    plik.close();
}

// matrix& dowroc() { // takie co odwraca kolumnami
//     matrix tmp(size);
//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             tmp.data[i][j] = data[size - 1 - j][i];
//         }
//     }
//     return *this = tmp;
// }