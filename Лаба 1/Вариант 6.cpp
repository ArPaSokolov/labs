#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� ������� ����:\n";
	short A;
	cin >> A;
	short V;
	V = A * A * A;
	cout << "���������� �������� ������ ����:\n";
	cout << V;
	return 0;
}