#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcularLeds(char numero)
{
    int chaves[] = {6,2,5,5,4,5,6,3,7,6};
    int leds = 0;
    char *endtmp;
    int tmp = numero - '0';
    // printf("\nNUMERO = %d",chaves[tmp]);
    return chaves[tmp];
    // return chaves[strtol(numero, &endtmp, 10)];
}

int main(){
    char input[100];
    int inputNumber = 0;
    int counter = 0;
    int leds = 0;
    scanf("%d", &inputNumber);
    //scanf("%s", &input);
            printf("\nSTARTING INPUT = %s",input);
    while (fgets(input,100, stdin) != NULL && counter < inputNumber)
    {
        //char *tmp;
        //sscanf(input, "%s", &input);
        scanf("%s", &input);
        printf("\nCOUNTER = %d",counter);
        printf("\nINPUT BEFORE = %s",input);
        //strcpy(tmp, input);
            char *tmp = strcpy(tmp, input);
            int x = 0;
            printf("\nTMP = %s",tmp);
            printf("\nSTRLEN = %d",strlen(tmp));
            // while(strcmp(tmp[x], "/0") != 0)
            for(int i = 0; i < strlen(tmp); i++)
            {
                leds = calcularLeds(tmp[i]);
                printf("\nSTRING = %c LEN = %d",tmp[i], strlen(tmp));
                printf("\ntotal de leds = %d",leds);
                // x++;
            }
        counter++;
        //printf("\nLEN input = %d \tLen tmp = %d",strlen(input),strlen(tmp));
        printf("\nINPUT = %s\n", input);
    }
    
}