#include <stdio.h>
void merge(int * arr, int mid, int low, int high){
    int i=low, j = mid+1, k = low, B[100];

    while(i<=mid  && j<=high){
        if(arr[i]<arr[j]){
            B[k] = arr[i];
            i++;k++;
        }
        else{
            B[k] = arr[j];
            k++;j++;
        }
    }

    while(i<=mid){
        B[k] = arr[i];
        i++;k++;
    }

    while(j<=high){
        B[k] = arr[j];
        k++;j++;
    }

    for (int t = low; t <= high; t++)
    {
        arr[t] = B[t];
    }

}

void mergeSort(int A[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main(void){
    int A[7] = {9, 1, 4, 14, 4, 15, 6};
    mergeSort(A,0,6);
    for(int i = 0;i<7;i++){
        printf("%d ",A[i]);
    }
}
