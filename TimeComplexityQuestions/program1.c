#include <stdio.h>

// Ques1. Find the time complexity of the func1 function in the program show in program1.c as follows:

void foo(int array[], int length)
{
    int sum = 0;
    int product = 31;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    for (int i = 0; i < length; i++)
    {
        product *= array[i];
    }
}

int main()
{
    int arr[] = {3, 5, 66};
    foo(arr, 3);
    return 0; 
}