//QUICK SORT

#include<iostream>
#include<stdlib.h>
#include<omp.h>

using namespace std;

int partition(int arr[], int start, int end)
{
        int pivot = arr[end];
        int i = start - 1;
        for(int j = start; j < end; j++)
                if(arr[j]<pivot)
                {
                        i++;
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                }
        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;
        return (i+1);
}

void quicksort(int arr[], int start, int end)
{
        int index;
        if(start < end)
        {
                index = partition(arr, start, end);
                #pragma omp parallel sections
                {
                        #pragma omp section
                                quicksort(arr, start, index - 1);
                        #pragma omp section
                                quicksort(arr, index+1, end);
                }
        }
}

int main()
{
        int n = 16;
        int arr[n];

        #pragma omp parallel for
                for(int i = 0; i<n; i++)
                        arr[i] = rand()%64;

        quicksort(arr, 0, n-1);
        cout<<"n: "<<n<<endl;
        for(int i=0; i<n; i++)
                cout<<arr[i]<<endl;
}


