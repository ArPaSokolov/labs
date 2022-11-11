/*���� ������������� ������� {Aij}i=1...n;j=1..n ,
n<=100. ���� � ������� ���� ��� ���� �������,
������ �� ������������� ��������,
����������� ������ ������� �� ��������
���������� ������� ����� ����� ��������� �����.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void inF(ifstream& in, int numReading[50][50], int N, int M) //��������� ������ �����
{
	for (int inI = 0; inI < M; inI++)
	{
		for (int inJ = 0; inJ < N; inJ++)
			in >> numReading[inI][inJ];
	}
}

void outF(ofstream& out, int numReading[50][50], int N, int M)// ��������� ��������� �����
{
	for (int ofI = 0; ofI < M; ofI++)
	{
		for (int ofJ = 0; ofJ < N; ofJ++)
		{
			out << numReading[ofI][ofJ] << " ";
			cout << numReading[ofI][ofJ] << " ";
		}
		out << '\n';
		cout << '\n';
	}
}

int findMax(int numReading[50][50], int max, int M, int N) //����� �������������
{
	for (int mI = 0; mI < M; mI++)
	{
		for (int mJ = 0; mJ < N; mJ++)
		{
			if (numReading[mI][mJ] > max)
			{
				max = numReading[mI][mJ];
			}
		}
	}
	return max;
}

int ifPrime(int isPrime, int number) // ���������� ������� ����� ��� ���
{
	isPrime = 1;// ����� �������
	for (int i = 2; i <= sqrt(number); i++)
	{
		if ((number % i) == 0)
		{
			isPrime = 0; // ����� �� �������
		}
	}
	return isPrime;
}

int ifPrime(int isPrime, double number) // ���������� ������� ����� ��� ���
{
	isPrime = 0;// ����� �� �������
	return isPrime;
}

string ifPrime(int a) // ���������� ������� ����� ��� ���
{
	string b = "�������";
	for (int i = 2; i <= sqrt(a); i++)
	{
		if ((a % i) == 0)
		{
			b = "����� �� �������";
		}
	}
	return b;
}

void decreasSort(int numberOfPrime[100], int numReading[50][50], int M, int N) // ����������
{
	for (int sI = 0; sI < M; sI++)
	{
		int s = sI;
		while (s > 0 and numberOfPrime[s - 1] < numberOfPrime[s]) // ����� �� ��������� ������� c����, ���� ����������� �������
		{
			swap(numberOfPrime[s], numberOfPrime[s - 1]);// ������ ������� � ��������� ������� ����� (����� �� ���������� �������)
			for (int sJ = 0; sJ < N; sJ++)
				swap(numReading[s][sJ], numReading[s - 1][sJ]);// ������ ������� ������ �� ������
			s = s - 1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt"); // ��� ����� � ������������ (��� ������)
	ofstream out("output.txt"); // ��� ����� � ������������ (��� ������)
	int numReading[50][50]; // �������
	int numberOfPrimeInLine = 0; // ���������� ������� � ����� ������
	int N, M; //���������� �������� � �����
	int isPrime = 1; //������� ������� �����
	in >> N;
	in >> M;
	int max = INT_MIN;
	int numberOfPrime[100]; // ������ ��� �������� ���������� ������� ����� � ������ ������
	int sortTrue = 0; //����������� � ����������

	inF(in, numReading, N, M); // ��������� ����

	max = findMax(numReading, max, M, N); // ������� ������������ ��������

	for (int nI = 0; nI < M; nI++) // ������� ���������� ������� ����� � �������
	{
		for (int nJ = 0; nJ < N; nJ++)
		{
			int number = numReading[nI][nJ];
			if (number == max) // ��������� �� ������ ������������� ��������
				sortTrue += 1; // ������������ �������� �����������
			numberOfPrimeInLine += ifPrime(isPrime, number); // ������� ���������� ������� � ������
		}
		numberOfPrime[nI] = numberOfPrimeInLine; // ������ ����������� -> ���������� ���������� ������� � ���
		numberOfPrimeInLine = 0; // ��������� ������� ��� ��������� ������
	}

	if (sortTrue > 1)//������������ ����������� -> ���������
	{
		decreasSort(numberOfPrime, numReading, M, N);
		outF(out, numReading, N, M); //������� ���������� �������
	}
	else // ������������ ���� -> ���������� �� �����
	{
		outF(out, numReading, N, M); // ������� ���������� �������
	}
	return 0;
}