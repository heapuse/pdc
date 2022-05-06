//ODDEVEN SORT

#include<iostream>
#include<omp.h>
#include<stdlib.h>

using namespace std;

int main()
{
        int n = 16, j=0;
        int arr[n];
        bool sort = false;

        #pragma omp parallel for
                for(int i = 0; i<n; i++)
                        arr[i] = rand()%64;
//      #pragma omp parallel
        for(j=0; j<n;j++)
        {
                sort = true;
                #pragma omp parallel for
                        for(int i=1; i<n; i+=2)
                                if(arr[i]>arr[i+1])
                                {
                                        sort = false;
                                        int temp = arr[i];
                                        arr[i] = arr[i+1];
                                        arr[i+1] = temp;
                                }

                #pragma omp parallel for
                        for(int i=0; i<n; i+=2)
                                if(arr[i]>arr[i+1])
                                {
                                        sort = false;
                                        int temp = arr[i];
                                        arr[i] = arr[i+1];
                                        arr[i+1] = temp;
                                }

                #pragma omp parallel for
                        for(int i=0; i<n; i+=2)
                                if(arr[i]>arr[i+1])
                                {
                                        sort = false;
                                        int temp = arr[i];
                                        arr[i] = arr[i+1];
                                        arr[i+1] = temp;
                                }
                if(sort)
                        break;
        }
        cout<<j<<endl;
        cout<<"n: "<<n<<endl;
        for(int i=0; i<n; i++)
                cout<<arr[i]<<endl;
}
