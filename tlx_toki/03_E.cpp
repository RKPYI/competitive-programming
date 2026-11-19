// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/E
// AI used to discover upper_bound and lower_bound (not used)

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N;

    vector<long long> berat;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        berat.push_back(x);
    }

    sort(berat.begin(), berat.end());

    cin >> Q;

    vector<long long> low;
    vector<long long> high;

    for (int i = 0; i < Q; i++) {
        long long h,l;
        cin >> l >> h;
        low.push_back(l);
        high.push_back(h);
    }

    int n_mid = N / 2;
    
    for (int q = 0; q < Q; q++) {

        int idx_low = upper_bound(berat.begin(), berat.end(), low[q]) - berat.begin();
        int idx_high = upper_bound(berat.begin(), berat.end(), high[q]) - berat.begin();

        cout << idx_high - idx_low << endl;
    }

    return 0;
}