/*
    Aluno: Vinícius Rangel da Silva Assumpcao
    Matrícula: 669007
*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int *vertexList;

typedef struct graph
{
    int price;
    int source;
    int dest;
}graph;

graph* compononents;

/*
    Este algoritmo utiliza kruskal para encontrar o menor caminho e possui uma complexidade de O(n^2)
*/
int main( )
{
    compononents = (graph*)calloc(79802,sizeof(graph));
    vertexList = (int*)calloc(402,sizeof(int));
    map<string,int> graphMap;
    string starting_station;
    string station_source;
    string station_dest;
    int vertex = 0;
    int edge = 0;
    int minimunCost = 0;
    int a = 0;
    int b = 0;
    int tmp = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int cost = 0;
    cin >> vertex >> edge;
    while (vertex != 0)
    {
        graphMap.clear();
        cost = 0;
        minimunCost = 0;
        tmp = vertex-1;
        for (int i = 1; i <= vertex; i++)
        {
            vertexList[i] = i;
        }
        for (int i = 1; i <= vertex; i++)
        {
            cin >> starting_station;
            graphMap[starting_station] = i;
        }
        for (int i = 0; i < edge; i++)
        {
            cin >> station_source >> station_dest >> cost;
            compononents[i].source = graphMap[station_source];
            compononents[i].dest = graphMap[station_dest];
            compononents[i].price = cost;
        }
        cin >> starting_station;
        for (int i = 0; i < edge && tmp > 0; i++)
        {
            tmp2 = compononents[i].source;
            tmp3 = compononents[i].dest;
            while (vertexList[tmp2] != tmp2)
            {
                tmp2 = vertexList[tmp2];
            }
            a = tmp2;
            while (vertexList[tmp3] != tmp3)
            {
                tmp3 = vertexList[tmp3];
            }
            b = tmp3;
            if (a != b)
            {
                tmp = tmp - 1;
                vertexList[b] = a;
                minimunCost = minimunCost + compononents[i].price;
            }
        }
        if (tmp == 0)
        {
            printf("%d\n", minimunCost);
        }
        else
        {
            cout << "Impossible\n";
        }
        cin >> vertex >> edge;
    }
    return (0);
}
