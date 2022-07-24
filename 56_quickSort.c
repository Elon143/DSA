#include <stdio.h>

voie printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int pivot = A[low];
}

void quickSort(int A[], int low, int high){
    int partitionIndex;  // Index of pivot after partition
    
    if (low<high){
    partitionIndex = partition(A, low, high);
    quickSort(A, low, partitionIndex-1);   // sort left subarray
    quickSort(A, partitionIndex+1, high);   // sort right subarray
    }
}


int main(){

    int A[] = {3,5,6,2,45,23,4,12,5};
    int n = 9;
    printArray(A, n);
    quickSort(A, 0, n-1);
    printArray(A, n);

    return 0;
}