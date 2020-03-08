#include <bits/stdc++.h >
using namespace std;

int main()
{
    int T;
    cin >>T;
    while (T--) {
        int n, a[105];
        cin >> n;
        vector<int> ans;
        int f = -1;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            if (a[i]&1) {
                if (f == -1) f = i;
                else {
                    ans.push_back(f);
                    ans.push_back(i);
                    f = -1;
                }
            } else {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        cout << ans.size()<< endl;;
        for (int i=0; i<ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}
