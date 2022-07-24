#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n");
}

// // *** This is Basic bubble sort function to sort an Array
// void bubbleSort(int *A, int n){
//     int temp;
//     for (int i = 0; i <n-1; i++)  // For number of passes
//     {
//         printf("Working on pass number %d\n", i+1);
//         for (int j = 0; j < n-1-i; j++)  // For comparison in each pass
//         {
//             if(A[j]>A[j+1]){
//                 temp = A[j];
//                 A[j] = A[j+1];
//                 A[j+1] = temp;
//             }
//         }
//     }
// }


// *** This is an Adaptive bubble_sort function to sort an Array
void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of passes
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < (n-1-i); j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}


int main()
{
    // int A[] = {3,5,434,6,34,56,34,59};
    int A[] = {3, 50, 434, 69, 346, 5, 34, 59};
    // int A[] = {1,2,4,7,8,9,11,12};
    int n = 8;

    printArray(A, n); // Printing the array before sorting
    // bubbleSort(A, n); // Function to sort the array
    bubbleSortAdaptive(A, n);    // Function to sort the array
    printArray(A, n); // Printing the array after sorting

    return 0;
}