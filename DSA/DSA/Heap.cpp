#include <iostream>
#include <cmath>

using namespace std;

//��������� ��� ������������ �� ������� ���� �������� � ��������� ������ i, �� �
//�������� arr[]. n - ����� ����

void Heapify(int arr[], int size, int i)
{
    int max_element = i; //����� ������
    //������������ ��������� ������� �� ���������
    int left_daughter_element = 2 * i + 1; 
    int right_daughter_element = 2 * i + 2; 

    //���� ���� ������� ������� ������ �� ����� ����
    if (left_daughter_element < size && arr[left_daughter_element] > arr[max_element])
    {
        max_element = left_daughter_element;
    }
    //���� ������ ������� ������� ������ �� ��������� ������� ���� �� ����� ������
    if (right_daughter_element < size && arr[right_daughter_element] > arr[max_element])
    {
        max_element = right_daughter_element;
    }
    //���� ��������� ������� �� �����
    if (max_element != i)
    {
        swap(arr[i], arr[max_element]);

        // ���������� ����������� �� ������� ���� ��������� ��������
        Heapify(arr, size, max_element);
    }
}

//������� �������, �� ������ ���������� ����������
void HeapSort(int arr[], int size)
{
    //�������� ���� (������������� �����)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, size, i);
    }

    //���� �� ����� �������� �������� � ����
    for (int i = size - 1; i >= 0; i--)
    {
        //��������� �������� ����� �� ����
        swap(arr[0], arr[i]);

        //��������� ��������� heapify �� �������� ���
        Heapify(arr, i, 0);
    }
}

//�������� ������� ��� ��������� �� ����� ������ ������ n
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    HeapSort(arr, n);

    cout << "After sorting: ";
    PrintArray(arr, n);
}