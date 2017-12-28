#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b) {
    int ans = 1;
    for (int i=1; i<n; i++) {
        if (a < i || b < n-i) {
            continue;
        }
        int ta = a/i;
        int tb = b/(n-i);
        int tans = ta > tb ? tb : ta;
        ans = ans < tans ? tans : ans;
    }
    return ans;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = solve(n, a, b);
    cout << ans << endl;
    return 0;
}