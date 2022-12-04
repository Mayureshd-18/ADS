#include <stdio.h>

void printarray(int* arr, int n){
    printf("The array is: ");
    for(int j =0;j<n;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
}

void Insertionsort(int* arr,int num){
    for(int i=1;i<num;i++){
        int key = arr[i];
        int j = i-1;
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;




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
    Insertionsort(arr,n);
    printarray(arr,n);

}