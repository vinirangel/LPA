/*
    Aluno: Vinícius Rangel da Silva Assumpcao
    Matrícula: 669007
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int counter = 0;

/*
    Este programa utiliza o Merge sort para ordenar as bolhas, e possui complexidade de O(n log n), onde n e o numero de bolhas a serem ordenadas. 
    Durante a execucao, o programa calcula o numero de trocas realizadas durante o Merge sort para declarar o vencedor.
*/

void merge(int left, int middle, int right, int tmp[], int array[]) { // Merge it

    for (int i = left; i <= right; i++) { // Copia as partes para o array tmp
      tmp[i] = array[i];
    }

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) { // Copia os menores valores da esquerda ou direita para o array original

      if (tmp[i] < tmp[j]) {
        array[k] = tmp[i];
        i++;
      } else {
        array[k] = tmp[j];
        counter = counter+((j-k));
        j++;
      } 
      k++;
    }

    while (i <= middle) { // Copia os valores restantes para o array
      array[k] = tmp[i];
      k++;
      i++;
    }

}

void mergeSort(int left, int right, int arr_size, int arr[]) { 
    int tmp[arr_size];
    if (left < right) {
        //Busca o índice do valor do meio do array
        int middle = left + (right - left) / 2;

        // Ordena o lado direito do array
        mergeSort(left, middle, arr_size, arr);

        //Ordena o lado esquerdo do array
        mergeSort(middle + 1, right, arr_size, arr);

        // Combina os lados ordenados em apenas um array
        merge(left, middle, right, tmp, arr);
    }
  }


int main() {
    int tamanho;
    while(tamanho != 0)
    {
        counter = 0;
        scanf("%d", &tamanho);
        if(tamanho == 0)
            break;
        int bolhas[tamanho];

        for (int i = 0; i < tamanho; i++)
        {
            cin >> bolhas[i];
        }

        mergeSort(0, tamanho - 1, tamanho, bolhas);
        //Se o numero de ordenacoes for par, declara o Carlos como vencedor. Caso contrario, declara o Marcelo.
        if(counter % 2 == 0)
            printf("Carlos\n");
        else
            printf("Marcelo\n");
    }
    return 0;
}