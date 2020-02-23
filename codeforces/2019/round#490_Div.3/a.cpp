#include <iostream>
using namespace std;

int main()
{
    int n, k, a[102];
    int s, e;
    cin >> n >> k;

    s = 0;
    e = n-1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    while (s <= e && (a[s] <= k || a[e] <= k)) {
        ans++;
        if (a[s] <= k) {
            s++;
            continue;
        }
        if (a[e] <= k) {
            e--;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}