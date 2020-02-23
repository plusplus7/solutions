#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    if (t > k && t < n) {
        cout << k << endl;
    } else if (t <= k){
        cout << t << endl;
    } else {
        cout << n+k-t << endl;
    }
}
