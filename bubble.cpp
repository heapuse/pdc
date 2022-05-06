//BUBBLE SORT

#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

int main()
{
        int n = 16;
        int arr[n];
        #pragma omp parallel for
                for(int i = 0; i<n; i++)
                        arr[i] = rand()%64;

        for(int i=0; i<n-1; i++)
                #pragma omp parallel for
                        for(int j=0; j<n; j++)
                        {
                                if(arr[j] > arr[j+1])
                                {
                                        int temp = arr[j];
                                        arr[j] = arr[j+1];
                                        arr[j+1] = temp;
                                }
                        }
        cout<<"n: "<<n<<endl;
        for(int i = 0; i<n; i++)
                cout<<arr[i]<<endl;
        return 0;
}

