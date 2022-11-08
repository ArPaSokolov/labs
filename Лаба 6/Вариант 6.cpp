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
		for (int  inJ = 0; inJ < N; inJ++)
			in >> numReading[inI][inJ];
	}
}

void outF(ofstream& out, int numReading[50][50], int N, int M)// ��������� ��������� �����
{
	for (int oI = 0; oI < M; oI++)
	{
		for (int oJ = 0; oJ < N; oJ++)
			out << numReading[oI][oJ] << " ";
		out << '\n';
	}
}

int isPrime(int ifPrime, int number) // ���������� ������� ����� ��� ���
{
	ifPrime = 1;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if ((number % i) == 0)
		{
			ifPrime = 0; // ����� �� �������
		}
	}
	return ifPrime;
}

void decreasSort(int numOfPrime[], int numReading[50][50], int M, int N)
{
	for (int sI = 0; sI < M; sI++)
	{
		int s = sI;
		while (s > 0 and numOfPrime[s - 1] < numOfPrime[s])
		{
			swap(numOfPrime[s], numOfPrime[s - 1]);
			for (int sJ = 0; sJ < N; sJ++)
				swap(numReading[s][sJ], numReading[s - 1][sJ]);
			s = s - 1;
		}
	}
}

int findMaxNum(int numReading[50][50], int maxNum, int M, int N)
{
	for (int mI = 0; mI<M;mI++)
		for (int mJ = 0; mJ < M; mJ++)
		{
			if (numReading[mI][mJ] > maxNum)
				maxNum = numReading[mI][mJ];
		}
	return maxNum;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt"); // ��� ����� � ������������ (��� ������)
	ofstream out("output.txt"); // ��� ����� � ������������ (��� ������)
	int numReading[50][50];// ����� ��� ������ �������
	int number;//������� ������� (��� �������� �� ��������)
	int numOfPrime[50];//����� ������� � �������
	int N, M; //���������� �������� � �����
	int ifPrime = 1;//���� �� �������� ����� (0 - �� �������, 1 - �������)
	int maxNum = INT_MIN;
	int maxNumCounter = 0;
	in >> N;
	in >> M;

	inF(in, numReading, N, M);//������ ����
	
	maxNum=findMaxNum(numReading, maxNum, M, N);// ����� ������������

	for (int pI = 0; pI < M; pI++)// ������� ���-�� ������� � �������
	{
		numOfPrime[pI] = 0;// ����� ������� => ��������� �������
		for (int pJ = 0; pJ < N; pJ++)
		{
			number = numReading[pI][pJ];
			if (number == maxNum)
				maxNumCounter++;// ������� ���������� �����������
			if (isPrime(ifPrime, number) == 1)
				numOfPrime[pI]++;//����� �������
		}
	}
	if (maxNumCounter > 1)// ���� ������� ��������� ������������ - ���������
	{
		decreasSort(numOfPrime, numReading, M, N);//��������� ������� �� ���-�� ������� � ���
		outF(out, numReading, N, M);// ������� ����
	}
	else//�� ������� - �� ���������
		outF(out, numReading, N, M);// ������� ����


	return 0;
}
