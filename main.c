#include "dijkstra.h"


int main(int argc, char *argv[])
{
	FILE *archivo;

	int **matriz;
	int num_nodos;
	int path[10];
	int i,j;
	int inicio,final;

	if(argc != 4 )
	{
		printf("use : %s <texto.txt> <nodo inicial> <nodo final>",argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		inicio = atoi(argv[2]);
		final  = atoi(argv[3]);

		archivo = fopen(argv[1],"r");

		fscanf(archivo,"%d\n",&num_nodos);

		if (!verifica_parametros(inicio,final,num_nodos))
		{
			printf("Los parametros Ingresados entan fuera de Rango [0 - %d]\n",num_nodos-1);
			fclose(archivo);
			exit(EXIT_FAILURE);
		}

		else 
		{
			printf("Nodos = %d \n",num_nodos );

			matriz = (int**)malloc(num_nodos*sizeof(int));
			for (i=0;i<num_nodos;i++)
			{
				matriz[i]=(int*)malloc(num_nodos*sizeof(int));
			}

			for (i=0;i < num_nodos ; i++)
			{
				for (j=0;j<num_nodos;j++)
				{
					fscanf(archivo,"%d",&matriz[i][j]);
				}
				fscanf(archivo,"\n");
			}

		
			shortest_path(inicio,final,path,matriz,num_nodos);


			fclose(archivo);

		}
		return 0;
	}
}