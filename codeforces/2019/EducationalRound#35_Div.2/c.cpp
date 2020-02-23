#include <bits/stdc++.h>
using namespace std;

int a[3];
int solve() {
    if (a[0] == 1 || a[1] == 1 || a[2] == 1)
        return 1;
    int check[6][3] = {
        {1, 2, 0},
        {0, 2, 1},
        {1, 0, 2},
        {2, 1, 0},
        {0, 1, 2},
        {2, 0, 1},
    };
    for (int i=0; i<6; i++) {
        int s, t[3] = {-1, -1, -1}, lt = 0;
        for (s=0; s<20000; s++) {
            int j = 0;
            for (j=0; j<3; j++) {
                if (t[j] == -1) continue;
                if ((s - t[j]) % a[check[i][j]] == 0) break;
            }
            if (j == 3) {
                if (lt == 3) break;
                t[lt++] = s;
            }
        }
        if (s == 20000) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> a[0] >> a[1] >> a[2];
    int ans = solve();
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}