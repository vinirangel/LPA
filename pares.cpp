#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
using namespace std;

/*
Este algoritmo possui complexidade O(n^2), iterando sobre cada par de valores uma vez
*/

int main(){
    int amount;
    while (amount != 0)
    {
        scanf("%d", &amount);
        int x_values[amount];
        int y_values[amount];
        float closest = FLT_MAX;
        
        //Ler os pares
        for (int i = 0; i < amount; i++)
        {
            scanf(" %d %d", &x_values[i], &y_values[i]);
        }

        //Calcula a distancia uma vez para cada par de valores
        for (int i = 0; i < amount-1; i++)
        {
            for (int j = i+1; j < amount; j++)
            {
                float deltaX = pow( (x_values[j]-x_values[i]), 2);
                float deltaY = pow( (y_values[j]-y_values[i]), 2);
                float result = sqrt((deltaX+deltaY));
                if(result < closest)
                    closest = result;
            }
        }
        if(closest < 10000)
            printf("%.4f\n", closest);
        else if(amount != 0)
            printf("INFINITY\n");
    }
    return 0;
}