// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/A
// AI used to tell the correct logical answer

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main(){
    char A[1001], B[1001];
    cin >> A;
    cin >> B;
    
    int A_len = strlen(A);
    int B_len = strlen(B);

    if (A_len - B_len != 1) {
        cout << "Wah, tidak bisa :(\n";
        return 0;
    }

    int i = 0, j = 0;
    int skip = 0;

    while (i <= A_len && j <= B_len) {
        if (A[i] == B[j]) {
            i++;
            j++;
        } else {
            skip++;
            i++;
        }
    }

    if (skip <= 1) {
        cout << "Tentu saja bisa!\n";
    } else {
        cout << "Wah, tidak bisa :(\n";
    }

    return 0;
}