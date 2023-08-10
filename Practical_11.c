/*
Implement prim’s algorithm for MST using Greedy Method.
*/
#include<stdio.h>
#include<conio.h>
#define SIZE 20
#define INFINITY 32767
void prim(int G[][SIZE],int);
void main()
{
    int G[SIZE][SIZE],nodes;
    int v1,v2,length,i,j,n;
    printf("Prim's Algorithm");
    printf("\nEnter no. of nodes in the graph:");
    scanf("%d",&nodes);
    printf("Enter no. of Edges in the graph:");
    scanf("%d",&n);
    for ( i = 0; i < nodes; i++)        //initialize the graph
        for ( j = 0; j < nodes; j++)
            G[i][j]=0;
    printf("Enter edges and weights:\n");   //entering weighted graph
    for ( i = 0; i < n; i++)
    {
        printf("Enter Edge by V1 and V2[Read the graph from starting nodes 0]:");
        scanf("%d %d",&v1,&v2);
        printf("Enter corresponding weight:");
        scanf("%d",&length);
        G[v1][v2]=G[v2][v1]=length;
    }
    prim(G,nodes);
}
void prim(int G[][SIZE],int nodes)
{
    int tree[SIZE],i,j,k;
    int min_dist,v1,v2,total=0;
    for ( i = 0; i < nodes; i++)        //initialize the selected vertices list
        tree[i]=0;
    printf("The Minimal Spanning tree is:");
    tree[0]=1;
    for ( k = 1; k <= nodes-1; k++)
    {
        min_dist=INFINITY;
        for ( i = 0; i <= nodes-1; i++)
        {
            for ( j = 0; j <= nodes-1; j++)
            {
                if (G[i][j]&&((tree[i]&&!tree[j])||(!tree[i]&&tree[j])))
                {
                    if (G[i][j]<min_dist)
                    {
                        min_dist=G[i][j];
                        v1=i;
                        v2=j;
                    }
                }
            }
        }
        printf("\nEdge(%d %d) and weight= %d",v1,v2,min_dist);
        tree[v1]=tree[v2]=1;
        total=total+min_dist;
    }
    printf("\nTotal Path Length is=%d",total);
}

/*
OUTPUT:
Prim's Algorithm
Enter no. of nodes in the graph:5
Enter no. of Edges in the graph:7
Enter edges and weights:
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:0 1
Enter corresponding weight:10
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:1 2
Enter corresponding weight:1
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:2 3
Enter corresponding weight:2
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:3 4
Enter corresponding weight:3
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:4 0
Enter corresponding weight:5
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:1 3
Enter corresponding weight:6
Enter Edge by V1 and V2[Read the graph from starting nodes 0]:4 2
Enter corresponding weight:7
The Minimal Spanning tree is:
Edge(0 4) and weight= 5
Edge(3 4) and weight= 3
Edge(2 3) and weight= 2
Edge(1 2) and weight= 1
Total Path Length is=11
*/