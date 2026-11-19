#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    set<pair<int,int>> pasak;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pasak.insert({x,y});
    }

    long long unique = pasak.size();

    if (unique < 3) {
        cout << 0 << endl;
    } else {
        long long kombinasi = (unique * (unique-1) * (unique-2)) / 6;
        cout << kombinasi << endl;
    }

    
}