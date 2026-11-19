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
    long long num;
    cin >> num;
    vector<long long> primes = prima(num);

    vector<vector<long long>> factor;

    long long psize = primes.size();
    long long i = 0;
    while (i < psize && num > 1) {
        if (num % primes[i] == 0) {
            long long power = 0;
            while (num % primes[i] == 0) {
                num /= primes[i];
                power++;
            }
            factor.push_back({primes[i], power});
        }
        i++;
    }

    for (long long count = 0; count < factor.size(); count++ ) {
        cout << factor[count][0];
        if (factor[count][1] > 1) {
            cout << "^" << factor[count][1];
        }

        if (count + 1 < factor.size()) cout << " x ";
    }
    cout << endl;
}