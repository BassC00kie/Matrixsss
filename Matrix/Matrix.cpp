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
int** plusingMatr(int** mat1, int** mat2) {
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
void SwapStrngs(int** mat1, int a, int b) {
    int strg;
    for (int i = 0; i < Size_N1; i++) {
        strg = mat1[a][i];
        mat1[a][i] = mat1[b][i];
        mat1[b][i] = strg;
    }
}
void StrgsResidual(int** mat1, int a, int b, float K) {
    for (int i = 0; i < Size_N1; i++) {
        mat1[a][i] = mat1[a][i] - K*mat1[b][i];
    }
}
void StrgMultNum(int** mat1, int a, float b) {
    for (int i = 0; i < Size_N1; i++) {
        mat1[a][i] = mat1[a][i] * b;
    }
}
void gauss(int** mat1) {
    for (int j = 0; j < Size_N1; j++) {
        for (int i = j+1; i < Size_N1; i++) {
            int k = mat1[i][j] / mat1[j][j];
            mat1[i][j] = mat1[i][j] - k * mat1[j][j];
        }
    }
}
int main()
{
    ifstream outfile("MatrixN1.txt");
    if (outfile.is_open())
        cout << "File has been opened\n\n";
    else
    {
        cout << "!!File hasn't been open!!\n\n";
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
    cout << "First matrix:\n\n";
    show(matrix1);
    cout << "Second matrix:\n\n";
    show(matrix2);
    int** matrixAnsSum =  plusingMatr(matrix1, matrix2);
    cout << "Sum:\n\n";
    show(matrixAnsSum);
    int** matrixAnsMult = mulMat(matrix1, matrix2);
    cout << "Mult:\n\n";
    show(matrixAnsMult);
    int** matrix1Clone = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrix1Clone[i] = new int[Size_M1];
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++) {
            matrix1Clone[i][j]=matrix1[i][j];
        }
    }
    int solv;
    cout << "How to solve\n1)Comp\n2)Ur self\n\n";
    cin >> solv;
    if (solv == 2){
        while (true) {
            int a, b;
            float c, k;
            cout << "Choose number of operation you want\n1) Swap strings\n2) Strings residual\n3) String mult number\n";
            int operation = 0;
            cin >> operation;
            if (operation == 1) {
                cout << "Enter strngs u want to swap\n\n";
                cin >> a >> b;
                cout << '\n';
                SwapStrngs(matrix1, a, b);
                SwapStrngs(matrix2, a, b);
                show(matrix1);
                show(matrix2);
            }
            if (operation == 2) {
                cout << "Enter strngs u want to reasid\n\n";
                cin >> a >> b;
                cout << "\nEnter K";
                cin >> k;
                StrgsResidual(matrix1, a, b, k);
                StrgsResidual(matrix2, a, b, k);
                show(matrix1);
                show(matrix2);
            }
            if (operation == 3) {
                cout << "Enter strngs and number to mult\n\n";
                cin >> a >> c;
                cout << '\n';
                StrgMultNum(matrix1, a, c);
                StrgMultNum(matrix2, a, c);
                show(matrix1);
                show(matrix2);
            }
            if (matrix1Clone == matrix2) {
                show(matrix1);
                show(matrix2);
                break;
            }
        }
    }
    if (solv == 1) {
        gauss(matrix1);
        gauss(matrix2);
        show(matrix1);
        show(matrix2);
    }
}