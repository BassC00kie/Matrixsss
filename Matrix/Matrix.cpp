#include <iostream>
#include "conio.h"
#include <cstdlib> 
#include <fstream>
using namespace std;
int Size_N1;
int Size_M1;
int N;
int** show(int** mat1) {
    for (int i = 0; i < Size_N1; i++)
    {
        for (int j = 0; j < Size_M1; j++)
        {
            cout << mat1[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    return mat1;
}
int** plusing1(int** mat1, int** mat2) {
    int** matrixS = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrixS[i] = new int[Size_M1];
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++) {
            matrixS[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return matrixS;
}
int** mulMat(int** mat1, int** mat2)
{
    int** matrixM = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrixM[i] = new int[Size_M1];
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++) {
            matrixM[i][j] = 0;
            for (int k = 0; k < Size_N1; k++) {
                matrixM[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return matrixM;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream outfile("MatrixN1.txt");
    if (outfile.is_open())
        cout << "file has been opened\n\n";
    else
    {
        cout << "file hasn't been open\n\n";
        return -1;
    }
    outfile >> Size_N1;
    Size_M1 = Size_N1;
    int** matrix1 = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrix1[i] = new int[Size_M1];
    }
    int** matrix2 = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrix2[i] = new int[Size_M1];
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++) {
            outfile >> matrix1[i][j];
        }
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++)
            if (i == j) {
                matrix2[i][j] = 1;
            }
            else {
                matrix2[i][j] = 0;
            }
    }
    for (int i = 0; i < Size_N1; i++)
    {
        for (int j = 0; j < Size_M1; j++)
        {
            cout << matrix1[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < Size_N1; i++)
    {
        for (int j = 0; j < Size_M1; j++)
        {
            cout << matrix2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    int** matrixAnsSum =  plusing1(matrix1, matrix2);
    show(matrixAnsSum);
    int** matrixAnsMult = mulMat(matrix1, matrix2);
    show(matrixAnsMult);
}