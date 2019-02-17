#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
    int n;
    int mass[n];
    
    cout<< "Введите кол-во числе а массиве: ";
    cin>>n;
////////////Zapolnenie///////////////
    for(int i=0; i<n; i++)
        {
        mass[i] = random() % 200-100;
        cout << "[" << i+1 << "]: " << mass[i] << endl;
        }
 ////////////Sortirovka///////////////
    for(int i=0; i < n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(mass[j]>mass[j+1])
            {
                swap (mass[j], mass[j+1]);
            }
        }
    }
////////////////Vivod/////////////////
    cout<<"Сортировка выполнена: "<<endl;
    for(int i=0; i<n; i++)
        {
        cout << "[" << i+1 << "]: " << mass[i] << endl;
        }
    return 0;
}
