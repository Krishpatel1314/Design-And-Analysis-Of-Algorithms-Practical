/*
Implementation of a knapsack problem using greedy algorithm.
*/
#include<stdio.h>
#include<conio.h>
void knapsack(int n,float m,float w[],float p[]);
void main()
{
    int i,j,n;
    float p[15],w[15],c[15],temp,m;
    printf("Enter no. of objects:");
    scanf("%d",&n);
    printf("Enter weights:");
    for ( i = 0; i < n; i++)
        scanf("%f",&w[i]);
    printf("Enter profits:");
    for ( i = 0; i < n; i++)
        scanf("%f",&p[i]);
    printf("Enter knapsack size:");
    scanf("%f",&m);
    for ( i = 0; i < n; i++)
        c[i]=p[i]/w[i];
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1 ; j++)
        {
            if (c[j]<c[j+1])
            {
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;

                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }  
        }
    }
    printf("The items are arranged as...\n");
    printf("Items\tWeights\t\tProfits");
    for ( i = 0; i < n; i++)
        printf("\n[%d]\t%.0f\t\t%.0f",i,w[i],p[i]);
    knapsack(n,m,w,p);
}
void knapsack(int n,float m,float w[],float p[])
{
    float x[15],U,profit=0.0,weight=0.0;
    int i;
    U=m;
    for ( i = 0; i < n; i++)
        x[i]=0.0;
    for ( i = 0; i < n; i++)
    {
        if (w[i]>U)
            break;
        x[i]=1.0;
        U=U-w[i];
    }
    if (i<n)
        x[i]=U/w[i];  //take fractional part of the item to fulfill the size
    printf("\nThe solution vector is:");
    for ( i = 0; i < n; i++)
        printf("\n%d\t\%.2f",i,x[i]);
    for ( i = 0; i < n; i++)
    {
        w[i]=w[i]*x[i];
        p[i]=p[i]*x[i];
    }
    for ( i = 0; i < n; i++)
    {
        profit=profit+p[i];   //computing total profit & wt
        weight=weight+w[i];
    }
    printf("\nMaximum Profit is:%.2f",profit);
    printf("\nMaximum weight is:%.2f",weight);
}

/*
OUTPUT:
Enter no. of objects:7
Enter weights:1 3 5 4 1 3 2
Enter profits:5 10 15 7 8 9 4
Enter knapsack size:15
The items are arranged as...   
Items   Weights         Profits
[0]     1               8      
[1]     1               5
[3]     5               15
[4]     3               9
[5]     2               4
[6]     4               7
The solution vector is:
0       1.00
1       1.00
2       1.00
4       1.00
5       1.00
6       0.00
Maximum Profit is:51.00
Maximum weight is:15.00
*/