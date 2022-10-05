#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number:\n";
    int N;  // ���-�� ���������
    cin >> N;
    int mas[10000];
    int num1[10000];
    int num2[10000];

    // ��������� ������
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the element:\n";
        cin >> mas[i];
    }

    // ����� �� �������
    for (int j = 0; j < N; j++)
    {
        int n = mas[j];  // �����
        int o;  // �������
        int sum = 0;    // ����� ���� �����
        int mult = 1;   // ������������ ���� �����
        while (n > 0)   // ������������ ����� �� ��������
        {
            o = n % 10;
            n = (n - o) / 10;
            sum += o;
            mult *= o;
        }
        num1[j] = sum; // ��������� � ������ ����� ���� �����
        num2[j] = mult; // ��������� � ������ ������������ ���� �����
    }

    // ���������� �� ����� ����
    for (int l1 = 0; l1 < N; l1++)
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

    // ������� �����
    cout << "The array:\n";
    for (int h = 0; h < N; h++)
    {
        cout << mas[h] << " ";
    }
    return 0;

}