#include <bits/stdc++.h>
using namespace std;

int s[1005], d[1005];
int ans = 0;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> d[i];
    }

    for (int i=0; i<n; i++) {
        if (ans < s[i]) {
            ans = s[i];
        } else {
            ans ++;
            while ((ans-s[i])%d[i] != 0) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}