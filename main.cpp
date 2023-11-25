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

    matrix t1(30);
    t1.pod_przekatna();
    matrix t2(30);
    t2.nad_przekatna();
    t1 = t1 + t2;
    // t1 + t2 także działa i przypisuje wynik do t1
    std::cout << "\nT1 - suma dwoch matryc, jednej stworzonej przez funkcje nad_przekatna, a druga przez funkcje pod_przekatna \n" << t1;

    matrix t3(30);
    t3.losuj();

    matrix t4(30);
    t4.szachownica();

    t3 = t3 * t4;
    std::cout << "\nT3 - iloczyn dwoch matryc, jednej z szachownica i drugiej z liczbami losowymi \n" << t3;

    matrix t5(30);
    t5.nad_przekatna();
    t5 + 3;
    std::cout << "\nT5 - matryca wypelniona jedynkami nad przekatna + 3\n" << t5;

    matrix t6(30);
    t6.nad_przekatna();
    t6 = t6 * 3;
    std::cout << "\nT6 - matryca wypelniona jedynkami nad przekatna * 3\n" << t6;

    matrix t7(30);
    t7.nad_przekatna();
    t7 = t7 - 1;
    std::cout << "\nT7 - matryca wypelniona jedynkami nad przekatna - 1\n" << t7;

    matrix t8(30);
    t8.nad_przekatna();
    t8 = 1 + t8;
    std::cout << "\nT8 - 1 + matryca wypelniona jedynkami nad przekatna \n" << t8; 

    matrix t9(30);
    t9.nad_przekatna();
    t9 = 3 * t9 ;
    std::cout << "\nT9 - 3 * matryca wypelniona jedynkami nad przekatna\n" << t9; 

    matrix t10(30);
    t10.nad_przekatna();
    t10 = 1 - t10 ;
    std::cout << "\nT10 - 1 - matryca wypelniona jedynkami nad przekatna\n" << t10; 


    matrix t11(30);
    t11.nad_przekatna();
    //t11 = t11++; takie nie działa
    t11++ ;
    std::cout << "\nT11 - matryca wypelniona jedynkami nad przekatna ++\n" << t11; 

    matrix t12(30);
    t12.nad_przekatna();
    //t11 = t11-- takie nie działa
    t12-- ;
    std::cout << "\nT12 - matryca wypelniona jedynkami nad przekatna --\n" << t12; 


    matrix t13(30);
    t13.nad_przekatna();
    t13+=10 ;
    std::cout << "\nT13 - matryca wypelniona jedynkami nad przekatna += 10\n" << t13; 

    matrix t14(30);
    t14.nad_przekatna();
    t14-=10 ;
    std::cout << "\nT14 - matryca wypelniona jedynkami nad przekatna -= 10\n" << t14; 

    matrix t15(30);
    t15.nad_przekatna();
    t15*=-1 ;
    std::cout << "\nT15 - matryca wypelniona jedynkami nad przekatna *= -1\n" << t15; 

    matrix t16(30);
    t16.nad_przekatna();
    t16 + 2.1231 ;
    std::cout << "\nT16 - matryca wypelniona jedynkami nad przekatna + 2.1231 (double)\n" << t16; 

    matrix t17(30);
    t17.nad_przekatna();
    matrix t18(30);
    t18.nad_przekatna();
    std::cout << "\nCzy dwie rowne macierze sa rowne? T17 == T18\n";
    if(t17 == t18) {
        std::cout<<"TAK";
    } else {
        std::cout<<"NIE";
    }

    std::cout << "\nDwie rowne macierze: Czy T17 > T18\n";
    if(t17 > t18) {
        std::cout<<"TAK";
    } else {
        std::cout<<"NIE";
    }    

    t18.wstaw(0,0,-1);
    std::cout << "\nDodanie jednego elementu mniejszego do T18: Czy T17 > T18\n";
    if(t17 > t18) {
        std::cout<<"TAK";
    } else {
        std::cout<<"NIE";
    }

    std::cout << "\nMacierze takie jak w poprzednim: Czy T17 < T18\n";
    if(t17 < t18) {
        std::cout<<"TAK";
    } else {
        std::cout<<"NIE";
    }  

    return 0;
}