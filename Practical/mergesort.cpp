#include <iostream>

using namespace std;

int merge(int A[], int p, int q, int r) {
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl];
    int R[nr];

    for (int i = 0; i < nl; i++) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < nr; j++) {
        R[j] = A[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;
    int comparisons = 0; // Initialize the comparison count

    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
        comparisons++; // Increment the comparison count
    }

    while (i < nl) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nr) {
        A[k] = R[j];
        j++;
        k++;
    }

    return comparisons; // Return the total number of comparisons
}

int mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        int left_comparisons = mergeSort(A, p, q);
        int right_comparisons = mergeSort(A, q + 1, r);
        int merge_comparisons = merge(A, p, q, r);
        return left_comparisons + right_comparisons + merge_comparisons;
    }
    return 0; // Base case: no comparisons needed
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
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
            int c = mergeSort(arr, 0,s );
            cout<<"Sorted Array :  ";
            printArray(arr, s);
            cout<<"    Number of Comparisons : "<<c;
            comp += c;
            cout<<endl<<endl;

        }
        float avg = comp/s;
        cout<<"Average Number of comparisons for input size  "<<s<<" = "<<avg<<endl;
    }


    return 0;

}


