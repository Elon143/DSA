#include<stdio.h>

void display(int arr[], int n){
    // Code for Traversal 
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[],int size,int element, int capacity, int index){
    // code for insertion
    if (size>=capacity)
    {
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
    

}

int main(){
    int arr[100] = {1, 2, 3, 6,3};
    int size = 5, element = 40, index=3, capacity=100;
    display(arr, size);
    indInsertion(arr, size, element, capacity, index);
    size +=1;
    display(arr, size);

    return 0;
}