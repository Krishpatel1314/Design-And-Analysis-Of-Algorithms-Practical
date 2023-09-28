/*
Implementation and Time analysis of factorial program using iterative 
and recursive method.
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
long i_factorial(int);
long r_factorial(int);
void main()
{
    int n;
    clock_t start, end;
    printf("Enter a number:");
    scanf("%d",&n);
    start = clock();
    printf("Iterative Factorial of %d is %d",n,i_factorial(n));
    end = clock();
    double d1 = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to Iterative Factorial to execute in seconds : %f", d1);
    start = clock();
    if (n<0)
        printf("\nNegative integers are not allowed.");
    else
        printf("\nRecursive Factorial of %d is %d",n,r_factorial(n));
    end = clock();
    double d2 = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to Recursive Factorial to execute in seconds : %f", d2);
}
long i_factorial(int n)
{
    int i;
    long f=1;
    for ( i = 1; i <= n; i++)
        f=f*i;
    return f;
}
long r_factorial(int n)
{
    if (n==0)
        return 1;
    else 
        return (n*r_factorial(n-1));
}

/*
OUTPUT:
Enter a number:5
Iterative Factorial of 5 is 120
Time taken to Iterative Factorial to execute in seconds : 0.005000
Recursive Factorial of 5 is 120
Time taken to Recursive Factorial to execute in seconds : 0.002000
*/