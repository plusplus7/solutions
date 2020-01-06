#include <bits/stdc++.h>
using namespace std;

long long cst[37], c[37], p[37];

int main() {
    int n, L;

    cin >> n >> L;
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }

    for (int i=0; i<32; i++) {
        if (i == 0) {
            cst[i] = c[i];
        } else {
            if (i >= n) {
                cst[i] = cst[i -1] << 1ll;
            } else {
                cst[i] = c[i] > (cst[i - 1] << 1ll) ? (cst[i - 1] << 1ll) : c[i];
            }
        }
    }
    int f = L & 1;
    int m = 0;
    p[0] = (L & 1) ? cst[0] : 0;
    for (int i=1; i<32; i++) {
        int v = L & (1 << i);
        if (v) {
            m = i;
            p[i] = cst[i] > (cst[i - 1] << 1ll) ? (cst[i - 1] << 1ll) : cst[i];
            f = 1;
        }
        if (f) {
            p[i] += p[i - 1] < cst[i] ? p[i - 1] : cst[i];
        }
    }
    
    cout << p[31] << endl;
    return 0;
}