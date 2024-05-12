#include <iostream>
#include <cmath>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int array_size, int arr[], int dig) {

    int C[10] = {0};
    int B[array_size];

    int pow_of_10 = pow(10, dig);
    // Frequency array
    for (int i = 0; i < array_size; i++) {
        C[(arr[i] / pow_of_10) % 10]++;
    }
    // Cummulative frequncy array
    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }


    // Filling correct sequence in B
    for (int i = array_size - 1; i >= 0; i--) {
        B[C[(arr[i] / pow_of_10) % 10] - 1] = arr[i];
        C[(arr[i] / pow_of_10) % 10]--;
    }
    
    // Copying back sorted array to arr
    for (int i = 0; i < array_size; i++) {
        arr[i] = B[i];
    }
}

// Apply count sort to every digit of the array
void radixsort(int arr[],int size){
    for (int i = 0; i < size; i++) {
        countSort(10, arr, i);
    }
}


int main() {
    int arr[10] = {123, 321, 323, 543, 976, 467, 335, 754, 656, 789};
    cout << "Array array: ";
    printArray(arr, 10);
    radixsort(arr,3);
    cout << "Sorted array: ";
    printArray(arr, 10);

    return 0;
}
