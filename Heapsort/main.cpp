#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void HeapSort(int *arr, int n)
{
    for (int i=n-1; i>0; i--)
    {
        for (int j=i; j>0; j--)
        {
            int index = (j-2)/2;
            if (arr[j] >= arr[index])
                swap(arr[j], arr[index]);
        }
        swap(arr[0], arr[i]);
    }
}

int main()
{
    srand(time(NULL));
    int n;
    cout <<"Введите длину массива: ";
    cin >> n;
    int mass[n];
    
    cout << "Исходный массив: " << endl;
    for (int i=0; i<n; i++)
        mass[i] = rand() % 200;
    for (int i=0; i<n; i++)
        cout << mass[i] << "   ";
    
    HeapSort(mass, n);
    
    cout << endl<< "Отсортированный массив: "<< endl;
    for (int i=0; i<n; i++)
        cout << mass[i]<< "   ";
    
    return 0;
}
