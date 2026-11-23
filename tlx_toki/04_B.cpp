// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/04/problems/B
// AI used to generate recursive function (damn can't think)

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> current_combination;
void recursive(int start) {
    if (current_combination.size() == K) {
        for (int i = 0; i < K; i++) {
            cout << current_combination[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= N; i++) {
        current_combination.push_back(i);
        recursive(i + 1);
        current_combination.pop_back();
    }
} 

int main(){
    cin >> N >> K;
    recursive(1);
    return 0;
}