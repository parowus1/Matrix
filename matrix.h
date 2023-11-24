#pragma once


class matrix {
private:
    int size;
    int** data;

public:
    matrix();
    matrix(int n);
    matrix(int n, int* t);
    matrix(const matrix& m);
    ~matrix();
