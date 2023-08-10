/*
Implementation and Time analysis of linear and binary search algorithm.
*/
#include <stdio.h>
#include <conio.h>
#include<time.h>
#define size 50
int i,j,arr[size],n,temp,ch,key,flag=0,low=0,beg,mid,end;
void Seq_Search(int arr[],int,int);
void bubble_sort(int arr[],int);
void binsearch(int arr[]);
int main()
{
    clock_t start, end;
    printf("\n1)Create an array");
    printf("\n2)Linear Search");
    printf("\n3)Binary Search");
    printf("\n4)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the number of elements in the array : ");
                scanf("%d", &n);
                printf("\nEnter the elements: ");
                for(i=0;i<n;i++)
                    scanf("%d", &arr [i]);
                break;
            case 2:
                start = clock();
                printf("Linear Search");
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                Seq_Search(arr,n,key);
                end = clock();
                double duration1 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to Linear Search to execute in seconds : %f", duration1);
                break;
            case 3:
                start = clock();
                printf("Binary Search");
                binsearch(arr);
                end = clock();
                double duration3 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to binary search to execute in seconds : %f", duration3);
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid Input!!"); 
        }
    }
}
void Seq_Search(int arr[],int n,int key)
{
    int i,flag=0,mark;
    for ( i = 0; i < n; i++)
    {
        //searching element from begninning of array
        if (arr[i]==key)
        {
            flag=1;  //setting the flag if element found
            mark=i;  //marking the loaction of key element
            break;
        }
    }
    if (flag==1)
        printf("The element is present at location %d",mark+1);
    else
        printf("Element not found!");   
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    
    for(i=0; i<=n-2; i++)
    {
       for(j=0; j<=n-2-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void binsearch(int arr[])
{
    printf("\nEnter the element to be searched:");
    scanf("%d",&key);
    bubble_sort(arr,n);
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
    beg = 0, end = n-1;
    while(beg<=end)
    {
        mid = (beg + end)/2;
        if (arr[mid] == key)
        {
            printf("\n%d is present in the array at position %d", key, mid+1);
            flag ==1;
            break;
        }
        else if (arr[mid]>key)
            end = mid-1;
        else
            beg = mid+1;
    }
    if (beg > end && flag == 0)
        printf("\n%d does not exist in the array", key);
}
/*
OUTPUT:
1)Create an array
2)Linear Search
3)Binary Search(Non-Recursive)
4)Exit
Enter your choice:1
Enter the number of elements in the array : 10
Enter the elements: 5 25 9 96 26 35 18 28 65 14
Enter your choice:2
Linear Search
Enter the element to be searched:65
The element is present at location 9
Time taken to Linear Search to execute in seconds : 1.496000
Enter your choice:3
Binary Search
Enter the element to be searched:96
5       9       14      18      25      26      28      35      65      96
96 is present in the array at position 10
Time taken to Merge sort to execute in seconds : 0.925000
Enter your choice:4
*/