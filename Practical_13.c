/*
Implementation of Graph and Searching using DFS 
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
#define TRUE 1
#define FALSE 0
int g[MAX][MAX];
int v[MAX];
int n;
// void main()
// {
//     int v1,v2;
//     char ans;
//     void create();
//     void Dfs(int);
//     // clrscr();
//     create();
//     // clrscr();
//     printf("The Adjacent Matrix for the graph is\n");
//     for ( v1 = 0; v1 < n; v1++)
//     {
//         for ( v2 = 0; v2 < n; v2++)
//             printf("%d",g[v1][v2]);
//         printf("\n");
//     }
//     getch();
//     do
//     {
//         for ( v1 = 0; v1 < n; v1++)
//             v[v1]=FALSE;
//         // clscr();
//         printf("Enter the vertex from which you want to traverse:");
//         scanf("%d",&v1);
//         if (v1>=MAX)
//         printf("Invalid Vertex\n");
//         else
//         {
//             printf("The Depth First Search of the Graph is\n");
//             Dfs(v1);
//         }
//         printf("\nDo you want to traverse by any other node?");
//         ans=getch();
//     } while (ans=='y');
// }
// void create()
// {
//     int ch,v1,v2,flag;
//     char ans='y';
//     printf("This is a Program to create a graph\n");
//     printf("The display is in Depth First Manner\n");
//     getch();
//     // clrscr();
//     // flushall();
//     for (v1 = 0; v1 < n; v1++)
//         for ( v2 = 0; v2 < n; v2++)
//             g[v1][v2]=FALSE;
//     printf("\nEnter no. of nodes:");
//     scanf("%d",&n);
//     printf("\nEnter the vertices no. starting from 0");
//     do
//     {
//         printf("\nEnter the vertices v1 & v2:");
//         scanf("%d",&v1,&v2);
//         if (v1>=n||v2>=n)
//         printf("Invalid Vertex Value\n");
//         else
//         {
//             g[v1][v2]=TRUE;
//             g[v2][v1]=TRUE;
//         }
//         printf("\n\nAdd more edges??(y/n)");
//         ans=getch();
//     } while (ans=='y');
// }
// void Dfs(int v1)
// {
//     int v2;
//     printf("%d\n",v1);
//     v[v1]=TRUE;
//     for ( v2 = 0; v2 < MAX; v2++)
//         if (g[v1][v2]==TRUE && v[v2]==FALSE)
//             Dfs(v2);
// }

#include <stdio.h>
int a[20][20], reach[20], n;
void dfs(int v)
{
     int i;
     reach[v] = 1;
     for (i = 1; i <= n; i++)
     {
          if (a[v][i] && !reach[i])
          {
               printf("\n %d->%d", v, i);
               dfs(i);
          }
     }
}
void main()
{
     int i, j, count = 0;
     printf("\n Enter number of vertices");
     scanf("%d", &n);
     for (i = 1; i <= n; i++)
     {
          reach[i] = 0;
          for (j = 1; j <= n; j++)
               a[i][j] = 0;
     }
     printf("\nEnter adjacency matrix:\n");
     for (i = 1; i <= n; i++)
          for (j = 1; j <= n; j++)
               scanf("%d", &a[i][j]);
     dfs(1);
     printf("\n");
     for (i = 1; i <= n; i++)
     {
          if (reach[i])
               count++;
     }
     if (count == n)
          printf("\n Graph is connected");
     else
          printf("\n Graph is not connected");
}