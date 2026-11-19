#include <bits/stdc++.h>
using namespace std;

int main(){
    char N[256];
    cin >> N;

    int len = ceil(sqrt(strlen(N)));
    char matrix[len][len];
    int counter = 0;
    bool reverse = false;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (counter >= strlen(N)) {
                matrix[i][j] = '.';
            } else {
                matrix[i][j] = N[counter];
            }
            counter++;
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i % 2 == 0) {
                cout << matrix[i][j];
            } else {
                cout << matrix[i][len-1-j];
            }
        }
        cout << endl;
    }
}