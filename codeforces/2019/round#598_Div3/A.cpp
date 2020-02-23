#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--) {
        long long a, b, n, S;
        cin >> a >> b >> n >> S;
        long long t = S/n;
        if (t > a) {
            t = a;
        }
        if (S - t*n <= b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
