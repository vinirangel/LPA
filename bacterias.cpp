#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//Complexidade: O(n), onde n é a quantidade de dias de cultivacao das colonias

int main(){
 int dias;
 int total = 0;
 int counter = 4;
 char input[4001];
 int colonias[4] = {0,0,0,0};
 //Contador utilizado para "eliminar" a colonia mais velha
 int oldestColony = 0;
 while (counter < dias)
 {
    //Calcula o total inicial de bacterias
    if(oldestColony == 0)
    {
	cin >> dias;
        if(dias == 0)
	{
            	break;
	}
        cin >> colonias[0] >> colonias[1] >> colonias[2] >> colonias[3];
	total = total + colonias[0] + colonias[1] + colonias[2] + colonias[3];
        total*=2;
        total-= colonias[0];
    }
    else if(oldestColony < 4)
    {
        total*=2;
        total-= colonias[oldestColony];
    }
    //Reseta os contadores do loop e outros valores relevantes
    if(counter == dias-1){
        printf("\n%d",total);
        colonias[0] = 0, colonias[1] = 0, colonias[2] = 0, colonias[3] = 0;
        oldestColony = 0;
        counter = 4;
        total = 0;
        continue;
    }
    counter++;
    oldestColony++;
 }
}
