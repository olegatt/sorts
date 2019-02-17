#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void ShellSort (int n, int arr[])
{
    int t;
    for (int step = n/2; step > 0; step /=2 )
    {
        for(int i = step; i<n; i++)
        {
            int j;
            t = arr[i];
            for(j = i; j>=step; j-=step)
            {
                if (t < arr[j-step])
                    arr[j] = arr[j-step];
                else
                    break;
            }
            arr[j] = t;
        }
    }
}

int main ()
{
    int n;
    cout << "Ведите кол-во эелементов массива: "<< endl;
    cin >> n;
    int arr[n];
    cout << "Исходный массив: " << endl;
    for (int i=0; i<n; i++)
    {
        arr[i] = rand() % 100-50;
        cout << arr[i]<< "   ";
    }
    cout << endl;
    
    ShellSort(n,arr);
    
    cout << "Отсортированный массив: "<< endl;
    for (int i=0; i<n; i++)
    {
        cout << arr[i]<< "   ";
    }
    return 0;
}
