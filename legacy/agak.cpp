#include <bits/stdc++.h>
using namespace std;

bool agak(int N) {
    int jmlfactor = 0;

    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            if (i*i == N) {
                jmlfactor++;
            } else {
                jmlfactor += 2;
            }
        }

        if (jmlfactor > 2) {
            return false;
        }
    }

    return true;
}

int main(){
    int tc;
    cin >> tc;
    bool output[tc];

    for (int i = 0; i < tc; i++) {
        int x;
        cin >> x;
        output[i] = agak(x);
    }

    for (int x: output) {
        if (x) cout << "YA\n";
        else cout << "BUKAN\n";
    }
}