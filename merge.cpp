//MERGE SORT

#include<iostream>
#include<stdlib.h>
#include<omp.h>

using namespace std;

void merge(int arr[], int low1, int high1, int low2, int high2)
{
        int n = high1 - low1 + high2 - low2;
        int temp[n], i, j, k;
        i = low1;
        j = low2;
        k = 0;

        while(i <= high1 && j <= high2)
                if(arr[i]<arr[j])
                        temp[k++] = arr[i++];
                else
                        temp[k++] = arr[j++];
        while(i <= high1)
                temp[k++] = arr[i++];
        while(j <= high2)
                temp[k++] = arr[j++];
        for(i = low1, j = 0; i<= high2; i++, j++)
                arr[i] = temp[j];

}


void mergesort(int arr[], int low, int high)
{
        int mid;
        if(low < high)
        {
                mid = low + (high-low)/2;
                #pragma omp parallel sections
                {
                        #pragma omp section
                                mergesort(arr, low, mid);
                        #pragma omp section
                                mergesort(arr, mid+1, high);
                }
                merge(arr, low, mid, mid+1, high);
        }
}

int main()
{
        int n = 16;
        int arr[n];
        #pragma omp parallel for
                for(int i = 0; i<n; i++)
                        arr[i] = rand()%64;

        mergesort(arr, 0, n-1);
        cout<<"n: "<<n<<endl;
        for(int i=0; i<n; i++)
                cout<<arr[i]<<endl;
}
