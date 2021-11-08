/*
    Aluno: Vinícius Rangel da Silva Assumpcao
    Matrícula: 669007
*/

#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
	Este programa utiliza programacao dinamica e a tecnica de bitmasking para resolver o problema TSP e possui complexidade de O(n^2*n^2),
	onde n corresponde ao numero de espacos do tabuleiro
*/

struct Triple {
	int v[3];
};

Triple new_Triple(int x, int y, int z) {
	return (Triple){{ x, y, z }};
}

int travelingSalesman(int, int);

char board[101][101];
int lines, columns, board_spc;
int array[150][150], dist[150][150], dp[150][150], tmp[16][66000];

int main() {
    
	while (true) {
        cin >> lines;
        cin >> columns;
        cin >> board_spc;

        if (lines == 0 && columns == 0 && board_spc == 0) 
			break;
        
		for (int y = 0; y <= board_spc; y += 1) {
			for (int x = 0; x <= (1 << (board_spc + 1)) - 1; x++)
				tmp[y][x] = -1;
		}

        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                array[i][j] = -1;
            } 
        }
        
		for (int i = 0; i < lines; i++)
			cin >> board[i];
        
		int pawn = 0;
		for (int y = 0; y < lines; y++) {
			for (int x = 0; x < columns; x++) {
				switch (board[y][x]) {
				case 'P':
					pawn++;
					array[y][x] = pawn;
					break;
				case 'C':
					array[y][x] = 0;
					break;
				}
			}
		}
        
        for (int i = 0; i < board_spc; i++)
        {
            for (int j = 0; j < board_spc; j++)
            {
                dist[i][j] = 500000;
            } 
        }
        
		for (int i = 0; i < lines; i += 1) {
			for (int j = 0; j < columns; j += 1) {
				if (array[i][j] != -1) {
					int v = array[i][j];
					int x = i;
					int y = j;
                    
                    for (int i = 0; i < lines; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            dp[i][j] = 0;
                        } 
                    }
    
				    queue<Triple> q;
				    q.push(new_Triple(0, x, y));
				    
				    while (1) {
				    	if (q.empty()) break;

						Triple current = q.front();
						q.pop();
				        
						int previous = current.v[0];
						int px = current.v[1];
						int py = current.v[2];
				        
						if ((px < 0 || px > lines ) | (py < 0 || py > columns) | board[px][py] == '#' || dp[px][py])
							continue;
				        
						dp[px][py] = true;
				        
						if (array[px][py] != -1)
							dist[v][array[px][py]] = previous;
				        
						q.push(new_Triple(previous + 1, px + 1, py + 2));
						q.push(new_Triple(previous + 1, px + 1, py - 2));
						q.push(new_Triple(previous + 1, px + 2, py + 1));
						q.push(new_Triple(previous + 1, px + 2, py - 1));
						q.push(new_Triple(previous + 1, px - 2, py + 1));
						q.push(new_Triple(previous + 1, px - 2, py - 1));
						q.push(new_Triple(previous + 1, px - 1, py + 2));
						q.push(new_Triple(previous + 1, px - 1, py - 2));
					}
				}
			}
		}
        
		cout << travelingSalesman(1, 0) << endl;
	}
    
	return 0;
}

int travelingSalesman(int bitMask, int position) {
	int answer = 100000;

	if (tmp[position][bitMask] == -1) {
		if (bitMask == (( 1 << (board_spc + 1)) - 1)) {
			tmp[position][bitMask] = dist[position][0];
			return tmp[position][bitMask];
		}
	        
		for (int next = 0; next <= board_spc; next++) {
			int s = bitMask & (1 << (next));
			if (next != position && !s) {
				int result = travelingSalesman(bitMask | (1 << (next)), next) + dist[position][next];
				answer = min(answer, result);
			}
		}
		return tmp[position][bitMask] = answer;
	}

	return tmp[position][bitMask];
}