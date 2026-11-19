// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/D
// AI not used

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int kartu[N];

    for (int i = 0; i < N; i++) {
        cin >> kartu[i];
    }

    bool sorted = false;
    long long count = 0;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < N-1; i++) {
            if (kartu[i] > kartu[i+1]) {
                int temp = kartu[i];
                kartu[i] = kartu[i+1];
                kartu[i+1] = temp;
                count++;
                sorted = false;
            }
        }
    }

    cout << count << endl;

    return 0;
}