#include <stdio.h>

void printarray(int* arr, int n){
    printf("The array is: ");
    for(int j =0;j<n;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
}

int partition(int * arr, int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;
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

void quickSort(int *arr, int low, int high){

    int partitionIndex;

    if(low<high){
        partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex);
        quickSort(arr,partitionIndex+1,high);
    }
}

int main(void){
    int arr[10] = {3,5,4,2,1,6,7,8,0,9};

    printarray(arr,10);
    quickSort(arr,0,9);
    printarray(arr,10);

}