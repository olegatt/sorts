#include <iostream>
#include <cstdlib>
#include <ctime>

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
    srand(time(NULL));
    int n;
    cout <<"Введите размер массвива: ";
    cin >> n;
    int mass[n];
    cout << endl;
    
    for (int i=0; i<n; i++)
        mass[i] = rand() % 100;
    
    QuickSort(mass, n);
    
    cout << "Исходный, отсортироваанный массив: "<< endl;
    for (int i=0; i<n; i++)
        cout << mass[i]<< "  ";
    cout << endl;
    
    int key;
    cout << "Введи элемент для поиска: ";
    cin >> key;
    
    int l = 0, r = n;
    int search = -1;
    
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (key == mass[mid])
        {
            search = mid;
            break;
        }
        
        if (key < mass[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    if (search == -1)
        cout <<"Элемент не найден"<< endl;
    else
        cout << "Номер элемента: " << search+1 << "   " <<"Элемент: "<< mass[search];
    
    return 0;
}
