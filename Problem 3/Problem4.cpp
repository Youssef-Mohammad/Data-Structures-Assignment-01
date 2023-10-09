#include <iostream>
#include "Problem4.h"
using namespace std;

template <typename T>
Matrix<T>::Matrix(int r,int c)
{
    row = r;
    col = c;
    matrix = new T*[row];
    for(int i = 0; i < row; i++)
    {
        matrix[i] = new T[col];
    }
}
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix &m)
{
    Matrix result(row, col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return result;
}
template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix &m)
{
    Matrix result(row, col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    return result;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &m)
{
    Matrix result(row, m.col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < m.col; j++)
        {
            result.matrix[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return result;
}
template <typename T>
Matrix<T> Matrix<T>::transpose(Matrix &m)
{
    Matrix<int> result(row, col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}
template <typename U>
istream& operator>>(istream& in, Matrix<U> &m)
{
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.col; j++)
        {
            cout << "Element[" << i << "][" << j << "]:" << endl;
            in >> m.matrix[i][j];
        }
    }
    return in;
}
template <typename U>
ostream& operator<<(ostream& out, Matrix<U> &m)
{
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.col; j++)
        {
            out << m.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
template <typename T>
Matrix<T>::~Matrix()
{
    for(int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

MatrixCalculator::MatrixCalculator()
{
    int choice;
    cout << "Welcome to Mohamed's Matrix Calculator" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1)Perform Matrix Addition" << endl;
    cout << "2)Perform Matrix Subtraction" << endl;
    cout << "3)Perform Matrix Multiplication" << endl;
    cout << "4)Perform Matrix Transpose" << endl;
    cout << "5)Exit" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            trans();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
            break;
    }
}
void MatrixCalculator::add()
{
    int r1, c1, r2, c2;
    cout << "Enter the number of rows in the first matrix:" << endl;
    cin >> r1;
    cout << "Enter the number of columns in the first matrix:" << endl;
    cin >> c1;
    cout << "Enter the number of rows in the second matrix:" << endl;
    cin >> r2;
    cout << "Enter the number of columns in the second matrix:" << endl;
    cin >> c2;
    if(r1 != r2 || c1 != c2)
    {
        cout << "The matrices cannot be added" << endl;
        return;
    }
    else
    {
        Matrix<int> m1(r1, c1);
        Matrix<int> m2(r2, c2);
        cout << "Enter the elements of the first matrix:" << endl;
        cin >> m1;
        cout << "Enter the elements of the second matrix:" << endl;
        cin >> m2;
        Matrix<int> result = m1 + m2;
        cout << "The result of the addition is:" << endl;
        cout << result;
    }
}
void MatrixCalculator::sub()
{
    int r1, c1, r2, c2;
    cout << "Enter the number of rows in the first matrix:" << endl;
    cin >> r1;
    cout << "Enter the number of columns in the first matrix:" << endl;
    cin >> c1;
    cout << "Enter the number of rows in the second matrix:" << endl;
    cin >> r2;
    cout << "Enter the number of columns in the second matrix:" << endl;
    cin >> c2;
    if(r1 != r2 || c1 != c2)
    {
        cout << "The matrices cannot be subtracted" << endl;
        return;
    }
    else
    {
        Matrix<int> m1(r1, c1);
        Matrix<int> m2(r2, c2);
        cout << "Enter the elements of the first matrix:" << endl;
        cin >> m1;
        cout << "Enter the elements of the second matrix:" << endl;
        cin >> m2;
        Matrix<int> result = m1 - m2;
        cout << "The result of the subtraction is:" << endl;
        cout << result;
    }
}
void MatrixCalculator::mul()
{
    int r1, c1, r2, c2;
    cout << "Enter the number of the first matrix rows:" << endl;
    cin >> r1;
    cout << "Enter the number of the first matrix columns:" << endl;
    cin >> c1;
    cout << "Enter the number of the second matrix rows:" << endl;
    cin >> r2;
    cout << "Enter the number of the second matrix columns:" << endl;
    cin >> c2;
    if(c1 != r2)
    {
        cout << "The matrices cannot be multiplied" << endl;
        return;
    }
    else
    {
        Matrix<int> m1(r1, c1);
        Matrix<int> m2(r2, c2);
        cout << endl << "Enter the first matrix elements:" << endl;
        cin >> m1;
        cout << endl << "Enter the second matrix elements:" << endl;
        cin >> m2;
        Matrix<int> result = m1 * m2;
        cout << endl << "The multiplication result is:" << endl << endl;
        cout << result;
    }
}
void MatrixCalculator::trans()
{
    int r, c;
    cout << "Enter the number of rows in the matrix:";
    cin >> r;
    cout << "Enter the number of columns in the matrix:";
    cin >> c;
    Matrix<int> m(r, c);
    cout << "Enter the elements of the matrix:" << endl;
    cin >> m;
    Matrix<int> result = m.transpose(m);
    cout << "The result of the transpose is:" << endl;
    cout << result;
}