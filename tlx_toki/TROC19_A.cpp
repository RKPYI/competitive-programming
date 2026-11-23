// Problemset Link: https://tlx.toki.id/problems/troc-19/A
// AI not used

#include <bits/stdc++.h>
using namespace std;

int main(){
    int P, Q;
    cin >> P >> Q;
    int total = P*P + Q*Q + 1;

    if (total % 4 == 0) {
        cout << total / 4 << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}