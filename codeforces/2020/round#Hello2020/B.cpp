#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> s[100005];
vector<int> ma;
int mi[100005];
int sd[100005];
int cd = 0;
long long ans = 0ll;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        sd[i] = 0;
        int l, tma = -1, pr = 0x7fffffff, ds = 0;
        mi[i] = 0x7fffffff;
        scanf("%d", &l);
        s[i].clear();
        while (l--) {
            int t;
            scanf("%d", &t);
            if (t < mi[i]) mi[i]= t;
            if (t > tma) tma = t;
            if (t > pr) ds = 1;
            s[i].push_back(t);
            pr = t;
        }
        if (ds == 0) {
            ma.push_back(tma);
        }
        else {
            cd ++;
            sd[i] = 1;
        }
    }

    sort(ma.begin(), ma.end());
    for (int i=0; i<n; i++) {
        if (sd[i] == 1) {
            ans += (long long)n;
        } else {
            ans += ma.end() - upper_bound(ma.begin(), ma.end(), mi[i]);
            ans += (long long)cd;
        }
    }
    cout << ans << endl;
    return 0;
}
