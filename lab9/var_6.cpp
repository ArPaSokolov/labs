/*����� �������� ������������. (�������1, �������2, �������3)*/

#include <iostream>
using namespace std;

class triangle //�����
{
private: //����������� �������
	int A; //����
	int B; //����
	int C; //����
public: //����������� �������
	void SetSides(int valueA, int valueB, int valueC) //(�����) ������ ��������
	{
		A = valueA;
		B = valueB;
		C = valueC;
	}
	int GetA() // (�����) �������� ��������
	{
		return A;
	}
	int GetB() //(�����) �������� ��������
	{
		return B;
	}
	int GetC() //(�����) �������� ��������
	{
		return C;
	}
	int Perimetr()
	{
		if ((A + B > C) and (A + C > B) and (B + C > A))
		{
			int valueP = A + B + C;
			return valueP;
		}
		else
		{
			return 0;
		}
	}
	void Show()
	{
		cout << "A is: " << A << endl;
		cout << "B is: " << B << endl;
		cout << "C is: " << C << endl;
	}

};
int main()
{
	cout << "Perimetr is: "<< "Enter 3 sides:" << endl;
	
	triangle ABC; //������
	int valueA;
	int valueB;
	int valueC;
	cin >> valueA;
	cin >> valueB;
	cin >> valueC;

	ABC.SetSides(valueA, valueB, valueC);
	cout << "Perimetr is: " << ABC.Perimetr() << endl;
	ABC.Show();

	return 0;
}