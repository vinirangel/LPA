#include <stdio.h>
#include<stdint.h>
#include<string.h>

//Este algoritmo possui um custo de O(n³), onde n e a quantidade de testes e de querys a serem realizados 

const char * subsequencia(char *sequencia, char *substring)
{
	sequencia[strcspn(sequencia, "\n")] = 0;
	substring[strcspn(substring, "\n")] = 0;
	char *test = strstr(sequencia, substring);
	if (test != NULL)
		return "Yes\n";
	return "No\n";
}

int main() {
	int testes = 0;
	int counter = 0;
	int queries = 0;
	char input[100001];
	char substring[101];
	scanf("%d", &testes);
	while( counter < testes )
	{
		scanf("%s", &input);
		int subcounter = 0;
		scanf("%d", &queries);
		while (subcounter < queries)
		{
			scanf("%s", &substring);
			printf(subsequencia(input, substring));
			subcounter++;
		}
		counter++;
	}
}
