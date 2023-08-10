/*
Implementation and Time analysis of sorting algorithms. 
Merge sort and Quick sort.
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define size 50
void merge(int arr[],int,int,int);
void merge_sort(int arr[],int, int);
int partition(int arr[],int , int);
void quick_sort(int arr[], int, int);
int main()
{
    clock_t start, end;
    int i,j,arr[size],n,temp,ch;
    printf("\n1)Create an array");
    printf("\n2)Merge Sorting");
    printf("\n3)Quick Sorting");
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
                printf("Merge Sort:");
                merge_sort(arr,0,n-1);
                for(i=0;i<n;i++) 
                    printf("%d\t", arr[i]);
                end = clock();
                double duration1 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to Merge sort to execute in seconds : %f", duration1);
                break;
            case 3:
                start = clock();
                printf("Quick Sort:");
                quick_sort(arr,0,n-1);
                for(i=0;i<n;i++)
                    printf("%d\t", arr[i]);
                end = clock();
                double duration2 = ((double)end - start)/CLOCKS_PER_SEC;
                printf("\nTime taken to Quick sort to execute in seconds : %f", duration2);
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid Input!!"); 
        }
    }
}
void merge(int arr[], int beg, int mid, int end)
{
    int i=beg, j=mid+1, index=beg, temp[size], k;
    while((i<=mid) && (j<=end))
    {
        if(arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    arr[k] = temp[k];
}
void merge_sort(int arr[],int beg,int end)
{
    int mid;
    if (beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }   
}
int partition(int arr[],int beg,int end)
{
    int left, right, temp, loc, flag;
    loc = left = beg;
    right = end;
    flag = 0;
    while(flag != 1)
    {
        while((arr[loc] <= arr[right]) && (loc!=right))
        right--;
        if(loc==right)
        flag =1;
        else if(arr[loc]>arr[right])
        {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        if(flag!=1)
        {
            while((arr[loc] >= arr[left]) && (loc!=left))
            left++;
            if(loc==left)
            flag =1;
            else if(arr[loc] <arr[left])
            {
                temp = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}
void quick_sort(int arr[],int beg,int end)
{
    int loc;
    if (beg<end)
    {
        loc = partition(arr,beg,end);
        quick_sort(arr,beg,loc-1);
        quick_sort(arr,loc+1,end);
    }  
}
/*
OUTPUT:
1)Create an array 
2)Merge Sorting   
3)Quick Sorting   
4)Exit
Enter your choice:1

Enter the number of elements in the array : 10

Enter the elements: 5 25 9 96 26 35 18 28 65 14

Enter your choice:2
Merge Sort:5    9       14      18      25      26      28      35      65      96
Time taken to Merge sort to execute in seconds : 0.005000
Enter your choice:1

Enter the number of elements in the array : 12

Enter the elements: 9 26 35 45 96 85 74 25 14 63 25 5

Enter your choice:3
Quick Sort:5    9       14      25      25      26      35      45      63      74      85      96
Time taken to Quick sort to execute in seconds : 0.006000
Enter your choice:4
*/