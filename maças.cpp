#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

/*
    Aluno: Vinícius Rangel da Silva Assumpcao
    Matrícula: 668007

    Este programa utiliza a tecnica de memoizacao da programacao dinamica para fazer uma espécie de busca em profundidade a fim de encontrar
    o caminho mais curto capaz de pegar a maior quantidade possivel de maças,
    e possui complexidade o(nmt), sendo que n e m correspondem a quantidade de linhas e colunas da matriz a ser percorrida e t corresponde ao tempo da ultima maça a cair no chao.
*/

int n = -1;
int m = 0;
int k = 0; 
int max_time = 0;
int apples[20][20][1000];
int memoized_array[20][20][2000];


bool validate_position(int current_x, int current_y, int time){
    if(current_y < 0 || current_x < 0 || current_y >= m || current_x >= n || time > max_time)
        return false;

    return true;
}

int traversal(int x, int y, int t){
    int &memoized_value = memoized_array[x][y][t];
    if(memoized_value != -1) 
        return memoized_value;
    int total = 0;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int next_t = t + 1;
            int next_x = x + i;
            int next_y = y + j;
            if(validate_position(next_x, next_y, next_t)){
                int tmp_result = traversal(next_x, next_y, next_t);
                if(tmp_result > total)
                    total = tmp_result;
            }
        }
    }
    return total + apples[x][y][t];
}

int main(){
    int time;
    while(n != 0){
        int x, y;
        cin >> n >> m >> k;
        if(n == 0)
            break;
        max_time = 0;
        memset(apples, 0, sizeof(apples));
        memset(memoized_array, -1, sizeof(memoized_array));
        for(int i = 0; i < k; i++){
            scanf("\n%d%d%d", &x, &y, &time);
            apples[--x][--y][time] = 1;
            if(time > max_time)
                max_time = time;
        }
        scanf("%d%d", &x, &y);
        cout << traversal(--x,--y,0) << endl;
    }
    return 0;
}