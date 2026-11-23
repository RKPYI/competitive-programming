// Problemset Link: https://tlx.toki.id/problems/troc-18/A
// AI not used

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if (N < 7 && (N == 2 || N == 3 || N == 5)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}