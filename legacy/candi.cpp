#include <bits/stdc++.h>
using namespace std;


int main(){
    long long B, C, D;
    cin >> B >> C >> D;
    
    if (C == D) {
        if (B > D) {
            cout << B - D << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    
    long long target = C - D;
    long long amt = 0;
    
    for (long long i = 1; i * i <= target; i++) {
        if (target % i == 0) {
            long long f1 = i;
            long long f2 = target / i;

            if (f1 > D && f1 <= B) amt++;
            if (f1 != f2 && f2 > D && f2 <= B) amt++;
        }
    }

    cout << amt << endl;

    return 0;
}

// B = max ekor bebek
// C = butir jajanan untuk bebek
// D = sisa butir setelah dibagi ke bebeknya
// Tujuan = menerka banyaknya bebek (berapa banyak kemungkinan banyaknya bebek berbeda)