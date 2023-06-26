/*
Implementation and Time analysis of sorting algorithms. 
Bubble sort, Selection sort, Insertion sort.
*/
#include <stdio.h>
#include <conio.h>
#define size 50
void bubble_sort(int arr[],int);
void insertion_sort(int arr[],int);
void selection_sort(int arr[],int);
int main()
{
    int i,j,arr[size],n,temp,ch;
    printf("\n1)Create an array");
    printf("\n2)Bubble Sorting");
    printf("\n3)Selection Sorting");
    printf("\n4)Insertion Sorting");
    printf("\n5)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number of elements in the array : ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for(i=0;i<n;i++)
                {
                    scanf("%d", &arr [i]);
                }
                break;
            case 2:
                printf("Bubble Sort:");
                bubble_sort(arr,n);
                for(i=0;i<n;i++)
                {   
                    printf("%d\t", arr[i]);
                }
                break;
            case 3:
                printf("Selection Sort:");
                selection_sort(arr,n);
                for(i=0;i<n;i++)
                {   
                    printf("%d\t", arr[i]);
                }
                break;
            case 4:
                printf("Insertion Sort:");
                insertion_sort(arr,n);
                for(i=0;i<n;i++)
                {   
                    printf("%d\t", arr[i]);
                }
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid Input!!"); 
        }
    }
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for(i=0; i<n; i++)
    {
       for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void selection_sort(int arr[],int n)
{
    int i,j, temp;
    for ( i = 0; i < n-1 ; i++)
    {
        temp=i;
        for ( j = i+1; j < n; j++)
        {
            if (arr[j]<arr[temp])
            {
                temp=j;
            }
        }
        if (temp!=i)
        {
            int a;
            a=arr[i];
            arr[i]=arr[temp];
            arr[temp]=a;
        }
    }
}
void insertion_sort(int arr[],int n)
{
    int i,j,temp;
    for ( i = 1; i <=n-1; i++)
    {
        temp=arr[i];
        j=i-1;
        while ((j>=0)&&(arr[j]>temp))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
/*
OUTPUT:
1)Create an array
2)Bubble Sorting
3)Selection Sorting
4)Insertion Sorting
5)Exit
Enter your choice:1
Enter the number of elements in the array : 5
Enter the elements: 5 3 6 2 7

Enter your choice:2
Bubble Sort:2   3       5       6       7
Enter your choice:3
Selection Sort:2        3       5       6       7
Enter your choice:4
Insertion Sort:2        3       5       6       7
Enter your choice:5
*/