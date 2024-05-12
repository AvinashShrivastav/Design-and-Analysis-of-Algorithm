#include <iostream>
using namespace std;
int passes,comparison,s;

void insertionSort(int arr[], int n) {
    int i, key, j;
    passes = 0;
    s = 0;
    comparison=0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        passes++;
        while (j >= 0 && arr[j] > key) {
            s++;
            ++comparison;
            arr[j + 1] = arr[j];
            --j;
        }
        if (j >= 0 && arr[j] != key) // Increment comparisons for the initial comparison of the current element
            ++comparison;
        arr[j + 1] = key;
    }
    cout<<"Comp"<<comparison;
}

int main(){
    int A[] = {6,3,5,8,16};
    insertionSort(A,5);
    for(int i = 0; i < 5; i++){
        cout<<A[i]<<" ";
    }
    // cout<<comparison;


}