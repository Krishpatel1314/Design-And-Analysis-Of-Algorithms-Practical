/*
Implementation of a knapsack problem using dynamic programming.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 15
int table[SIZE][SIZE];
void DKP(int n,int W,int w[],int v[]);

int main()
{
    int w[]={0,2,3,5,7,1,4,1};
    int v[]={0,10,5,15,7,6,18,3};
    int W=12,n=7,i;
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
void DKP(int n,int W,int w[SIZE],int v[SIZE])
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
void find_item(int i,int k,int w[SIZE])
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
  2     10
  3     5
  5     15
  7     7
  1     6
  4     18
  1     3
                Capacity=12
 Table Constructed using dynamic programming is...
 0 0  0  0  0  0  0  0  0  0  0  0  0
 0 0 10 10 10 10 10 10 10 10 10 10 10
 0 0 10 10 10 15 15 15 15 15 15 15 15
 0 0 10 10 10 15 15 25 25 25 30 30 30
 0 0 10 10 10 15 15 25 25 25 30 30 30
 0 6 10 16 16 16 21 25 31 31 31 36 36
 0 6 10 16 18 24 28 34 34 34 39 43 49
 0 6 10 16 19 24 28 34 37 37 39 43 49

Solution for the Knapsack...
Item 6 is selected
Item 5 is selected
Item 1 is selected
*/