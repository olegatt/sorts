#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void QuickSort (int *arr, int n)
{
    int size = n;
    int c = arr[(n/2)];
    int k = 0;
    
    do
    {
        while(arr[k] < c) k++;
        while(arr[n] > c) n--;
        
        if (k <= n)
        {
            swap(arr[k], arr[n]);
            k++;
            n--;
        }
    }
    while (k <= n);
    
    if (n > 0)
        QuickSort(arr, n);
    if (size > k)
        QuickSort(arr+k, size-k);
}

int main()
{
    
    int n;
    cout << "Введите кол-во массива: ";
    cin >> n;
    cout << endl;
    int mass[n];
    
    for (int i=0; i<n; i++)
        mass[i] = rand() % 100;
    
    cout << "Исходный массив: ";
    for (int i=0; i<n; i++)
        cout << mass[i] << "   ";
    
    cout << endl;
    
    QuickSort (mass, n);
    
    cout << "Отсортированный массив: ";
    for (int i=0; i<n; i++)
        cout << mass[i]<< "   ";
    
    return 0;
    
}
