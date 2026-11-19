#include <bits/stdc++.h>
using namespace std;

int main(){
    long long B, K;
    cin >> B;
    cin >> K;

    vector<long long> pemberat;
    long long penyeimbang = 0;
    long long selisih = K - B;
    int index = 0;
    
    for (int i = 60; i >= 0; i--) {
        long long berat = (1LL << i);
        if (penyeimbang + berat <= selisih) {
            pemberat.push_back(berat);
            penyeimbang += berat;
        }
        index++;
    }

    int pemberat_len = pemberat.size();
    for (int i = 0; i < pemberat_len; i++) {
        cout << pemberat[i] << endl;
    }
}