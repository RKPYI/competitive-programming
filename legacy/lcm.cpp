#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    long long D[N];
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    long long num = 1;
    for (int i = 0; i < N; i++) {
        num = lcm(D[i], num);
    }

    cout << num << endl;
}