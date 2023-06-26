/*
Implementation and Time analysis of factorial program using iterative 
and recursive method.
*/
#include <stdio.h>
#include <conio.h>
long i_factorial(int);
long r_factorial(int);
void main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Iterative Factorial of %d is %d",n,i_factorial(n));
    if (n<0)
        printf("\nNegative integers are not allowed.");
    else
        printf("\nRecursive Factorial of %d is %d",n,r_factorial(n));
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
Recursive Factorial of 5 is 120
*/