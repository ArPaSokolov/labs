/* ������ ������������������ ����������� ����� {Aj}j=1...n (n<=1000).
����������� ������������������ �� ����������� ����� ���� �����,
����� � ����������� ������� ���� ������������� �����������
�� ����������� ������������ ���� �����, ����� � �����������
������� ���� � ����������� �������������� ���� �������������
����������� �� ����������� ������ �����.*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a length of array:" << endl;
    int N;  // ���-�� ���������
    cin >> N;
    int* mas = new int[N];
    int* masSum = new int[N];
    int* masMult = new int[N];

    // ��������� ������
    cout << "Enter the elements:" << endl;
    for (int c = 0; c < N; c++)
    {
        cin >> mas[c];
    }

    // ����� �� �������
    for (int s = 0; s < N; s++)
    {
        int o;  // �������
        int sum = 0;    // ����� ���� �����
        int mult = 1;   // ������������ ���� �����
        int q = mas[s];
        while (q > 0)   // ������������ ����� �� ��������
        {
            o = q % 10;
            q = q / 10;
            sum += o;
            mult *= o;
        }
        masSum[s] = sum; // ��������� � ������ ����� ���� �����
        masMult[s] = mult; // ��������� � ������ ������������ ���� �����
    }

    //���������� �� ����� ����
    for (int i = 1; i < N; i++)
    {             // ���� ������ ����� |
        int j = i;//                   V
        while (j > 0 and masSum[j - 1] > masSum[j]) // ����� �� ��������� ������� c����, ���� ����������� �������
        {
            swap(mas[j], mas[j - 1]);// �������� ������� � ��������� ������� �����
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }
    //���������� �� ����� ������������ ����
    for (int i = 1; i < N; i++)
    {
        int j = i;
        while (j > 0 and masMult[j - 1] > masMult[j] and masSum[j - 1] == masSum[j]) // ����� �� ��������� ������� �����, ���� ����������� �������
        {
            swap(mas[j], mas[j - 1]);// �������� ������� � ��������� ������� �����
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }
    //���������� �� ������
    for (int i = 1; i < N; i++)
    {
        int j = i;
        while (j > 0 and mas[j - 1] > mas[j] and masMult[j - 1] == masMult[i] and masSum[j - 1] == masSum[j]) // ����� �� ��������� ������� �����, ���� ����������� �������
        {
            swap(mas[j], mas[j - 1]);// �������� ������� � ��������� ������� �����
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }

    // ������� �����
    cout << "The array:" << endl;
    for (int h = 0; h < N; h++)
    {
        cout << mas[h] << " ";
    }

    int M;
    cout << endl << "Enter a new length of array:" << endl;
    cin >> M;
    while (M < 0)
    {
        cout << "The value is incorrect.Enter a new value:" << endl;
        cin >> M;
    }

    mas = (int*)realloc(mas, M * sizeof(int));
    cout << "Enter " << M - N << " new elements :" << endl;
    for (int R = N; R < M; R++)
    {
        cin >> mas[R];
    }

    cout << "The array:\n";
    for (int h = 0; h < M; h++)
    {
        cout << mas[h] << " ";
    }

    delete[] mas;
    delete[] masSum;
    delete[] masMult;

    return 0;
}