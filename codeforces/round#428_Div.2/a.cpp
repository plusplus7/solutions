#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, k, a[102];
    cin >> n >> k;
    int bran = 0, arya = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        arya += a[i];
        if (arya >= 8) {
            bran += 8;
            arya -= 8;
        } else {
            bran += arya;
            arya = 0;
        }
        if (bran >= k) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}