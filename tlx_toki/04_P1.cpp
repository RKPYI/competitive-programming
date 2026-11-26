// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/P1
// AI used to create the function

#include <bits/stdc++.h>
#include <string>
using namespace std;

string N;
set<long long> unik;

void cari(int idx, long long total, long long angka_skrg, int tanda) {
    if (idx == N.length()) {
        unik.insert(total + (tanda * angka_skrg));
        return;
    }
    
    long long digit = N[idx] - '0';

    cari(idx + 1, total, angka_skrg * 10 + digit, tanda);
    cari(idx + 1, total + (tanda * angka_skrg), digit, 1);
    cari(idx + 1, total + (tanda * angka_skrg), digit, -1);
    

}
int main(){
    cin >> N;

    cari(1,0,N[0] - '0', 1);

    cout << unik.size() << endl;

    return 0;
}