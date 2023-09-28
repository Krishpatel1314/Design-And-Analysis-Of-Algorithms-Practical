/*
Implementation of matrix chain multiplication using dynamic programming.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int matrix_chain(int s[20][20],int p[],int i,int j);
void dispaly_matrix_order(int s[20][20],int i,int j);
int main()
{
    int n,i,cost;
    int p[100];
    int s[20][20];
    printf("Enter the no of matrix:");
    scanf("%d",&n);
    for ( i = 0; i < n+1; i++)
    {
        printf("Enter the dimension of matrix:");
        scanf("%d",&p[i]);
    }
    cost=matrix_chain(s,p,1,n);
    printf("The Optimal Cost: %d\n",cost);
    printf("The Optimal Order:\t");
    dispaly_matrix_order(s,1,n);
    return 0;
}
int matrix_chain(int s[20][20],int p[],int i,int j)
{
    if(i==j)
        return 0;
    int k,count;
    int min=1000000; //infinity
    for ( k = i; k < j; k++)
    {
        count=matrix_chain(s,p,i,k)+matrix_chain(s,p,k+1,j)+p[i-1]*p[k]*p[j];
        if (count<min)
        {
            min=count;
            s[i][j]=k;
        }
    }
    return min;  //return optimal cost
}
void dispaly_matrix_order(int s[20][20],int i,int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        dispaly_matrix_order(s,i,s[i][j]);
        dispaly_matrix_order(s,s[i][j]+1,j);
        printf(")");
    }
}

/*
OUTPUT:
Enter the no of matrix:6
Enter the dimension of matrix:30
Enter the dimension of matrix:35
Enter the dimension of matrix:15
Enter the dimension of matrix:5
Enter the dimension of matrix:10
Enter the dimension of matrix:20
Enter the dimension of matrix:25
The Optimal Cost: 15125
The Optimal Order:      ((A1(A2A3))((A4A5)A6))
*/