// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/F
// AI used to give idea about prefix sums

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N;

    vector<int> hewan(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i == 0) hewan[i] = x;
        else hewan[i] = hewan[i-1] + x;
    }

    cin >> Q;
    vector<int> num;

    for (int i = 0; i < Q; i++) {
        int x; 
        cin >> x;
        num.push_back(x);
    }

    for (int qq = 0; qq < Q; qq++) {
        int count = num[qq];

        cout << lower_bound(hewan.begin(), hewan.end(), count) - hewan.begin() + 1 << endl;
    }

    return 0;
}