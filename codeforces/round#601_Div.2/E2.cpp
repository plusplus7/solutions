#include <bits/stdc++.h>

using namespace std;

int n;
long long s[1000006];

long long check(long long p)
{
    int tp = 0;
    long long ans = 0ll;
    for (int i=0; i<n; i++) {
        if (s[i]%p != 0) {
            ans += min(s[i]%p, p-s[i]%p);
        //    cout << p <<" " << ans<<endl;
        }
    }
  //  }cout << p <<" " << ans<<endl;
    return ans;
}

long long solve()
{
    long long ts = s[n-1], p = 2ll, ans = -1ll;
    while(p*p <= ts) {
        if (ts%p == 0) {
            //cout << p << endl;
            long long cp = check(p);
            if (cp < ans || ans == -1) {
                ans = cp;
            }
            while (ts%p == 0) {
                ts/=p;
            }
        }
        p++;
    }
    if (ts > 1) {
    long long cp = check(ts);
    if (cp < ans || ans == -1) {
        ans = cp;
    }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=0; i<n; i++) {
        long long t;
        cin>>t;

        s[i] += t + (i==0?0ll:s[i-1]);
    }
    if (s[n-1] == 1ll) {
        printf("-1\n");
    } else {
        cout << solve() << endl;
    }
}
