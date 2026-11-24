// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/F
// ai not used

#include <bits/stdc++.h>
using namespace std;

int score = 0;
int highest = 0;
int highest_x = 0;
int highest_y = 0;
int matrix[25][25];
bool done[25][25];
bool dot[25][25];

void recursive(int y, int x, int color, int M, int N, bool toggle_dot = false) {
    if (x >= 0 && y >= 0 && x < N && y < M) {
        if (!done[y][x]) {
            done[y][x] = true;
            if (matrix[y][x] == color) {
                score++;

                if (toggle_dot) {
                    dot[y][x] = true;
                }

                recursive(y-1,x,color,M,N, toggle_dot);
                recursive(y+1,x,color,M,N, toggle_dot);
                recursive(y,x-1,color,M,N, toggle_dot);
                recursive(y,x+1,color,M,N, toggle_dot);
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
                highest_x = j;
                highest_y = i;
            }
            
            for (int done1 = 0; done1 < 25; done1++) {
                for (int done2 = 0; done2 < 25; done2++) {
                    done[done1][done2] = false;
                }
            }
            score = 0;
        }
    }

    recursive(highest_y, highest_x, matrix[highest_y][highest_x], M, N, true);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (dot[i][j]) {
                matrix[i][j] = -1;
            }
        }
    }

    for (int j = 0; j < N; j++) {
        int dasar = -1;
        for (int i = M - 1; i >= 0; i--) {
            if (matrix[i][j] == -1 && dasar == -1) {
                dasar = i;
            } else if (matrix[i][j] != -1) {
                if (dasar == -1) continue;
                matrix[dasar][j] = matrix[i][j];
                matrix[i][j] = -1;
                dasar = -1;
                i = M;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != -1) {
                cout << matrix[i][j] << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    return 0;
}