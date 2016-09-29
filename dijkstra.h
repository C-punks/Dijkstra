#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define MAX_NODES 1024

struct state
{
	int predecessor;
	int length;
	enum {permanent,tentative}label;
};

void shortest_path(int i ,int t, int path[],int **mtriz,int n);
int verifica_parametros(int inicio , int final , int total_nodos);
