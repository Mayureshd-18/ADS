
#include <stdio.h>

void printarray(int* arr, int n){
    printf("The array is: ");
    for(int j =0;j<n;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
}


int partition(int *arr,int low,int high){
    int pivot = arr[low];
    int temp;
    int i = low+1;
    int j = high;

    do{

        while(arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;


    return j;

}

void quicksort(int * arr, int low, int high){
    int partitionIndex;

    if(low<high){
        partitionIndex = partition(arr,low,high);
        quicksort(arr,low,partitionIndex);
        quicksort(arr,partitionIndex+1,high);
    }
}

int main() {
    // Write C code here
    int arr[5] = {3,2,4,1,5};
    quicksort(arr,0,4);

    printarray(arr,5);
    return 0;
}