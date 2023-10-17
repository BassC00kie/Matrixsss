#include <iostream>
#include "conio.h"
#include <cstdlib> 
#include <fstream>
using namespace std;
int Size_N1;
int Size_M1 = Size_N1;
int N;
int plusing(int** mat1, int** mat2) {
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
    for (int i = 0; i < Size_N1; i++)
    {
        for (int j = 0; j < Size_M1; j++)
        {
            cout << matrixS[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*int mult(int** mat1, int** mat2) {

}*/

int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream outfile("U:\'Кириллл В'\Matrixsss\\MatrixN1");
    outfile >> Size_N1;
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
        for (int j = 0; j < Size_M1; j++)
            outfile >> matrix1[i][j];
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
    plusing(matrix1, matrix2);
}