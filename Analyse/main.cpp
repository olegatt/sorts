#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;
void ShellSort (int*arr, int n);
void BubbleSort (int *arr, int n);
void InsertSort (int *arr, int n);
void SelectSort (int *arr, int n);
void QuickSort (int *arr, int n);
void HeapSort(int *arr, int n);
void Analiz (int *arr, int n);
void CoutMassive (const int n, int* mass);
int CinMassive ();


void Analiz (int *arr, int n)
{
	int arrs[n];
	for (int i = 0; i < n; i++)
	{arrs[i] = arr[i];}
	BubbleSort(arrs, n);
	
	for (int i = 0; i < n; i++)
	{arrs[i] = arr[i];}
	cout <<"\n";
 	SelectSort(arrs, n);
 	
 	for (int i = 0; i < n; i++)
	{arrs[i] = arr[i];}
	cout <<"\n";
 	InsertSort(arrs, n);
 	
 	for (int i = 0; i < n; i++)
	{arrs[i] = arr[i];}
	cout <<"\n";
 	ShellSort(arrs, n);
 	
 	for (int i = 0; i < n; i++)
	{arrs[i] = arr[i];}
	cout <<"\n";
 	HeapSort(arrs, n);
 	
 	for (int i = 0; i < n; i++)
	{arrs[i] = arr[i];}
	cout <<"\n";
	clock_t start_time5 = clock(); 
	QuickSort(arrs, n);
	clock_t end_time5 = clock();
    float time5 = double(end_time5-start_time5)/CLOCKS_PER_SEC;
 	cout << "Vremya sortirovki Quickom " << time5 << "c";
 	cout <<"\n";
}

void BubbleSort (int *arr, int n)
{
    clock_t start_time1 = clock();
    for(int i=0; i < n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap (arr[j], arr[j+1]);
            }
        }
    }
    clock_t end_time1 = clock();
    float time1 = double(end_time1-start_time1)/CLOCKS_PER_SEC;
 	cout << "Vremya sortirovki Bubblem " << time1 << "c"; 
}

void SelectSort (int *arr, int n)
{
    clock_t start_time2 = clock();
     for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
             min = j;
            }   
        }
        swap(arr[min], arr[i]);
    }
    clock_t end_time2 = clock();
    float time2 = double(end_time2-start_time2)/CLOCKS_PER_SEC;
 	cout << "Vremya sortirovki Selectom " << time2 << "c";
}

void InsertSort (int *arr, int n)
{
     clock_t start_time3 = clock();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && arr[j-1] > arr[j];j--)
        {
            swap (arr[j-1], arr[j]);
        }
    }
    clock_t end_time3 = clock();
    float time3 = double(end_time3-start_time3)/CLOCKS_PER_SEC;
	cout << "Vremya sortirovki Insertom " << time3 << "c";
}

void ShellSort (int*arr, int n)
{
    clock_t start_time4 = clock();
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
    clock_t end_time4 = clock();
    float time4 = double(end_time4-start_time4)/CLOCKS_PER_SEC;
 	cout << "Vremya sortirovki Shellom " << time4 << "c";
}

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

void QuickSortPred (int *arr, float n)
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

void HeapSort(int *arr, int n)
{
    clock_t start_time6 = clock();
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
    clock_t end_time6 = clock();
    float time6 = double(end_time6-start_time6)/CLOCKS_PER_SEC;
 	cout << "Vremya sortirovki Heapom " << time6 << "c";
}

int Menu(int N, int* massiv)
{
	int a; 
	
do{
	system("cls");
   	cout << "           << Menu >>              "<<endl;
    cout <<"1. Vvod massiva." << endl;
    cout <<"2. Vivod massiva."<< endl;
    cout <<"3. Otsort na x %."<< endl;
    cout <<"4. Bubble"<<endl;
    cout <<"5. Select"<<endl;
    cout <<"6. Insert"<<endl;
    cout <<"7. Shell"<<endl;
    cout <<"8. Heap"<<endl;
    cout <<"9. Quick"<<endl;
    cout <<"10. Analiz"<<endl;
    cout <<"0. Exit"<<endl;	

	cin>>a;
	switch(a)
	{
	case 1: CinMassive (); break;		
	case 2: CoutMassive (N, massiv); system("pause");break;	
	case 3:	{
	int per;
	float nn;
	cout<<"Na skolko % otsortirovat'?: ";
	cin>>per;
	nn=N*per/100;
	QuickSortPred(massiv, nn);
	break;}
 	case 4: BubbleSort(massiv, N); system("pause"); break;
 	case 5:	SelectSort(massiv, N); system("pause"); break;
 	case 6:	InsertSort(massiv, N); system("pause"); break;
 	case 7:	ShellSort(massiv, N); system("pause"); break;
 	case 8:	HeapSort(massiv, N); system("pause"); break;
 	case 9:	{
	clock_t start_time5 = clock(); 
	QuickSort(massiv, N);
	clock_t end_time5 = clock();
    float time5 = double(end_time5-start_time5)/CLOCKS_PER_SEC;
 	cout << "Vremya sortirovki Quickom " << time5 << "c";
	system("pause"); break;}
 	case 10: Analiz(massiv, N); system("pause"); break;
 	case 0:	return(0); break;
 	default: cout<<"V menu net takogo punkta"; system("pause"); break;
	}
}while(a!=0);	
}

int CinMassive () 
{
int N;
cout<<"Vvedite kol-vo elemntov v massive: ";
cin>>N;
int mass[N];
for (int i=0; i<N; i++) 
mass[i] = rand() % 10000 - 5000;
Menu(N, mass);
return 0; 
}

void CoutMassive (int n, int* arr) 
{ 
    cout<<"Otsort-ii massiv: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<" element massiva: "<<arr[i]<<endl;
    }
}

int main ()
{
 cout << "Sozdat' massiv nado shachala!!!"<< endl;
 CinMassive ();
 return 0;
}
