//ENUMERATE SORT

#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
        int arr[] = {5, 7, 2, 3, 2, 9};
        int brr[6];
        //compare each element with all other elements, and find the no. of
        //elements less than that as 'count', and store in that index
        //in new array
        #pragma omp parallel for
                for(int i=0; i<6; i++)
                {
                        int c = 0;
                        for (int j = 0; arr[j]; j++)
                                if(arr[j]<arr[i] || (i<j && arr[i] == arr[j]))
                                        c++;
                        brr[c] = arr[i];
                }
        for(int i = 0; i<6; i++)
                cout<<brr[i]<<endl;

        return 0;
}
