#include <stdio.h>

void printarray(int* arr, int n){
    printf("The array is: ");
    for(int j =0;j<n;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
}

void bubblesort(int* arr, int n){
    int temp;
    int isSorted;
    int ctr = 0;
    for(int i=0;i<n-1;i++){
        isSorted = 1;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        ctr++;
        if(isSorted){
            printf("Took %d passes\n",ctr);
            return;
        }
    }
    printf("Took %d passes\n",ctr);

}

int main(void){
    int arr[5];
    int n = 5 ;

    for(int i=0;i<5;i++){
        printf("Enter the element you want to add into the array:\n");
        scanf("%d",&arr[i]);
    }

    printarray(arr,n);
    bubblesort(arr,n);
    printarray(arr,n);

}
