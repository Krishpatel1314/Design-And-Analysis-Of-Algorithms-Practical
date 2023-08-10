/*
Implementation of max-heap sort algorithm.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10
void makeheap(int arr[],int);
void heapsort(int arr[],int);
void display(int arr[],int);
void main()
{
    int i,n,arr[max];
    for ( i = 0; i < max; i++)
        arr[i]=0;
    printf("How many elements you want to enter:");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &arr [i]);
    printf("The elements are:");
    display(arr,n);
    makeheap(arr,n);
    printf("\nHeapified:");
    display(arr,n);
    heapsort(arr,n);
    printf("\nElements sorted by heap sort:");
    display(arr,n);
}
void makeheap(int arr[],int n)
{
    int i,val,j,father;
    for ( i = 1; i < n; i++)
    {
        val=arr[i];
        j=i;
        father=(j-1)/2;                //finding the parent of node j
        while (j>0 && arr[father]<val)     //creating a MAX heap
        {
            arr[j]=arr[father];        //preserving parent dominance
            j=father;
            father=(j-1)/2;
        }
        arr[j]=val;
    }
}
void heapsort(int arr[],int n)
{
    int i,j,k,temp;
    for ( i = n-1; i >0; i--)
    {
        temp=arr[i];
        arr[i]=arr[0];
        k=0;
        if (i==1)
            j=-1;
        else
            j=1;
        if (i>2 && arr[2]>arr[1])
            j=2;
        while (j>=0 && temp<arr[j])
        {
            arr[k]=arr[j];
            k=j;
            j=2*k+1;
            if (j+1<=i-1 && arr[j]<arr[j+1])
                j++;
            if (j>i-1)
                j=-1;
        }
        arr[k]=temp;
    }
}
void display(int arr[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {    printf("%d\t",arr[i]);
    }
}

/*
OUTPUT:
How many elements you want to enter:10
Enter the elements: 5 25 9 96 26 35 18 28 65 14
The elements are:5      25      9       96      26      35      18      28      65     14
Heapified:96    65      35      28      25      9       18      5       26      14

Elements sorted by heap sort:5   9       14      18      25      26      28      35     65   96
*/