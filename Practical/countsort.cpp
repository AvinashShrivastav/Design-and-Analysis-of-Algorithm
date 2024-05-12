#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void countSort(int array_size, int arr[],int max_val = 255){
    int C[max_val];
    for (int i = 0; i<max_val; i++){
        C[i] = 0;
    }
    int B[array_size];
    for(int i = 0; i <array_size; i++){
        C[arr[i]] += 1;
    }

    for(int i =1; i < max_val; i++){
        C[i] += C[i-1]; 
    }
    for(int i = array_size - 1; i >=0; i--){
        B[C[arr[i]] - 1] = arr[i]; // subtract one from the count value
        C[arr[i]] -= 1;
    }
    for (int i = 0; i <array_size; i++){
        arr[i] = B[i];
    }

}

int main()
{
    int k = 10; // maximum value in the array
    int n = 10; // size of the array

    int A[n] = {3,4,6,1,2,8,5,8,2,1};
    
    cout<<"Array :"<<endl;
    printArray(A,n);
    countSort(n,A,10);
    cout<<"Sorted Array : "<<endl;
    printArray(A,n);
}
