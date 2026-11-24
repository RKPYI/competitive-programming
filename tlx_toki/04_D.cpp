// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/D
// hint 1 read, hint 2 read

#include <bits/stdc++.h>
using namespace std;

int score = 0;
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
    
    int B,K;
    cin >> B >> K;
    
    recursive(B,K,matrix[B][K],M,N);

    cout << score * (score-1) << endl;

    return 0;
}