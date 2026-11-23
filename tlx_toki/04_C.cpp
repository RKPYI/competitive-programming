// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/B
// AI used to generate the function

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> current;
bool used[10];
void solve() {
    if (current.size() == N) {
        for (int digit: current) {
            cout << digit;
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (used[i]) continue;

        int len = current.size();
        if (len >= 2) {
            int a = current[len - 2];
            int b = current[len - 1];
            int c = i;

            bool middle_peak = (b > a && b > c);
            bool middle_valley = (b < a && b < c);

            if (!middle_peak && !middle_valley) continue;
        }

        used[i] = true;
        current.push_back(i);
        solve();

        current.pop_back();
        used[i] = false;
    }
}

int main(){
    cin >> N;
    solve();
    return 0;
}