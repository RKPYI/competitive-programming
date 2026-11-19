#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
    long long n,a,b;
    cin >> n >> a >> b;

    vector<vector<long long>> c(n+1, vector<long long>(n+1, 0));

    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }

    long long total = 0;
    for (int k = a; k <= b; k++) {
        total = (total + c[n][k]) % MOD;
    }

    cout << total << endl;
}