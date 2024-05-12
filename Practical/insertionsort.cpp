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
        // comp++;
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


void generateRamdomArray(int arr[],int size){
    for(int i = 0 ; i < size; i++)
    {
        arr[i] = rand()%100;
    }

}




int main()

{
    // int size[10] = {10,20,30,40,50,60,70,80,90,100};
    // for (int i = 0; i < 10; i ++)
    // {
    //     float comp;
    //     int no_array = 10;
    //     int s = size[i];
    //     for (int j = 0; j < no_array; j++)
    //     {
            
    //         int arr[s];
    //         generateRamdomArray(arr,s);
    //         cout<<"Random Array  : ";
    //         printArray(arr,s);
    //         int c = insertionSort(arr, size[i]);
    //         cout<<"Sorted Array :  ";
    //         printArray(arr, s);
    //         cout<<"    Number of Comparisons : "<<c;
    //         comp += c;
    //         cout<<endl<<endl;

    //     }
    //     float avg = comp/s;
    //     cout<<"Average Number of comparisons for input size  "<<s<<" = "<<avg<<endl;
     int A[] = {6,3,5,8,16};
     printArray(A,5);
     int c = insertionSort(A,5);
     printArray(A,5);
     cout<<c;

    return 0;

}






















    // int no_array = 10;
    // int s = size[i];
    
    // int comp[10];
    // for (int i = 0; i < no_array; i++)
    // {
    //     int arr[size[i]];
    //     for (int j = 0; j < size[i]; j++)
    //     {
    //         arr[j] = rand()%100;
    //     }
    //     cout<<"Random Array :  ";
    //     printArray(arr, size[i]);
    //     int c = insertionSort(arr, size[i]);
    //     cout<<"Sorted Array :  ";
    //     printArray(arr, size[i]);
    //     cout<<"    Number of Comparisons : "<<c;
    //     comp[i] = c;
    //     cout<<endl<<endl;

    // }
    

//     return 0;

// }