/*
Implementation and Time analysis of linear and binary search algorithm.
*/
#include <stdio.h>
#include <conio.h>
#define size 50
int i,j,arr[size],n,temp,ch,key,flag,low=0;
void Seq_Search(int arr[],int,int);
int binsearchrec(int arr[],int,int,int);
int binsearchnonrec(int arr[],int);
int main()
{
    printf("\n1)Create an array");
    printf("\n2)Linear Search");
    printf("\n3)Binary Search(Recursive)");
    printf("\n4)Binary Search(Non-Recursive)");
    printf("\n5)Exit");
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
                {
                    scanf("%d", &arr [i]);
                }
                break;
            case 2:
                printf("Linear Search");
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                Seq_Search(arr,n,key);
                break;
            case 3:
                printf("Binary Search by Recursive");
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                int low=0,high=n-1;
                flag=binsearchrec(arr,key,low,high);
                if (flag==0)
                    printf("Element not found");
                else
                    printf("Element found at %d",flag+1);
                break;
            case 4:
                printf("Binary Search by Non-Recursive");
                printf("\nEnter the element to be searched:");
                scanf("%d",&key);
                flag=binsearchnonrec(arr,key);
                if (flag==-1)
                    printf("Element not found");
                else
                    printf("Element found at %d",flag+1);
                break;
            case 5:
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
int binsearchrec(int arr[],int key,int low,int high)
{
    int m;
    m=(low+high)/2;  //mid of the array is obtained
    if (key==arr[m])
        return m;
    else if (key<arr[m])
    {    
        binsearchrec(arr,key,low,m-1);  //search the left sub list
        flag++;
    }
    else
    {   
        binsearchrec(arr,key,m+1,high);  //search the right sub list
        flag++;
    }    
}
int binsearchnonrec(int arr[],int key)
{
    int m,low=0,high=n-1;
    while (low<=high)
    {
        m=(low+high)/2;  //mid of the array is obtained
        if (key==arr[m])
            return m;
        else if (key<arr[m])
            high=m-1;       //search the left sub list
        else
            low=m+1;        //search the right sub list
    }
    return -1;   //if element not present in list
}