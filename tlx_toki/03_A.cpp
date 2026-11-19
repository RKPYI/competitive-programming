// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/A
// AI used to find bug when curr_sel == selisih

#include <bits/stdc++.h>
using namespace std;

long long abso(int n) {
    if (n < 0) return -n;
    else return n;
}

int main(){
    long long N, X;
    cin >> N >> X;

    long long deret[N];

    for (int i = 0; i < N; i++) {
        cin >> deret[i];
    }

    long long selisih = 1e12;
    int index = -1;
    for (int i = 0; i < N; i++) {
        long long curr_sel = abso(deret[i] - X);
        if (curr_sel < selisih) {
            selisih = curr_sel;
            index = i;
        } else if (curr_sel == selisih) {
            if (deret[i] < deret[index]) {
                index = i;
            }
        }
    }

    cout << deret[index];

    return 0;
}