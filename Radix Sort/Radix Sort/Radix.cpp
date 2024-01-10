#include <iostream>

using namespace std;

// ������� ��������� ��� ��������� ������������� �������� arr[]
int GetMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// �������, ��� ������ ��������� ���� arr[] �������� ��
// �����, ������������ exp.
void CountingSort(int arr[], int size, int exp)  //���������� ����������
{
    int* output = new int[size]; // output array
    int i, count[10] = { 0 };
    //�������� ������� ����� � count[] 
    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // ����� count[i], ��� ����� count[i] ����� ������� ���
    // ������� ���� ����� � �����[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    //������ �������� �����
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //������� �������� ����� � arr[], ��� ����� arr[]
    //����� ���������� ����� �������� �� ������� �����
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

// ������� �������, ��� ����� arr[] ������ n �� ���������
// Radix Sort
void RadixSort(int arr[], int n)
{
    //��������� ����������� �����, ��� ����� ������� ����
    int m = GetMax(arr, n);

    //������������� ��������� ���������� ��� ����� �����. 
    //������ ����� ���������� exp. exp � 10^i
    //�� i - �������� ��������� �����
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        CountingSort(arr, n, exp);
    }
}

void Print(int arr[], int n)
{
    cout << "After sorting:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    RadixSort(arr, n);
    Print(arr, n);
    return 0;
}