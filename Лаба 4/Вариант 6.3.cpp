
/*	���� ������������� ������� {Aij}i=1..n,j=1..m (n,m<=100). 
����� ������ � ���������� ������������� ���������
� �������� ��� �������� ���� ������ ���� �������������.*/

#include <iostream>
using namespace std;

int main()
{
    
    cout << "Enter the number of columns:\n";
    int N,S;  // ���-�� �������� � �����
    int maxProizvLine; // ����� ������ � ������������ �������������
    int maxProizv = 0;    // ������������ �����
    cin >> N;
    cout << "Enter the number of line:\n";
    cin >> S;
    double matrix[100][100];
    // ������ �������
    cout << "Enter the matrix:\n";
    for (int i = 0; i < S; i++)
    {
        int Proizv = 1;
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
            Proizv *= matrix[i][j];
        }
        if (maxProizv < Proizv)
        {
            maxProizv = Proizv;
            maxProizvLine = i;
        }
    }
    
    // ������� �������
    cout << "\n";
    cout << "The matrix:";
    for (int l = 0; l < S; l++)
    {
        cout << "\n";
        for (int k = 0; k < N; k++)
        {
            if (l == maxProizvLine)
            {
                cout << (matrix[l][k] = maxProizv) << " ";
            }
            else
            {
                cout << matrix[l][k] << " ";
            }
        }
    }
    return 0;
}