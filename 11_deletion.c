#include<stdio.h>

void display(int arr[], int n){
    // Code for Traversal 
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[],int size,int index, int capacity){
    // // code for deletion
    // if (index>=capacity)
    // {
    //     return -1;
    // }
    for (int i = index; i<size-1; i++)
    {
        arr[i]=arr[i+1] ;
    }
   

}

int main(){
    int arr[100] = {1, 2, 3, 6,3};
    int size = 5, element = 40, index=2, capacity=100;
    display(arr, size);
    indDeletion(arr, size, index, capacity);
    size -=1;
    display(arr, size);

    return 0;
}