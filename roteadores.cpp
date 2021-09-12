#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//Utiliza o algoritmo de Kruskal para encontrar a MST
//Possui complexidade de O(E log V), onde E e a quantidade de arestas e V a quantidade de vertices

struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;

	struct Edge* edge;
};

struct Graph* createGraph(int nodes, int edges)
{
	struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
	graph->V = nodes;
	graph->E = edges;

	graph->edge = (struct Edge*)malloc(sizeof( struct Edge)*edges);

	return graph;
}

struct subset {
	int parent;
	int rank;
};

int find(struct subset subsets[], int i)
{
	// Encontra a raiz e a torna o pai de i
	if (subsets[i].parent != i)
		subsets[i].parent
			= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Coloca a arvore de rank meno na raiz da de maior rank
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// If ranks are same, then make one as root and
	// increment its rank by one
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

//Compara duas aresta de acordo com o seu peso
int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge
		result[V]; 
	int e = 0; 
	int i = 0; 
	//Ordena as aresta em ordem crescente
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
		myComp);

	struct subset* subsets
		= (struct subset*)malloc(V * sizeof(struct subset));

	// Cria uma quantidade V de subsets
	for (int v = 0; v <= V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1 && i < graph->E) {
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle
		// Se incluir esta aresta nao cria um ciclo, inclui-la no resultado
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}

	// constroi a MST
	int minimumCost = 0;
	for (i = 0; i < e; ++i)
	{
		minimumCost += result[i].weight;
	}
	printf("%d\n",minimumCost);
	return;
}

int main()
{
    int nodes = 0;
    int node1 = 0;
    int node2 = 0;
    int edgeNumber = 0;
    int edgeValue = 0;
    int counter = 0;
    int currentNode = 0;
    char *input = (char *)malloc(sizeof(int)*10001);
    cin >> nodes >> edgeNumber;
    fflush( stdin );
    struct Graph* graph = createGraph(nodes, edgeNumber);
    setbuf(stdin, NULL);
    while(counter < edgeNumber)
    {
	cin >> node1 >> node2 >> edgeValue;
        graph->edge[currentNode].src = node1;
	graph->edge[currentNode].dest = node2;
	graph->edge[currentNode].weight = edgeValue;
        currentNode++;
        counter++;
    }

	KruskalMST(graph);
}
