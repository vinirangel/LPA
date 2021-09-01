// C program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, undirected
// and weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	// Since the graph is undirected, the edge
	// from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int nodes, int edges)
{
	struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
	graph->V = nodes;
	graph->E = edges;

	graph->edge = (struct Edge*)malloc(sizeof( struct Edge)*edges);

	return graph;
}

// A structure to represent a subset for union-find
struct subset {
	int parent;
	int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
	// find root and make root as parent of i
	// (path compression)
	if (subsets[i].parent != i)
		subsets[i].parent
			= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Attach smaller rank tree under root of high
	// rank tree (Union by Rank)
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

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's
// algorithm
void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge
		result[V]; // Tnis will store the resultant MST
	int e = 0; // An index variable, used for result[]
	int i = 0; // An index variable, used for sorted edges

	// Step 1: Sort all the edges in non-decreasing
	// order of their weight. If we are not allowed to
	// change the given graph, we can create a copy of
	// array of edges
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
		myComp);

	// Allocate memory for creating V ssubsets
	struct subset* subsets
		= (struct subset*)malloc(V * sizeof(struct subset));

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1 && i < graph->E) {
		// Step 2: Pick the smallest edge. And increment
		// the index for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle,
		// include it in result and increment the index
		// of result for next edge
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}

	// print the contents of result[] to display the
	// built MST
	printf(
		"Following are the edges in the constructed MST\n");
	int minimumCost = 0;
	for (i = 0; i < e; ++i)
	{
		printf("%d -- %d == %d\n", result[i].src,
			result[i].dest, result[i].weight);
		minimumCost += result[i].weight;
	}
	printf("Minimum Cost Spanning tree : %d",minimumCost);
	return;
}

// Driver program to test above functions
int main()
{
    int nodes = 0;
    int node1 = 0;
    int node2 = 0;
    int edgeNumber = 0;
    int edgeValue = 0;
    int counter = 0;
    int currentNode = 1;
    char input[10001];
    scanf("%d%d", &nodes, &edgeNumber);
    nodes++;
    struct Graph* graph = createGraph(nodes, edgeNumber);
    // printf("GRAPH[5] = %d",graph->edge[4])
    //printf("NODES = %d \tEDGES = %d\n",nodes,edgeNumber);
    fflush( stdin );
    while(fgets(input, 10121, stdin) != NULL)// && counter < edgeNumber)
    {
        //printf("CURRENT COUNTER = %d \tCURRENTNODE = %d \tEDGE NUMBER = %d\n", counter,currentNode,edgeNumber);
        sscanf(input, "%d %d %d", &node1, &node2, &edgeValue);
        //printf("NODE 1 = %d \t NODE 2 = %d \t EDGE = %d\n",node1,node2,edgeValue);
        graph->edge[currentNode].src = node1;
	    graph->edge[currentNode].dest = node2;
	    graph->edge[currentNode].weight = edgeValue;
        currentNode++;
        counter++;
        if (counter == edgeNumber)
        {
            break;
        }
        
         printf("AFTER COUNTER = %d \tAFTER NODE = %d \tAFTER NUMBER = %d\n", counter,currentNode,edgeNumber);
    }

    for (int i = 1; i < nodes+1; i++)
    {
        printf("\nNODE[%d] SOURCE= %d \tDEST = %d \t WEIGHT = %d",i,graph->edge[i].src,graph->edge[i].dest,graph->edge[i].weight);
    }
    
	KruskalMST(graph);
}
