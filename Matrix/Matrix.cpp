#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int Size_N1;
    int Size_M1;
    int Size_N2;
    int Size_M2;
    cout << "Введите кол-во столбцов у первой матрицы" << "\n";
    cin >> Size_N1;
    cout << "Введите кол-во строк у первой матрицы" << "\n";
    cin >> Size_M1;
    int** matrix1 = new int* [Size_N1];
    for (int i = 0; i < Size_N1; i++)
    {
        matrix1[i] = new int[Size_M1];
    }
    cout << "Введите кол-во столбцов у второй матрицы" << "\n";
    cin >> Size_N2;
    cout << "Введите кол-во строк у второй матрицы" << "\n";
    cin >> Size_M2;
    int** matrix2 = new int* [Size_N2];
    for (int i = 0; i < Size_N2; i++)
    {
        matrix2[i] = new int[Size_M2];
    }
    for (int i = 0; i < Size_N1; i++) {
        for (int j = 0; j < Size_M1; j++)
            matrix1[i][j] = i;
    }
    for (int i = 0; i < Size_N2; i++) {
        for (int j = 0; j < Size_M2; j++)
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
    for (int i = 0; i < Size_N2; i++)
    {
        for (int j = 0; j < Size_M2; j++)
        {
            cout << matrix2[i][j] << ' ';
        }
        cout << '\n';
    }
}