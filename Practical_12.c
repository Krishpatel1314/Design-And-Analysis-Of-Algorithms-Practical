/*
Implement kruskal’s algorithm for MST using Greedy Method. 
*/
#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
typedef struct Graph
{
    int v1;
    int v2;
    int cost;
}GR;
GR G[20];
int tot_edges,tot_nodes;
void create();
void spanning_tree();
int minimum(int);

void main()
{
    printf("Graph creation for adjacent matrix\n");
    create();
    spanning_tree();
}
void create()
{
    int k;
    printf("Enter total no. of nodes:");
    scanf("%d",&tot_nodes);
    printf("Enter total no. of edges:");
    scanf("%d",&tot_edges);
    for ( k = 0; k < tot_edges; k++)
    {
        printf("Enter edges in(V1 V2)form:");
        scanf("%d %d",&G[k].v1,&G[k].v2);
        printf("Enter Corresponding Cost:");
        scanf("%d",&G[k].cost);
    }
}
void spanning_tree()
{
    int count,k,v1,v2,i,j,tree[10][10],pos,parent[10],sum;
    int find(int v2,int parent[]);
    void Union(int i, int j, int parent[]);
    count=0;
    k=0;
    sum=0;
    for ( i = 0; i < tot_nodes; i++)
        parent[i]=i;
    while (count!=tot_nodes-1)
    {
        pos=minimum(tot_edges);
        if(pos==-1)
            break;
        v1=G[pos].v1;
        v2=G[pos].v2;
        i=find(v1,parent);
        j=find(v2,parent);
        if (i!=j)
        {
            tree[k][0]=v1;
            tree[k][1]=v2;
            k++;
            count++;
            sum+=G[pos].cost;
            Union(i,j,parent);
        }
        G[pos].cost=INFINITY;
    }
    if (count==tot_nodes-1)
    {
        printf("\nSpanning Tree is...");
        printf("\n----------------------\n");
        for ( i = 0; i < tot_nodes-1; i++)
        {
            printf("[%d",tree[i][0]);
            printf("--");
            printf("%d",tree[i][1]);
            printf("]");
        }
        printf("\n----------------------");
        printf("\nCost of Spanning Tree is= %d",sum);
    }
    else
        printf("There is no spanning tree");
}
int minimum(int n)
{
    int i,small,pos;
    small=INFINITY;
    pos=-1;
    for ( i = 0; i < n; i++)
    {
        if (G[i].cost<small)
        {
            small=G[i].cost;
            pos=i;
        }
    }
    return pos;
}
int find(int v2, int parent[])
{
    while (parent[v2]!=v2)
    {
        v2=parent[v2];
    }
    return v2;
}
void Union(int i,int j,int parent[])
{
    if(i<j)
        parent[j]=i;
    else
        parent[i]=j;
}

/*
OUTPUT:
Graph creation for adjacent matrix
Enter total no. of nodes:4
Enter total no. of edges:5
Enter edges in(V1 V2)form:1 2
Enter Corresponding Cost:2
Enter edges in(V1 V2)form:1 4
Enter Corresponding Cost:1
Enter edges in(V1 V2)form:1 3
Enter Corresponding Cost:3
Enter edges in(V1 V2)form:2 3
Enter Corresponding Cost:3
Enter edges in(V1 V2)form:4 3
Enter Corresponding Cost:5

Spanning Tree is...
--------------------
[1--4][1--2][1--3]
----------------------
Cost of Spanning Tree is= 6
*/