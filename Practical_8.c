/*
Implementation of making a change problem using dynamic programming 
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int numberofcoins(int [5],int,int);
int main()
{
    int d[5];
    int n,N;
    printf("Enter the no. of units(n):");
    scanf("%d",&n);
    printf("Enter the values of coins:");
    for (int i = 1; i <=n ; i++)
        scanf("%d",&d[i]);
    printf("Enter total units for which the changes if required(N):");
    scanf("%d",&N);
    printf("Minimum no. of coins %d",numberofcoins(d,n,N));
    return 0;
}
int minval(int x,int y)
{
    if(x<y)
        return x;
    else 
        return y;
}
int numberofcoins(int d[],int n,int N)
{
    int i,j;
    int c[10][10];
    for ( i = 0; i <= n; i++)
        for ( j = 0; j <=N; j++)
            c[i][j]=9999;    //initialize table by infinity
    for ( i = 0; i <= n; i++)
        c[i][0]=0;
    for ( j = 0; j <=N; j++)
        c[0][j]=j;
    //filling up table column by column
    for ( j = 1; j <=N; j++)
    {
        for ( i = 1; i <= n; i++)
        {
            if(i==1)
            {
                if(j<d[i])
                   c[i][j]=9999; //infinity
                else
                    c[i][j]=1+c[1][j-d[1]];
            }
            else if (j<d[i])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=minval(c[i-1][j],1+c[i][j-d[i]]);
        }
    }
    printf("\nPrinting the table for no. of coind:\n");
    for ( i = 0; i <= n; i++)
    {
        for ( j = 0; j <=N; j++)
        {
            printf(" %d",c[i][j]);
        }
        printf("\n");
    }
    return c[n][N];         //returning bottom most and rightmost element
}

/*
OUTPUT:
Enter the no. of units(n):3
Enter the values of coins:1 4 6
Enter total units for which the changes if required(N):8

Printing the table for no. of coind:
 0 1 2 3 4 5 6 7 8
 0 1 2 3 4 5 6 7 8
 0 1 2 3 1 2 3 4 2
 0 1 2 3 1 2 1 2 2
Minimum no. of coins 2
*/