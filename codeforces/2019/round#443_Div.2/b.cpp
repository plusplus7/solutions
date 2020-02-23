#include <bits/stdc++.h>
using namespace std;

queue<long long> q;
int main() {
    long long k, n, a[505];
    long long mn = -1;;

    while (!q.empty()) q.pop();

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mn = a[i] > mn ? a[i] : mn;
        q.push(a[i]);
    }

    if (k >= n) {
        cout << mn << endl;
        return 0;
    }

    long long w = q.front();
    q.pop();
    long long ck = 0;
    while (ck != k) {
        long long t2 = q.front();
        q.pop();
        if (w > t2) {
            ck++;
            q.push(t2);
        } else {
            q.push(w);
            w = t2;
            ck = 1;
        }
    }
    cout << w << endl;
    system("pause");
    return 0;
}