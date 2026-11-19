#include <bits/stdc++.h>
using namespace std;

void print(int x, int y) {
    if (x < y) {
        cout << x;
        return;
    }

    int rem = x%y;
    print(x/y, y);
    cout << rem;
}

int main(){
    int x, base;
    cin >> x;
    cin >> base;

    print(x, base);
    cout << endl;

    return 0;
}