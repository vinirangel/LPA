#include <stdio.h>
#include<stdint.h>
#include<string.h>

const char * subsequencia(char *sequencia, char *substring)
{
    sequencia[strcspn(sequencia, "\n")] = 0;
    substring[strcspn(substring, "\n")] = 0;
    //  printf("\nFUNCTION STRING = %s SUBSTRING = %s",sequencia,substring);
    char *test = strstr(sequencia, substring);
    // printf("\nTEST = %s",test);
    if (test != NULL)
        return "Yes";
    return "No";
}

int main() {
    int testes = 0;
    int counter = 0;
    int queries = 0;
    char input[100001];
    char substring[101];
    //char subsequencia[101];
    scanf("%d", &testes);
    //printf("TESTES = %d",testes);
    fflush(stdin);
    while(counter < testes)
    {
        fgets(input, 100000, stdin) != NULL;
        // printf("\nINPUT = %s",input);
        // printf("\nCOUNTER = %d", counter);
        int subcounter = 0;
        fflush(stdin);
        scanf("  %d", &queries);
        // printf("\nQUERIES = %d",queries);
        fflush(stdin);
        while (subcounter < queries)
        {
            fgets(substring, 100, stdin) != NULL;
            // printf("\nSUBCOUNTER = %d",subcounter);
            // printf("\nSUBSTRING = %s",substring);
            printf(subsequencia(input, substring));
            subcounter++;
            // printf("\nSUBCOUNTER NO FIM = %d",subcounter);
        }
        counter++;
        // printf("COUNTER NO FIM = %d",counter);
        //printf("\nCHGEUEI NO FIM");
    }
}