#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
    Aluno: Vinícius Rangel da Silva Assumpcao
    Matrícula: 668007
    
    Este programa utiliza um algoritmo guloso para calcular a quantidade total de notas e moedas restantes,
    e possui complexidade de O(n^2)
*/

int main()
{
    double valor;
    int notas[] = {100, 50, 20, 10, 5, 2};
    float moedas[] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};
    int total_notas[] = {0, 0, 0, 0, 0, 0,};
    int total_moedas[] = {0, 0, 0, 0, 0, 0};
    cin >> valor;
    valor+=0.0001;
    float resto = valor;

    //Divide o valor do input o maximo possivel para cada nota
    for (int i = 0; i < 6; i++)
    {
        while ((int)valor - notas[i] >= 0)
        {
            valor = valor - notas[i];
            total_notas[i]++;
        }
        
    }
   
    //Divide o valor restante do input o maximo possivel para cada moeda
    for (int j = 0; j < 6; j++)
    {
        while (valor - moedas[j] > 0)
        {
            valor = valor - moedas[j];
            total_moedas[j]++;
        }
    }
    
    printf("NOTAS:");
    for (int i = 0; i < 6; i++)
    {
        printf("\n%d nota(s) de R$ %.2f", total_notas[i], (float)notas[i]);
    }
    printf("\nMOEDAS:");
    for (int i = 0; i < 6; i++)
    {
        printf("\n%d moeda(s) de R$ %.2f", total_moedas[i], (float)moedas[i]);
    }
    return 0;
}