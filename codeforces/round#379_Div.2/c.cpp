#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
long long n, m, k;
long long x, s;
long long a[200005], b[200005];
vector<long long> c, d;

long long nx;
long long ans = 0ll;

long long minl(long long la, long long lb) {
    return la>lb?lb:la;
}

int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    scanf("%I64d%I64d", &x, &s);
    c.clear();
    d.clear();
    for (int i=0; i<m; i++) {
        scanf("%I64d", a+i);
    }
    for (int i=0; i<m; i++) {
        scanf("%I64d", b+i);
    }
    for (int i=0; i<k; i++) {
        long long tc;
        scanf("%I64d", &tc);
        c.push_back(tc);
    }
    for (int i=0; i<k; i++) {
        long long td;
        scanf("%I64d", &td);
        d.push_back(td);
    }

    nx = n*x;
    ans = nx;
    for (int i=0; i<k-1; i++) {
        if (s >= d[i] && s < d[i+1]) {
            ans = minl(ans, (n-c[i]) *x);
        }
    }

    for (int i=0; i<m; i++) {
        if (b[i] <= s) {
            ans = minl(ans, n * a[i]);
        }
    }

    for (int i=0; i<m; i++) {
        long long ss = s - b[i];
        if (ss <= 0) {
            continue;
        }
        vector<long long>::iterator iter = upper_bound(d.begin(), d.end(), ss);
        if (iter == d.begin()) {
            continue;
        }
        int no;
        no = distance(d.begin(), iter)-1;
        ans = minl(ans, (n-c[no]) * a[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
