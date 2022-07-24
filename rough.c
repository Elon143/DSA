#include <stdio.h>
#include <stdlib.h>



/******
// program to find percent of any number


int main()
{  for (int i = 0; i < 10; i++)
{
    
    float percent;
    int num, value;

    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the value how much percent you want of the number: ");
    scanf("%d",&value);
    percent = (num*value)/100;
   
    printf("The  %d percent is: %0.2f\n",value, percent);
   
}

    return 0;
}

****/

/***
int main()
{  for (int i = 0; i < 2; i++)
{
    
    float percentage, marks;
    int totalMarks;
    printf("Enter the totalmarks to know your percentage: ");
    scanf("%d",&totalMarks);
    printf("Enter marks you get in exams: ");
    scanf("%f", &marks);
    if (marks>totalMarks)
    {
     printf("You Entered wrong value: ");   
    }else{  
        percentage = (marks*100)/totalMarks;
    }
    printf("your percentage is: %0.2f\n", percentage);
   
}

    return 0;
}

*********/