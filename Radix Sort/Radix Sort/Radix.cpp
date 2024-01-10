#include <iostream>

using namespace std;

// Функція корисності для отримання максимального значення arr[]
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

// Функція, яка виконує підрахунок типу arr[] відповідно до
// цифри, представлена exp.
void CountingSort(int arr[], int size, int exp)  //сортування підрахунком
{
    int* output = new int[size]; // output array
    int i, count[10] = { 0 };
    //Зберігати кількість входів у count[] 
    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Змінює count[i], щоб тепер count[i] містив фактичні дані
    // позиція цієї цифри у виводі[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    //Будуємо вихідний масив
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //Копіюємо вихідний масив в arr[], щоб зараз arr[]
    //містив відсортовані числа відповідно до поточної цифри
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

// Основна функція, яка сортує arr[] розміру n за допомогою
// Radix Sort
void RadixSort(int arr[], int n)
{
    //Знаходить максимальне число, щоб знати кількість цифр
    int m = GetMax(arr, n);

    //Викостовується рахункове сортування для кожної цифри. 
    //Замість цифри передається exp. exp є 10^i
    //де i - поточний розрядний номер
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