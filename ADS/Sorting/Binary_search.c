#include <stdio.h>

int binarySearch(int * arr, int val){
    int low = 0;
    int high = 4;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==val){
            printf("Element found at the position %d",mid);
            return 1;
        }
        else if(val>arr[mid])
            low = mid+1;
        else
            high = mid-1;

    }
    printf("Element not found.");
    return 0;
}

int main(void){
    int arr[5];
    for(int i = 0;i<5;i++){
        scanf("%d",&arr[i]);
    }

    binarySearch(arr,30);


}