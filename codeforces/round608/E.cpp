#include <bits/stdc++.h>
using namespace std;

int check(long long x, long long n, long long k) {
    if (x <= 0) {
        return 0;
    }
    long long count = 0ll;
    long long tx = x;
    long long tn;
    if (x%2 == 0) {
        tn = 2;
    } else {
        tn = 1;
    }
    while (tx <= n)
    {
        count += min(tx + tn - 1, n) - tx + 1;
        tx *= 2;
        tn *= 2;
        if (count >= k) {
            return 1;
        }
    }
    if (count >= k) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long s = 0, e = n, mid;
    long long ans = 0;
    
    while (s < e) {
        mid = (s + e +1) / 2ll;
        int t1 = check(mid-1, n, k); 
        int t2 = check(mid, n, k); 
        int t3 = check(mid+1, n, k); 
        if (t1 == 0 && t2 == 0 && t3== 0) {
            e = mid-1;
        } else {
            s = mid;
            if (t1 == 1) {
                ans = mid-1;
            }
            if (t2 == 1) {
                ans = mid;
            }
            if (t3 == 1) {
                ans = mid+1;
            }
        }
    }
    cout << ans << endl;
}