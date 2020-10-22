#include <stdio.h>
#include<stdlib.h>
#define LIM 100

struct grafo{
int V;  //Num de vertices
int aresta; // Num de arestas
int **adj; // ponteiro de matriz de adjacencia do grafo
};
typedef struct grafo *Grafo ;
Grafo Grafo_inicia(int V,int C);
int Matriz (int l, int c, int val);
void insere_arco_grafo(Grafo G, int v, int w, int val);
void remove_arco_grafo(Grafo G,int v, int w);
void mostra_grafo(Grafo G);
void condicao_Dirac(Grafo G);
void condicao_Ore(Grafo G);
void readme();
Grafo add_grafo();
void menu();

int main(){

    menu();

  return 0;
}
Grafo Grafo_inicia(int V,int C)
{
   Grafo G = malloc(sizeof *G);
    G->V = V;
    G->aresta = 0;
    G->adj = Matriz(V,C,0);

    return G;
}
int Matriz (int l, int c, int val)
{
    int **m = malloc(l * sizeof(int*)); //Cria uma matriz com linha l

    for(int i = 0; i<l; i++)
        m[i] = malloc(c * sizeof(int)); // Cria matriz com coluna c

    for(int i = 0; i<l; i++)
        for(int j =0; j<c; j++ )
        m[i][j] = val;  // add o valor a matriz, se os vertices forem adjacentes

    return m;
}

void insere_arco_grafo(Grafo G, int v, int w, int val)
{
    if(G->adj[v][w] == 0 )
        {
        G->adj[v][w] = val;
        G->aresta ++;
        }
}

void remove_arco_grafo(Grafo G,int v, int w)
{
    if(G->adj[v][w] == 0)
    {
        G->aresta -- ;
    }
    else return;

}
void mostra_grafo(Grafo G)
{
    for(int i = 0; i < G->V; i++)
    {
        printf("%d:",i);

        for(int j = 0 ; j < G->V; j++)
            printf("%d ",G->adj[i][j]);

        printf("\n");
    }
     printf("\n");
}

void condicao_Dirac(Grafo G)
{
    int i, j, resultado,aux;

    if(G->V < 3)
        {
            printf("\n O grafo selecionado nao eh Hamiltoniano de acordo com a Condicao de Dirac:\n");
            printf("\tPois o numero de vertices eh menor do que 3\n");
            return;
        }
        else{
            for(i = 0;i <G->V; i++)
            {
                resultado = 0;
                aux = 0;
                for(j = 0;j < G->V; j++)
                {
                 aux = G->adj[i][j];
                resultado = resultado + aux;
                }
                printf("O grau do vertice: %d eh : %d\n",i,resultado);
                float p = G->V / 2;
                    if(resultado < p)
                    {
                        printf("\n O grafo selecionado nao eh Hamiltoniano de acordo com a Condicao de Dirac:\n");
                        printf("Pois o grau do  vertices: %d eh menor do que %.2f \n",i,p);
                        return;
                    }
            }
        }

     printf("\n O grafo selecionado eh Hamiltoniano de acordo com a Condicao de Dirac\n");
     return ;

}

void condicao_Ore(Grafo G)
{
 int i, j,aux1,aux2;

        if(G->V < 3)
            {
            printf("O grafo selecionado nao eh Hamiltoniano de acordo com a Condicao de Ore\n");
            printf("\tPois o numero de vertices eh menor do que 3\n");
            return;
            }
        else{
            for(i=0;i<G->V;i++)
            {
                for(j=0;j<G->V;j++)
                {
                 if(G->adj[i][j] == 0)
                 {
                   aux1= 0;
                   for(int k = 0; k < G->V; k++)
                   {
                       aux1 = aux1 + G->adj[i][k];
                   }
                   aux2= 0;
                   for(int k = 0; k < G->V; k++)
                   {
                       aux2 = aux2 + G->adj[j][k];
                   }
                   aux1 = aux1 + aux2;
                   if(aux1 < G->V)
                   {
                     printf("O grafo selecionado nao eh Hamiltoniano de acordo com a Condicao de Ore\n");
                     printf("Pois os vertices  nao adjacentes :%d,%d , a soma de seus graus nao sao maiores que o numero de vertices :%d \n",i,j,G->V);
                    return;
                   }

                 }
                }
            }
        }
     printf("O grafo selecionado eh Hamiltoniano de acordo com a Condicao de Ore\n");
    return;
}

void readme()
{
   FILE *fp;
   char read[100];

    fp = fopen("readme.txt","r");

    if(fp!= NULL)
    {
        while(fgets(read,100,fp)!= NULL)
        {
            printf("%s",read);
        }
      fclose(fp);
    }
return;
}

void menu()
{

    int escolha = 0, continua = 0;
    Grafo grafo;


    while(continua != 1)
    {
    printf("Bem vindo\n");
    printf("1-inserir grafo\n");
    printf("2- visualizar grafo\n");
    printf("3-Condicao de Dirac\n");
    printf("4-Condicao de Ore\n");
    printf("5-Ler readme\n");
    printf("6-Sair\n");
    scanf("%d",&escolha);
    getchar();


        switch(escolha)
        {
        case 1:
            grafo = add_grafo ();
            escolha = 0;
            printf("\n\n\n");

        break;
        case 2:
            mostra_grafo(grafo);
            escolha = 0;
            printf("\n\n\n");

        break;
        case 3:
            condicao_Dirac(grafo);
            escolha = 0;
            printf("\n\n\n");

        break;
        case 4:
           condicao_Ore(grafo);
           continua = 0;
           printf("\n\n\n");

        break;
        case 5:
            readme();
            escolha = 0;
            printf("\n\n\n");

        break;
        case 6:
            printf("Saindo...\n");
           continua = 1;
           printf("\n\n\n");

        break;

        default:
            printf("opcao inexistente\n");
        break;
        }

    }

}

Grafo add_grafo()
{
  Grafo G;
  int am,an,i,j,k;
  FILE *fp;
  char nome[50];
  printf("Informe o nome do grafo a ser analizado:\n");
   scanf("%s",&nome);

  fp = fopen(nome,"r");

  if(fp == NULL) return G;

  fscanf(fp,"%d %d",&am,&an);
  printf("A matriz e: %d por %d\n",am,an);

  G = Grafo_inicia(am,an);

  for(i = 0; i < am; i++)
    for(j = 0; j < an; j++)
      {
        fscanf(fp,"%d",&k);
        insere_arco_grafo(G,i,j,k);
      }
  fclose(fp);

  for(i = 0; i < am; i++){
    for(j = 0; j < an; j++)
        remove_arco_grafo(G,i,j);
    printf("\n");
  }
printf("\n\n\n");
  return G;
}


