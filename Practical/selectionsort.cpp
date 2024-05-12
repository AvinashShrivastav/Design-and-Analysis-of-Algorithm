#include <iostream>
using namespace std;

int selectionSort(int arr[], int n) {
    int i, j, min_idx;
    int comparisons = 0; // Initialize the comparison count

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++; // Increment the comparison count
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }

    return comparisons; // Return the total number of comparisons
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
            int c = selectionSort(arr, size[i]);
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