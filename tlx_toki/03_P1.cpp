// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/P1
// AI not used

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<long long> patok(N);
    vector<long long> bebek(K);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i == 0) patok[i] = x;
        else patok[i] = x + patok[i - 1];
    }

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        bebek[i] = x;
    }

    for (int i = 0; i < K; i++) {
        long long jarak = upper_bound(patok.begin(), patok.end(), bebek[i]) - patok.begin();

        cout << jarak << endl;
    }
    

    return 0;
}