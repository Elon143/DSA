#include <stdio.h>

// int linearSearch(int arr[], int size, int element){
//     for (int i=0; i<size; i++){
//         if(arr[i]==element){
//             return i;
//         }
//     }
//     return -1;
// }

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while (low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    // Searching ends
    return -1;
    
}

int main(){
    // Unsorted array of Linear search
    // int arr[] = {1,2,3,5,6,345,56,45,34,56,34};
    // int size = sizeof(arr)/sizeof(int);

    // Sorted array of binary search
    int element;
    printf("Enter the elment you are searching: ");
    scanf("%d",&element);
    int arr[] = {12,34,45,49,56,63,67,68,69,70};
    int size = sizeof(arr)/sizeof(int);
    printf("Size of an Arr = %d\n",size);
    // int element = 69;
    int searchIndex = binarySearch(arr,size,element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}