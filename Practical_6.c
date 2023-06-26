/*
Implementation of a knapsack problem using dynamic programming.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int table[5][6];
void DKP(int n,int W,int w[],int v[]);

int main()
{
    int w[]={0,2,3,4,5};
    int v[]={0,3,4,5,6};
    int W=5,n=4,i;
    printf("\n\t\t 0/1 Knapsack Problem usind Dynamic Programming");
    printf("\nGiven Data:");
    printf("\n w[i]  v[i]");
    printf("\n--------------------");
    for ( i = 1; i <= n; i++)
        printf("\n  %d     %d",w[i],v[i]);
    printf("\n\t\tCapacity=%d",W);
    for ( i = 0; i <=n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            table[i][j]=0;
        }
    }
    DKP(n,W,w,v);
}
int max(int a,int b)
{
    if (a>b)
        return a;
    else 
        return b;
}
void DKP(int n,int W,int w[5],int v[5])
{
    void find_item(int,int,int[]);
    int i,j,val1,val2;
    for ( i = 0; i <= n; i++)
    {
        for ( j = 0; j <= W; j++)
        {
            table[i][0]=0;
            table[0][j]=0;
        }
    }
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= W; j++)
        {
            if (j<w[i])
                table[i][j]=table[i-1][j];
            else if (j>=w[i])
            {
                val1=table[i-1][j];
                val2=v[i]+table[i-1][j-w[i]];
                table[i][j]=max(val1,val2);
            }
        }
    }
    printf("\n Table Constructed using dynamic programming is...\n");
    for ( i = 0; i <= n; i++)
    {
        for ( j = 0; j <= W; j++)
        printf(" %d",table[i][j]);
        printf("\n");
    }
    find_item(n,W,w);
}
void find_item(int i,int k,int w[5])
{
    printf("\nSolution for the Knapsack...");
    while (i>0&&k>0)
    {
        if (table[i][k]!=table[i-1][k])
        {
            printf("\nItem %d is selected",i);
            i=i-1;
            k=k-w[i];
        }
        else
            i=i-1;
    }
}

/*
OUTPUT:

                 0/1 Knapsack Problem usind Dynamic Programming
Given Data:
 w[i]  v[i]
--------------------
  2     3
  3     4
  4     5
  5     6
                Capacity=5
 Table Constructed using dynamic programming is...
 0 0 0 0 0 0
 0 0 3 3 3 3
 0 0 3 4 4 7
 0 0 3 4 5 7
 0 0 3 4 5 7

Solution for the Knapsack...
Item 2 is selected
Item 1 is selected
*/