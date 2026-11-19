#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int l,r;
        int erased = 0;
        cin >> l >> r;
        if (l == 0 || r == 0) {
            cout << erased << "\n";
        } else {
            int beauty;
            for (int i = l; l <= r; i++) {
                beauty += i;
            }
            if (l <= beauty || beauty <= r) {
                cout << erased << "\n";
            } else {
                if (r < 0 || l > 0) {
                    cout << (r - l);
                } else {
                    int m = min(r, -l);
                    cout << max(0, r - l - 2 * m - 1);
                }
            }
        }
    }

    return 0;
}