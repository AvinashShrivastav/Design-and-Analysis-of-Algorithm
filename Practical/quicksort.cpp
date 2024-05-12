#include <iostream>
using namespace std;

// Number of ciompariosn is wrong - Please rectify.

int partition(int A[], int p, int r, int& comparison_count) {
    int pivot = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
            comparison_count++; // Increment the comparison count
        }
    }
    swap(A[i + 1], A[r]);
    comparison_count++; // Increment the comparison count for the final swap
    return i + 1;
}

void quickSort(int A[], int p, int r, int& comparison_count) {
    if (p < r) {
        int q = partition(A, p, r, comparison_count);
        quickSort(A, p, q - 1, comparison_count);
        quickSort(A, q + 1, r, comparison_count);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

float averageComp(int arr[],int size)
{
    int sum = 0;
    for(int i = 0; i < size ; i ++){
        sum += arr[i];
    } 
    float avg = sum/size;

    return avg;
}


void generateRamdomArray(int arr[],int size){
    for(int i = 0 ; i < size; i++)
    {
        arr[i] = rand()%100;
    }

}

// int main() {
//     int A[] = { 2, 3, 4, 2, 2, 4, 57, 43, 24, 23 };
//     cout << "Array: ";
//     printArray(A, 10);

//     int comparison_count = 0; // Initialize the comparison count
//     quickSort(A, 0, 9, comparison_count);

//     cout << "Sorted Array: ";
//     printArray(A, 10);
//     cout << "Number of comparisons: " << comparison_count << endl;
// }

int main()
{
    int size[10] = {10,20,30,40,50,60,70,80,90,100};
    for (int i = 0; i < 10; i ++)
    {
        float comp;
        int no_array = 10;
        int s = size[i];
        for (int j = 0; j < no_array; j++)
        {
            
            int arr[s];
            generateRamdomArray(arr,s);
            cout<<"Random Array  : ";
            printArray(arr,s);
            int comparison_count = 0; // Initialize the comparison count
            quickSort(arr, 0, 9, comparison_count);
            cout<<"Sorted Array :  ";
            printArray(arr, s);
            cout<<" Number of Comparisons : "<<comparison_count;
            comp += comparison_count;
            cout<<endl<<endl;

        }
        float avg = comp/s;
        cout<<"Average Number of comparisons for input size  "<<s<<" = "<<avg<<endl;
    }


    return 0;

}