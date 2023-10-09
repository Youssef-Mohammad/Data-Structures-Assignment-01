#ifndef PROBLEM3_MATRIX_H
#define PROBLEM3_MATRIX_H
#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
protected:
    int row;
    int col;
    T** matrix;
public:
    Matrix(int r, int c);

    Matrix operator+(Matrix &m);
    Matrix operator-(Matrix &m);
    Matrix operator*(Matrix &m);
    Matrix transpose(Matrix &m);

    template <typename U>
    friend istream& operator>>(istream &in, Matrix<U> &m);
    template <typename U>
    friend ostream& operator<<(ostream &out, Matrix<U> &m);

    ~Matrix();
};

class MatrixCalculator
{
public:
    MatrixCalculator();
    static void add();
    static void sub();
    static void mul();
    static void trans();
};

#endif //PROBLEM3_MATRIX_H