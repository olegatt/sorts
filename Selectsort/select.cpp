#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cout << "Введите кол-во числе в массиве: "<< endl;
    cin >> n;
    
    int mass[n];
    
    for (int i = 0; i < n; i++)
    {
        mass[i] = random() % 200-100;
        cout << "[" << i+1 << "]: " << mass[i] << endl;
    }
    for (int i = 0; i< n-1; i++ )
    {
        int min = i;
        for (int j = i+1; j<n; j++)
        {
            if (mass[j] < mass[min])
                min = j;
        }
        swap (mass[min], mass[i]);
    }
    
    
    cout <<"=================" << endl;
    for (int i = 0; i < n; i++) 
    cout << "[" << i+1 << "]: " << mass[i] << endl;
    
    
    return 0;
}