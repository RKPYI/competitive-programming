#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    
    long long e = (a * d) + (c * b);
    long long f = b*d;

    long long div = gcd(e,f);

    cout << e / div << " " << f / div << endl;
}