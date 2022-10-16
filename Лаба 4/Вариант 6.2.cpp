/* ������ ������������������ ����������� ����� {Aj}j=1...n (n<=1000). 
����������� ������������������ �� ���������� ����� ���� �����, 
����� � ����������� ������� ���� ������������� ����������� 
�� ���������� ������������ ���� �����, ����� � ����������� 
������� ���� � ����������� �������������� ���� ������������� 
����������� �� ���������� ������ �����.*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number:\n";
    int N;  // ���-�� ���������
    cin >> N;
    int mas[10000];
    int masSum[10000];
    int masMult[10000];

    // ��������� ������
    for (int c = 0; c < N; c++)
    {
        cout << "Enter the element:\n";
        cin >> mas[c];
    }

    // ����� �� �������
    for (int s = 0; s < N; s++)
    {
        int n = mas[s];  // �����
        int o;  // �������
        int sum = 0;    // ����� ���� �����
        int mult = 1;   // ������������ ���� �����
        while (n > 0)   // ������������ ����� �� ��������
        {
            o = n % 10;
            n = n/ 10;
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
        while (j > 0 and masSum[j - 1] > masSum[i]) // ����� �� ��������� ������� c����, ���� ����������� �������
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
        while (j > 0 and masMult[j - 1] > masMult[i] and masSum[j - 1] == masSum[i]) // ����� �� ��������� ������� �����, ���� ����������� �������
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
        while (j > 0 and mas[j - 1] > mas[i] and masMult[j - 1] == masMult[i] and masSum[j - 1] == masSum[i]) // ����� �� ��������� ������� �����, ���� ����������� �������
        {
            swap(mas[j], mas[j - 1]);// �������� ������� � ��������� ������� �����
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }
    
    // ������� �����
    cout << "The array:\n";
    for (int h = 0; h < N; h++)
    {
        cout << mas[h] << " ";
    }
    return 0;

}
// �������������� �������
/*int a;
    int b;
    for (a = 2; a < N+1; a++)
    {
        b = a;
        while (b>1)
        {
            b = b - 1;
            if (mas[b-1] > mas[b]);
            {
                swap(mas[b], mas[b-1]);
            }

        }
    }*/

    /*for (int l1 = 0; l1 < N; l1++)
        for (int l2 = 0; l2 < N; l2++)
        {
            if (num1[l1] < num1[l2])
            {
                swap(mas[l1], mas[l2]);
                swap(num1[l1], num1[l2]);
                swap(num2[l1], num2[l2]);

            }
        }

    // ���������� �� ������������ ����
    for (int k1 = 0; k1 < N; k1++)
        for (int k2 = 0; k2 < N; k2++)
        {
            if (num1[k1] == num1[k2])
            {
                if ((num2[k1] < num2[k2]))
                {
                    swap(mas[k1], mas[k2]);
                    swap(num1[k1], num1[k2]);
                    swap(num2[k1], num2[k2]);
                }
            }
        }

    // ���������� �� ������
    for (int k1 = 0; k1 < N; k1++)
        for (int k2 = 0; k2 < N; k2++)
        {
            if (num1[k1] == num1[k2] and (num2[k1] == num2[k2]))
            {
                if ((mas[k1] < mas[k2]))
                {
                    swap(mas[k1], mas[k2]);
                    swap(num1[k1], num1[k2]);
                    swap(num2[k1], num2[k2]);
                }
            }
        }
    */
/* ���������� �� ����� ����(���������) https://ru.wikipedia.org/wiki/����������_��������� */
    /*int j;
    int i;
    for (i = 1; i < N; i++)
    {
        int xSum = masSum[i]; // ����������, ������� ������ ������������ �������
        int x = mas[i];
        j = i;
        while (j > 0 and masSum[j - 1] > xSum) // ����� �� ��������� ������� �����, ���� ����������� �������
        {
            masSum[j] = masSum[j - 1];  // �������������� ����� ������� �������
            mas[j] = mas[j - 1];
            j = j - 1;
        }
        masSum[j] = xSum; // ��������������� �������������� �������
        mas[j] = x;
    }*/