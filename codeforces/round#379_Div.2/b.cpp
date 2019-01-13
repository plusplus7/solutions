#include <iostream>
using namespace std;

long long minl(long long a, long long b) {
    return a > b? b: a;
}

int main() {
    long long k2, k3, k5, k6;
    long long ans = 0ll;
    cin >> k2 >> k3 >> k5>> k6;
    for (long long i=0; i<=k2; i++) {
        long long tans = 0ll;
        long long t1 = min(i, k3);
        long long t2 = min(min(k2-i, k5), k6);
        tans = (t1 * 32ll) + (t2 * 256ll);
        if (tans > ans) {
            ans = tans;
        }
    }
    cout << ans << endl;
}
