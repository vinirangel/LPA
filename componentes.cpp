#include <stdio.h>
#include <stdlib.h>
int sourceV, Vertex, Edge, time, visited[26], Graph[26][26];

/*
    Este programa utiliza o algoritmo Depth-First Search(DFS) para percorrer todos
    os componentes conexos do grafo informado pelo usuario e possui uma complexidade
    O(V^2), onde 'V' representa o numero de Vertices
*/

void DepthFirstSearch(int i)
{
    int j;
    char letter;
    visited[i] = 1;
    letter = (char)i + 97;
    printf("%c,",letter);
    for (j = 0; j < Vertex; j++)
    {
        if (Graph[i][j] == 1 && visited[j] == 0)
            DepthFirstSearch(j);
    }
}

int main()
{
    int i, j;
    int vertex1, vertex2;
    int cases = 0, currentCase = 1, components = 0;
    char tmp, tmp2;
    scanf("%d", &cases);

    for (int x = 0; x < cases; x++)
    {
        scanf(" %d %d", &Vertex, &Edge);
        components = 0;
        //Inicializa o grafo
        for (i = 0; i < Vertex; i++)
        {
            for (j = 0; j < Vertex; j++)
                Graph[i][j] = 0;
        }
        for (i = 0; i < Edge; i++)
        {
            scanf(" %c %c", &tmp, &tmp2);

            //Converte as letras em numeros e os insere no grafo 
            if(tmp >= 'a' && tmp <= 'z')
            {
                vertex1 = tmp - 'a' + 1;
            }
            if(tmp2 >= 'a' && tmp2 <= 'z')
            {
                vertex2 = tmp2 - 'a' + 1;
            }
            Graph[vertex1 - 1][vertex2 - 1] = 1;
            Graph[vertex2 - 1][vertex1 - 1] = 1;
        }

        printf("Case #%d:\n",currentCase++);
        for(int i = 0; i < Vertex; i++)
        {
            //Utiliza o DFS para percorrer cada componente nao visitado do grafo
            if(visited[i] == 0)
            {
                components++;
                DepthFirstSearch(i);
                printf("\n");
            }
        }
        printf("%d connected components\n",components);
        printf("\n");
        //Reseta o array de vertices visitados
        for (int i = 0; i < 26; i++)
        {
            visited[i] = 0;
        }
    }
    return 0;
}