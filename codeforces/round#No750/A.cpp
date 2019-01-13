#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int all = 4 * 60 - k;

    if (all <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        cnt = cnt + i*5;
        if (cnt > all) {
            cout << i-1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
