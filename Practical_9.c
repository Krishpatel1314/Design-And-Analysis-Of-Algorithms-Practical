/*
Implement LCS problem using dynamic programming.
*/
#include<stdio.h>
#include<string.h>
int i,j,m,n,c[10][10];
char x[10],y[10],b[10][10];
int lcs(char x[],char y[]);
void print(char b[10][10],char [],int,int);
int main()
{
    printf("Enter 1st Sequence:");
    scanf("%s",x);
    printf("Enter 2st Sequence:");
    scanf("%s",y);
    printf("The Longest Common Subsequence is:",lcs(x,y));
    print(b,x,m,n);
    return 0;
}
int lcs(char x[],char y[]){
    m=strlen(x);
    n=strlen(y);
    for ( i = 0; i <= m; i++)
        c[i][0]=0;
    for ( j = 0; j <= n; j++)
        c[0][j]=0;
    for ( i = 1; i <= m; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='D';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }
        }
    }
    printf("Table is...\n");
    for ( i = 0; i <= m; i++)
    {
        for ( j = 0; j <= n; j++)
        {
            printf("%3d",c[i][j]);
        }
        printf("\n");
    }
    
    return c[m][n] && b[m][n];
}
void print(char b[10][10],char x[],int i, int j)
{
    if (i==0 || j==0)
        return;
    if (b[i][j]=='D')
    {
        print(b,x,i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='U')
        print(b,x,i-1,j);
    else
        print(b,x,i,j-1);
}

/*
OUTPUT:
Enter 1st Sequence:abbacdcba
Enter 2st Sequence:bcdbbcaac
Table is...
  0  0  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  1  1  1
  0  1  1  1  1  1  1  1  1  1
  0  1  1  1  2  2  2  2  2  2
  0  1  1  1  2  2  2  3  3  3
  0  1  2  2  2  2  3  3  3  4
  0  1  2  3  3  3  3  3  3  4
  0  1  2  3  3  3  4  4  4  4
  0  1  2  3  4  4  4  4  4  4
  0  1  2  3  4  4  4  5  5  5
The Longest Common Subsequence is:bcdca
*/