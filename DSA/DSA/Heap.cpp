#include <iostream>
#include <cmath>

using namespace std;

//ѕроцедура дл€ перетворенн€ на дв≥йкову купу п≥ддерева з кореневим вузлом i, що Ї
//≥ндексом arr[]. n - розм≥р купи

void Heapify(int arr[], int size, int i)
{
    int max_element = i; //кор≥нь дерева
    //≤н≥ц≥ал≥зовуЇмо найб≥льший елемент €к кореневий
    int left_daughter_element = 2 * i + 1; 
    int right_daughter_element = 2 * i + 2; 

    //якщо л≥вий доч≥рн≥й елемент б≥льший за кор≥нь купи
    if (left_daughter_element < size && arr[left_daughter_element] > arr[max_element])
    {
        max_element = left_daughter_element;
    }
    //якщо правий доч≥рн≥й елемент б≥льший н≥ж найб≥льший елемент купи на даний момент
    if (right_daughter_element < size && arr[right_daughter_element] > arr[max_element])
    {
        max_element = right_daughter_element;
    }
    //якщо найб≥льший елемент не кор≥нь
    if (max_element != i)
    {
        swap(arr[i], arr[max_element]);

        // –екурсивно перетворимо на дв≥йкову купу зачеплене п≥ддерево
        Heapify(arr, size, max_element);
    }
}

//ќсновна функц≥€, що виконуЇ п≥рам≥дальне сортуванн€
void HeapSort(int arr[], int size)
{
    //ѕобудова купи (перегруповуЇмо масив)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, size, i);
    }

    //ќдин за одним вит€гуЇмо елементи з купи
    for (int i = size - 1; i >= 0; i--)
    {
        //ѕерем≥щуЇмо поточний кор≥нь до к≥нц€
        swap(arr[0], arr[i]);

        //¬икликаЇмо процедуру heapify на зменшен≥й куп≥
        Heapify(arr, i, 0);
    }
}

//ƒопом≥жна функц≥€ дл€ виведенн€ на екран масиву розм≥ру n
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