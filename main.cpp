#include "matrix.cpp"
#include <iostream>


int main() {
    std::cout << "Macierz \n";
    matrix m1;
    std::cout << "M1 Konstruktor domyslny: \n" << m1;

    m1.alokuj(30);
    std::cout << "\nM1 - po zaalokowaniu pamieci: \n" << m1;

    matrix m1copy(m1);
    std::cout << "\nM1copy - konstruktor kopiujacy: \n" << m1copy;

    m1.wstaw(0, 0, 9);
    m1.wstaw(10, 20, 99);

    std::cout << "\nM1 - po wstawieniu wartosci na pole (0, 0): \n" << m1;

    std::cout << "\nM1 - pokaz wartosc dla (0, 0): " << m1.pokaz(0,0) << "\n";

    m1.dowroc();
    std::cout << "\nM1 - po odwroceniu wierszy z kolumnami - dowroc(): \n" << m1;

    m1.losuj(200);
    std::cout << "\nM1 - po wylosowaniu cyfr dla 200 elementów macierzy losuj(200): \n" << m1;

    m1.losuj();
    std::cout << "\nM1 - po wylosowaniu cyfr dla wszystkich elementow macierzy losuj(): \n" << m1;

    matrix m2(30);

    int diagonalArray[30];
    for (int i = 0; i < 30; ++i) diagonalArray[i] = i + 1;
    
    int matrixSize = 30;
    m2.diagonalna(diagonalArray);
    std::cout << "\nM2 - po wpisyaniu cyfr na diagonalna - diagonalna(): \n" << m2;

    m2.diagonalna_k(-3, diagonalArray);
    std::cout << "\nM2 - po wpisyaniu cyfr na diagonalna_k przesuniętą o parametr - diagonalna(-3, tablica): \n" << m2;

    m2.kolumna(5, diagonalArray);
    std::cout << "\nM2 - po wpisyaniu cyfr w danej kolumnie - kolumna(5, tablica): \n" << m2;

    m2.wiersz(5, diagonalArray);
    std::cout << "\nM2 - po wpisyaniu cyfr w danym wierszu - wiersz(5, tablica): \n" << m2;

    m2.przekatna();
    std::cout << "\nM2 - uzupelnia 1 na przekatnej, 0 poza przekatna - przekatna(): \n" << m2;

    m2.pod_przekatna();
    std::cout << "\nM2 - uzupelnia cyfra 1 wszystkie pola pod przekatna, 0 w innych miejscach - pod_przekatna(): \n" << m2;

    m2.nad_przekatna();
    std::cout << "\nM2 - uzupelnia cyfra 1 wszystkie pola nad przekatna, 0 w innych miejscach - nad_przekatna(): \n" << m2;

    m2.szachownica();
    std::cout << "\nM2 - uzupelnia pola w szachownice z cyfr 0 i 1 szachownica(): \n" << m2;

//     std::cout<<"czy to wogole dziala1";

//     matrix A(3);
//         std::cout<<"czy to wogole d2ziala1";

//     A.alokuj(2);
//     A.wstaw(1,2,3);
//         std::cout<<"czy to wogol3e dziala1";

//     A.pokaz(1,2);
//     A.dowroc();
//     A.losuj();
//     A.losuj(3);
//     int diagonalValues[] = {1, 2, 3};
 
// matrix m(3);
//     m.szachownica();
//     std::cout << "Original Matrix:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Wstawiamy wartości do kolumny
//     int column_data[3] = {10, 11, 12};
//     m.kolumna(1, column_data);
//     std::cout << "\nMatrix after inserting column data:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     int row_data[3] = {20, 21, 22};
//     m.wiersz(0, row_data);
//     std::cout << "\nMatrix after inserting row data:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     matrix m1(3);
//     m1.losuj();
//     std::cout << "Matrix 1:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     matrix m2(3);
//     m2.losuj(9);
//     std::cout << "\nMatrix 2:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m2.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Dodajemy dwie macierze
//     m1 + m2;
//     std::cout << "\nMatrix 1 + Matrix 2:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Dodajemy stałą do macierzy
//     m1 + 5;
//     std::cout << "\nMatrix 1 + 5:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Dodajemy macierz do stałej
//     matrix result = 3 + m1;
//     std::cout << "\n3 + Matrix 1:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << result.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Dodajemy liczbę rzeczywistą do macierzy
//     m1 + 2.5;
//     std::cout << "\nMatrix 1 + 2.5:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << m1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }


//     matrix mc1(3);
//     matrix mc2(3);
//     mc1.losuj();
//     mc2.losuj();

//     // Matrix multiplication
//     matrix mc3 = mc1 * mc2;
//     std::cout << "Result of matrix multiplication:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mc3.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//         // Display values before multiplication by 5
//     std::cout << "\nValues of mc1 before multiplication by 5:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mc1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }


//     // Multiplication by a constant
//     matrix mc4 = mc1 * 5;
//     std::cout << "\nResult of matrix multiplication by 5:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mc4.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//         // Display values before multiplication by 3
//     std::cout << "\nValues of mc2 before multiplication by 3:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mc2.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }


//     // Friend multiplication operator (constant * matrix)
//     matrix mc5 = 3 * mc2;
//     std::cout << "\nResult of 3 times matrix multiplication:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mc5.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     const int size = 3;
    
//     int values[size * size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     matrix mm1(size, values);
//     mm1 -= 2;

//     // Using the friend subtraction operator
//     matrix mm2 = mm1 - 3;
//     std::cout<<"skompilowane";
//         std::cout << "Values of mm1 after subtraction by 2:\n";
//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             std::cout << mm1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Display values of mm2 after subtraction
//     std::cout << "\nValues of mm2 after subtraction by 3:\n";
//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             std::cout << mm2.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }



//     matrix md1(3);
//     matrix md2(3);
//     matrix md3(3);

//     // Perform some operations on matrices
//     md1.losuj();
//     md2.losuj();
//     md3 = md1 + md2;

//     // Display the original matrix
//     std::cout << "Original Matrix:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << md1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Use post-increment operator
//     matrix md4 = md1++;
//     std::cout << "\nMatrix after post-increment:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << md1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Use post-decrement operator
//     matrix md5 = md1--;
//     std::cout << "\nMatrix after post-decrement:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << md1.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }





//     matrix mcc(3);
//     mcc.losuj(); // Losowe wypełnienie macierzy

//     // Wyświetlenie pierwotnej macierzy
//     std::cout << "Original matrix:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mcc.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Testowanie operatora +=
//     mcc += 5;

//     // Wyświetlenie macierzy po dodaniu liczby
//     std::cout << "\nMatrix after += 5:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mcc.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }

//     // Tworzenie nowej macierzy
//     matrix mcc2(3);
//     mcc2.losuj(); // Losowe wypełnienie drugiej macierzy

//     // Testowanie operatora *=
//     mcc2 *= 2;

//     // Wyświetlenie drugiej macierzy po pomnożeniu przez 2
//     std::cout << "\nMatrix after *= 2:\n";
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             std::cout << mcc2.pokaz(i, j) << " ";
//         }
//         std::cout << "\n";
//     }


//         matrix d1(3, new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9});
//     matrix d2(3, new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9});
//     matrix d3(3, new int[9]{9, 8, 7, 6, 5, 4, 3, 2, 1, });

//     if (d1 == d2) {
//         std::cout << "d1 is equal to d2\n";
//     } else {
//         std::cout << "d1 is not equal to d2\n";
//     }

//     if (d1 > d3) {
//         std::cout << "d1 is greater than d3\n";
//     } else {
//         std::cout << "d1 is not greater than d3\n";
//     }

//     if (d1 < d3) {
//         std::cout << "d1 is smaller than d3\n";
//     } else {
//         std::cout << "d1 is not smaller than d3\n";
//     }


//         matrix myMatrix(3); // Tworzymy macierz 3x3
//     myMatrix.losuj();   // Losujemy wartości dla macierzy

//     // Wyświetlamy macierz za pomocą przeciążonego operatora <<
//     std::cout << "Macierz myMatrix:" << std::endl << myMatrix;


//     matrix mat(30);  // Tworzymy macierz 30x30
//     mat.losuj();     // Losujemy wartości dla macierzy
//     std::cout << mat; // Wyświetlamy macierz

    return 0;
}