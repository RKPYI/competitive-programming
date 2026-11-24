// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/E
// ai not used

#include <bits/stdc++.h>
using namespace std;

int score = 0;
int highest = 0;
int matrix[25][25];
bool done[25][25];

void recursive(int y, int x, int color, int M, int N) {
    if (x >= 0 && y >= 0 && x < N && y < M) {
        if (!done[y][x]) {
            done[y][x] = true;
            if (matrix[y][x] == color) {
                score++;

                recursive(y-1,x,color,M,N);
                recursive(y+1,x,color,M,N);
                recursive(y,x-1,color,M,N);
                recursive(y,x+1,color,M,N);
            }
        }
    }

    return;
}

int main(){
    int M,N;
    cin >> M >> N;
    

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            recursive(i,j,matrix[i][j],M,N);
            if (score > highest) {
                highest = score;
            }
            
            for (int done1 = 0; done1 < 25; done1++) {
                for (int done2 = 0; done2 < 25; done2++) {
                    done[done1][done2] = false;
                }
            }
            score = 0;
        }
    }

    cout << highest * (highest-1) << endl;

    return 0;
}