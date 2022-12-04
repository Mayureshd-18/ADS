#include <stdio.h>


void printarray(int* arr, int n){
    printf("The array is: ");
    for(int j =0;j<n;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
}

void Selectionsort(int* arr, int num){
    int temp;
    for(int i=0;i<num-1;i++){
        int min_index = i;
        for(int j = i+1;j<num;j++){
            if(arr[j]<arr[min_index])
                min_index  = j;
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

    }

}


int main(void){
    int arr[5];
    int n = 5 ;

    for(int i=0;i<5;i++){
        printf("Enter the element you want to add into the array:\n");
        scanf("%d",&arr[i]);
    }

    printarray(arr,n);
    Selectionsort(arr,n);
    printarray(arr,n);
}