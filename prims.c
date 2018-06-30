#include<stdio.h>

int readcostmatrix(int cost[7][7], int n)
{
	int i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);

	printf("Enter the cost matrix..999 for infinity:\n");

	for(i=1;i<n;i++)
		for(j=1;j<n;j++)
			scanf("%d",&cost[i][j]);
		return n;

}

int mincostspanningtree(int cost [7][7], int n)
{
	int min, i, j, u=0,v=0, a=0, b=0, ne=1,mincost=0,visited[10]={0};
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i]!=0)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\nEdge %d :(%d %d) cost : %d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;

		}
		cost[a][b]=cost[b][a]=999;
	}
	return mincost;
}

main()
{
	int mincost=0, n=6;
	int cost[7][7]={{0,0,0,0,0,0,0},{0,999,3,999,999,6,5},{0,3,999,1,999,999,4},{0,999,1,999,6,999,4},{0,999,999,6,999,8,5},{0,6,999,8,999,2},{0,5,4,4,5,2,999}};

	n=readcostmatrix(cost,n);
	mincost=mincostspanningtree(cost,n);
	printf("\nMinimum cost = %d",mincost);
}