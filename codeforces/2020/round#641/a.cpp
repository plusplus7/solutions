#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n>> k;
    for (int i=2; i<=n; i++) {
        if (n%i == 0) {
            n+=i;
            break;
        }
    }
    k--;
    long long ans = n+ 2ll*k;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}