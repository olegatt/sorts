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
        mass[i] = random() % 200-10;
        cout << "[" << i+1 << "]: " << mass[i] << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && mass[j-1] > mass[j];j--)
        {
            swap (mass[j-1], mass[j]);
        }
    }
    
    cout <<"=================" << endl;
    for (int i = 0; i < n; i++) 
    cout << "[" << i+1 << "]: " << mass[i] << endl;
    
    
    return 0;
}    