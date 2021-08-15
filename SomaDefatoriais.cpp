#include <stdio.h>
#include<stdint.h>

unsigned long long fatoriais(unsigned long long fatorial)
{
    //retorna 1 caso o parâmetro seja 0, caso contrário calcula o seu fatorial
    unsigned long long resultado = 1;
    if(fatorial == 0)
        return 1;
    else{
        for (unsigned long long count = fatorial; count > 1; count--)
        {
            resultado = resultado*count;
        }
    }
        return resultado;        
}

int main() {
    unsigned long long fatorial1 = 0;
    unsigned long long fatorial2 = 0;
    unsigned long long resultado = 0;
    char input[100];
    while(fgets(input, 100, stdin) != NULL)
    {
        sscanf(input, "%d %d", &fatorial1, &fatorial2);
        //printf("\nFAT1 = %lu",fatoriais(fatorial1));
        //printf("\nFAT2 = %lu",fatoriais(fatorial2));
        resultado = fatoriais(fatorial1) + fatoriais(fatorial2);
        printf("%lu\n", resultado);
    }
}