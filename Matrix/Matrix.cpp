#include <iostream>
using namespace std;
int Size_N1;
int Size_M1;

int plus(int** mat1, int** mat2) {
    int** matrixS = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrixS[i] = new int[Size_M1];
    }
    mat1 = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++) {
        mat1[i] = new int[Size_M1];
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
int mult(int** mat1, int** mat2) {

}
int main()
{
    setlocale(LC_ALL, "Rus");
    
    cout << "Введите кол-во столбцов у матрицы" << "\n";
    cin >> Size_N1;
    cout << "Введите кол-во строк у матрицы" << "\n";
    cin >> Size_M1;
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
            matrix1[i][j] = i;
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++)
            matrix2[i][j] = i;
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
    plus();
    return 0;
}