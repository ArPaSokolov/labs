/* ���� ������ ������ �� ����� 100 ��������. 
����� � ��� ������� ��������� ������� ��� ����������, 
��� ������ ������� � ������ ���.*/

#include <iostream>
using namespace std;

int main()
{
	char str[100];
	cout << "Enter the str:\n";
	cin >> str;	
	cout << "Enter the element:\n";
	char E;
	cin >> E;
	bool thereIs = false; // ���� �� ������� ���������� �������� � ������
	for (int i = 0; i < strlen(str); i++)
	{
		if (E == str[i]) //���������� �������� ������� � ���������� ������
		{
			if (thereIs == false) // ���������� ����� "The position(s):" ����� ������� ������������
			{
				cout << "The position(s):\n";
			}
			thereIs = true; // ����� �������
			cout << i + 1 << " ";
		}
	}
	if (thereIs == false) // ������� �� ��� ������
	{
		cout << "There is no '"<< E <<"' in str!\n";
	}
	
	return 0;
}