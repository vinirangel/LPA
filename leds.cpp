#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Utiliza uma tabela hash para pesquisar a quantidade de leds do numero passado como parametro
int calcularLeds(char numero)
{
    int chaves[] = {6,2,5,5,4,5,6,3,7,6};
    char *endtmp;
    int tmp = numero - '0';
    return chaves[tmp];
}

int main(){
    char input[100];
    int inputNumber = 0;
    int counter = 0;
    scanf("%d", &inputNumber);
    while (fgets(input,100, stdin) != NULL && counter < inputNumber)
    {
        int total = 0;
        scanf("%s", &input);
        char tmp[100];
        strcpy(tmp, input);
        int x = 0;
        //Calcula a quantidade de leds para cada digito do numero
        for(int i = 0; i < strlen(tmp); i++)
        {
            total += calcularLeds(tmp[i]);
        }
        printf("%d leds\n",total);
        counter++;
    }
}