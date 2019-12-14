
#include <bits/stdc++.h>
using namespace std;
char s[200005];
long long c[26], sc[200005];
set<int> v;
int main()
{

    long long n, k, ans;
    cin >> n >> k;
    cin >> s;

     v.clear();
    while (k--) {
        char vc;
        cin >> vc;
        v.insert(vc-'a');
    }

    ans=0;

    memset(c, 0, sizeof(c));
    if (k == 26) {
        cout << (n*(n+1ll))/2ll<<endl;
    } else {
        long long pr = -1ll;
        for (long long i=0; s[i]; i++) {
            int x = s[i]-'a';
            if (v.count(x) == 0) {
                long long l = (long long)i-1ll-pr;
                pr = i;
                if (l <= 0) {
                    continue;
                }

                ans += (l*(l+1ll))/2ll;

            }
        }
        long long l = (long long)n-1ll-pr;
                if (l > 0) {
                    ans += (l*(l+1ll))/2ll;
                }


    }
    cout << ans << endl;
    return 0;
}
