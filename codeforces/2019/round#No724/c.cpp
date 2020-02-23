#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
#define LL long long

LL n, m, k;
pair<LL, LL> pt[100005];
LL tag[100005];

LL exgcd(LL a, LL b, LL &x, LL &y){
    if(b==0){
        x = 1L; y = 0L;
        return a;
    }
    LL r = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}

inline LL lcm(LL a,LL b) {
    return a/gcd(a,b)*b;
}

int solve(LL a, LL b, LL c, LL &x, LL &y) {
    LL g = exgcd(a, b, x, y);
    if (c % g != 0 ) {
        return 1;
    }
    LL q = abs(b/g);
    x = x * c/g;
    x = (x%q + q) % q;
    return 0;
}

int main() {
    cin >> n >> m >> k;
    LL l = lcm(n, m);
    LL n2 = n*2;
    LL m2 = m*2;
    for (int i=0; i<k; i++) {
        cin >> pt[i].first >> pt[i].second;
        tag[i] = -1L;
    }
    for (int i=0; i<k; i++) {
        LL ans = l + 2333333L;
        {
            LL x = pt[i].first;
            LL y = pt[i].second;
            LL s, t;
            if (solve(n2, -m2, y-x, s, t) == 0) {
                LL tmpx = 2 * n * s + x;
                if (tmpx >= 0 && tmpx <= l) {
                    ans = min(ans, tmpx);
                }
            }
        }
        {
            LL x = -pt[i].first;
            LL y = pt[i].second;
            LL s, t;
            if (solve(n2, -m2, y-x, s, t) == 0) {
                LL tmpx = 2 * n * s + x;
                if (tmpx >= 0 && tmpx <= l) {
                    ans = min(ans, tmpx);
                }
            }
        }
        {
            LL x = pt[i].first;
            LL y = -pt[i].second;
            LL s, t;
            if (solve(n2, -m2, y-x, s, t) == 0) {
                LL tmpx = 2 * n * s + x;
                if (tmpx >= 0 && tmpx <= l) {
                    ans = min(ans, tmpx);
                }
            }
        }
        {
            LL x = -pt[i].first;
            LL y = -pt[i].second;
            LL s, t;
            if (solve(n2, -m2, y-x, s, t) == 0) {
                LL tmpx = 2 * n * s + x;
                if (tmpx >= 0 && tmpx <= l) {
                    ans = min(ans, tmpx);
                }
            }
        }
        if (ans > l) {
            tag[i] = -1L;
        } else {
            tag[i] = ans;
        }
    }
    for (int i=0; i<k; i++) {
        cout << tag[i] << endl;
    }
}
