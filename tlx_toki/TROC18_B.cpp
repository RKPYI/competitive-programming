// Problemset Link: https://tlx.toki.id/problems/troc-18/B
// editorial read

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << N*N << endl;
    } else {
        cout << N*N - 1 << endl;
    }

    return 0;
}