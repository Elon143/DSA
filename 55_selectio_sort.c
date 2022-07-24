#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    printf("Running Selecton sort.. \n");
    // for passes
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    // Input Array
    // 00,  01,  02,  03,  04
 //   |03,  05,  02,  12,  11

    // After 1st pass      //      
    // 00,  01,  02,  03,  04
    // 02, |05,  03,  12,  11       

    // After 2nd pass           // j=5,   inexOfMin = 3 ; i= 2;
    // 00,  01,  02,  03,  04
    // 02,  03, |05,  12,  11

    // After 3rd pass           // j=5,   inexOfMin = 5 ; i = 3 = 02 index;
    // 00,  01,  02,  03,  04
    // 02,  03,  05, |12,  11

    // After 4th pass           // j=12,   inexOfMin = 12 ; i = 4;
    // 00,  01,  02,  03,  04
    // 02,  03,  05,  11, |12


    int A[] = {3, 5, 2, 12, 11};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
}