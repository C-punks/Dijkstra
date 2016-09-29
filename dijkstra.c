#include "dijkstra.h"

void shortest_path(int s ,int t, int path[],int **matriz,int n)
{
	struct state state[MAX_NODES];

	int i,j,k,min;
	struct state *p;

	
	for ( p= &state[0]; p< &state[n];p++)
	{
		p->predecessor = -1;
		p->length = INT_MAX;
		p->label = tentative;
	}

	state[t].length =0;
	state[t].label = permanent;
	k=t;

	do
	{
		for (i=0;i < n;i++)
		{
			if (matriz[k][i] != 0 && state[i].label == tentative)
			{
				if (state[k].length + matriz[k][i] < state[i].length)
				{
					state[i].predecessor = k;
					state[i].length = state[k].length + matriz[k][i];
				}
			}
		}
		k = 0;
		min = INT_MAX;

		for(i=0;i<n;i++)
		{
				if(state[i].label == tentative && state[i].length < min)
				{
					min = state[i].length;
					k=i;
				}
		}
		state[k].label = permanent;
	}while(k != s);

	i =0;
	k =s;

	printf("\n\n");
	do
	{
		path[i++]=k;
		k=state[k].predecessor;
		printf("%d - ",path[i-1]);
	}while( k >= 0);
	printf("\n");
}

int verifica_parametros(int inicio , int final , int total_nodos)
{
	return (inicio >=0 && inicio <= total_nodos-1 && final >=0 && final <= total_nodos-1);
}