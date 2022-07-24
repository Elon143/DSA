#include <stdio.h>

// Ques. Find the time complexity of the func1 function in the program show in program2.c as follows:


void func(int n)
{
    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d , %d\n", i, j);
        }
    }
    
}

int main()
{
    func(4);
    return 0;
}