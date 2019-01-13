#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n;

    int d = 0;
    bool flag = false;

    while (n--) {
        cin >> t >> s;
        if (d == 0 && s[0] != 'S') {
            flag = true;
        }
        if (d == 20000 && s[0] != 'N') {
            flag = true;
        }

        if (s[0] == 'S') {
            d += t;
            if (d > 20000) {
                flag = true;
            }
        }
        if (s[0] == 'N') {
            d -= t;
            if (d < 0) {
                flag = true;
            }
        }
    }
    if (d != 0) {
        flag = true;
    }
    if (!flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;

    }
    return 0;
}
