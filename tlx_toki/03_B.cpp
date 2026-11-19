// Problemset Link: https://tlx.toki.id/courses/competitive-1/chapters/03/problems/B
// AI used to debug precision

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> deret;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        deret.push_back(x);
    }

    
    sort(deret.begin(), deret.end());;
    
    cout << fixed << setprecision(1);
    int mid = deret.size() / 2;
    if (deret.size() % 2 == 0) {
        cout << (deret[mid] + deret[mid-1]) / 2.0 << endl;
    } else {
        cout << deret[mid] / 1.0 << endl;
    }


    return 0;
}