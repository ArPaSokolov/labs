#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int N, sum = 0, max = INT_MIN, i = 0, j = 0;
    int G;
    cout << "������� ���������� ����� ������������������:\n";
    cin >> N;
    while (i < N)
    {
        i += 1;
        cout << "������� �����:\n";
        cin >> G;
        if (G < 0 and G % 7 == 0)
        {
            sum = sum + G;
            if (max < G)
            {
                max = G;
                j = i;
            }
        }
    }
    if (max != INT_MIN)
    {
        cout << "�����:\n";
        cout << sum << endl;
        cout << "������������ ��������:\n";
        cout << max << endl;
        cout << "����� �����:\n";
        cout << j << endl;
    }
    else
    {
        cout << "����� ��������������� ������� ���" << endl;
    }

    return 0;
}