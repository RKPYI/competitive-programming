// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/C
// AI not used

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> kata;

    for (int i=0;i<N;i++) {
        string x;
        cin >> x;
        kata.push_back(x);
    }

    vector<string> sorted_kata;

    for (int i = 1; i < 11; i++) {
        vector<string> temp;
        for (int j = 0; j < N; j++) {
            if (kata[j].size() == i) {
                temp.push_back(kata[j]);
            }
        }
        sort(temp.begin(), temp.end());

        for (string t: temp) {
            sorted_kata.push_back(t);
        }

        temp.clear();
    }


    for (string k: sorted_kata) {
        cout << k << endl;
    }

    return 0;
}