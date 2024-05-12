#include <iostream>
using namespace std;

int insertionSort(int arr[], int n)
{
    int i, key, j;
    int comp = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comp++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        comp++;
    }
    return comp;

}

void printArray(int arr[], int n)
{
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


int main()

{   int sample_size = 10;
    for(int no_array = 1; no_array < sample_size; no_array ++)
    {
        int size = rand()%71+ 30;
        int comp[size];
    for (int i = 0; i < no_array; i++)
    {
        int arr[size];
        for (int j = 0; j < size; j++)
        {
            arr[j] = rand()%100;
        }
        cout<<"Random Array :  ";
        printArray(arr, size);
        int c = insertionSort(arr, size);
        cout<<"Sorted Array :  ";
        printArray(arr, size);
        cout<<"    Number of Comparisons : "<<c;
        comp[i] = c;
        cout<<endl<<endl;

    }
    float avg = averageComp(comp,size);
    cout<<"Average Number of comparisons = "<<avg<<endl;

    }
    

    return 0;

}