/*
Implementation and Time analysis of sorting algorithms. 
Bubble sort, Selection sort, Insertion sort.
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define size 50
void bubble_sort(int arr[],int);
void insertion_sort(int arr[],int);
void selection_sort(int arr[],int);
int main()
{
    clock_t start, end;
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
                    scanf("%d", &arr [i]);
                break;
            case 2:
                start = clock();
                printf("Bubble Sort:");
                bubble_sort(arr,n);
                for(i=0;i<n;i++)  
                    printf("%d\t", arr[i]);
                end = clock();
                double duration1 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to bubble sort to execute in seconds : %f", duration1);
                break;
            case 3:
                start = clock();
                printf("Selection Sort:");
                selection_sort(arr,n);
                for(i=0;i<n;i++)   
                    printf("%d\t", arr[i]);
                end = clock();
                double duration2 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to bubble sort to execute in seconds : %f", duration2);
                break;
            case 4:
                start = clock();
                printf("Insertion Sort:");
                insertion_sort(arr,n);
                for(i=0;i<n;i++)
                    printf("%d\t", arr[i]);
                end = clock();
                double duration3 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to bubble sort to execute in seconds : %f", duration3);
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
void selection_sort(int arr[],int n)
{
    int i,j, temp;
    for ( i = 0; i < n-2 ; i++)
    {
        temp=i;
        for ( j = i+1; j < n-1; j++)
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
Enter the number of elements in the array : 10
Enter the elements: 5 25 6 65 70 3 89 0 56 38

Enter your choice:2
Bubble Sort:0   3       5       6       25      38      56      65      70      89
Time taken to bubble sort to execute in seconds : 0.022000
Enter your choice:1
Enter the number of elements in the array : 10
Enter the elements: 25 15 6 38 95 70 8 17 39 45

Enter your choice:3
Selection Sort:6        8       15      17      25      38      39      45      70      95
Time taken to bubble sort to execute in seconds : 0.005000
Enter your choice:1
Enter the number of elements in the array : 10
Enter the elements: 90 25 36 14 89 78 96 84 52 3

Enter your choice:4
Insertion Sort:3        14      25      36      52      78      84      89      90      96
Time taken to bubble sort to execute in seconds : 0.008000
Enter your choice:5
*/