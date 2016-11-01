#include "bits/stdc++.h"

using namespace std;

int main() {
    string a;
    cin >> a;
    int pr = -1, ans = -1;
    for (int i=0; i<=a.length(); i++) {
        if (i == a.length()
        || a[i] == 'A'
        || a[i] == 'E'
        || a[i] == 'I'
        || a[i] == 'O'
        || a[i] == 'U'
        || a[i] == 'Y'
        ) {
            ans = max(i-pr, ans);
            pr = i;
        }
    }
    if (ans == -1) {
        ans = a.length() + 1;
    }
    cout << ans <<endl;
}
