// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/G
// ai used

#include <bits/stdc++.h>
using namespace std;

int score = 0;
int highest = 0;
int matrix[25][25];
int backup[25][25];   // Added: stores the original board
bool done[25][25];
bool dot[25][25];
bool tested[25][25];  // Added: tracks which groups were already tried as Move 1

void recursive(int y, int x, int color, int M, int N, bool toggle_dot = false) {
    if (x >= 0 && y >= 0 && x < N && y < M && color > 0) {
        if (!done[y][x]) {
            if (matrix[y][x] == color) {
                done[y][x] = true;
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

void drop(int M, int N) {
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

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            dot[i][j] = false;
        }
    }
}

int main(){
    int M,N;
    cin >> M >> N;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            backup[i][j] = matrix[i][j]; // Save original board
        }
    }

    int max_total_score = 0;
    
    // Loop over every group as a candidate for Move 1
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > 0 && !tested[i][j]) {
                
                // Reset done[][] and count/mark Move 1 group
                for (int d1 = 0; d1 < 25; d1++)
                    for (int d2 = 0; d2 < 25; d2++)
                        done[d1][d2] = false;
                score = 0;

                recursive(i, j, matrix[i][j], M, N, true);

                // Mark this whole group as tested so we don't try it twice
                for (int r = 0; r < M; r++)
                    for (int c = 0; c < N; c++)
                        if (dot[r][c]) tested[r][c] = true;

                // Move 1 is only valid if the group has at least 2 balls
                if (score >= 2) {
                    int move1_score = score * (score - 1);
                    drop(M, N);

                    // Reset done[][] and highest BEFORE scanning the dropped board for Move 2
                    for (int d1 = 0; d1 < 25; d1++)
                        for (int d2 = 0; d2 < 25; d2++)
                            done[d1][d2] = false;
                    highest = 0;

                    for (int r = 0; r < M; r++) {
                        for (int c = 0; c < N; c++) {
                            if (matrix[r][c] > 0 && !done[r][c]) {
                                score = 0;
                                recursive(r, c, matrix[r][c], M, N);
                                if (score > highest) {
                                    highest = score;
                                }
                            }
                        }
                    }

                    int move2_score = (highest >= 2) ? highest * (highest - 1) : 0;
                    if (move1_score + move2_score > max_total_score) {
                        max_total_score = move1_score + move2_score;
                    }
                }

                // Restore matrix from backup and clear dot[][] for the next Move 1 test
                for (int r = 0; r < M; r++) {
                    for (int c = 0; c < N; c++) {
                        matrix[r][c] = backup[r][c];
                        dot[r][c] = false;
                    }
                }
            }
        }
    }

    cout << max_total_score << endl;

    return 0;
}