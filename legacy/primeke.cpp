#include <bits/stdc++.h>
using namespace std;

vector<long long> prima(long long N) {
    vector<bool> eliminated(N+1, false);
    vector<long long> primeList;

    for (long long i = 2; i <= N; i++) {
        if (!eliminated[i]) {
            primeList.push_back(i);

            for (long long j = i * i; j <= N; j = j + i) {
                eliminated[j] = true;
            }
        }
    }

    return primeList;
}

int main(){
    int tc;
    cin >> tc;
    vector<int> output;
    vector<long long> primes = prima(990002);

    for (int i = 0; i < tc; i++) {
        int num;
        cin >> num;
        output.push_back(primes[num - 1]);
    }

    for (int x: output) {
        cout << x << endl;
    }
}