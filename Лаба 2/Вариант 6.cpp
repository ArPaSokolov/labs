#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������� �������� ������� ��������� ��������:\n";
    double S;
    cin >> S;
    cout << "������� �������� ������ ��������:\n";
    double h;
    cin >> h;
    cout << "���������� �������� ������:\n";
    double V;
    V = h * S;
    cout << V;
    return 0;

}
