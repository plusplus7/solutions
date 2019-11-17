#include <bits/stdc++.h>

using namespace std;
int c[1000005];
int v[1000005];
int x;
vector<int> ans;
int main()
{
    int n;

    cin >>n;
    memset(c, 0, sizeof(c));
    x= 0;
    int tk = 0, t, day = 1;
    for (int i=0; i<n; i++) {
        cin >> t;
        if (t < 0 &&  c[-t] == 1) {
            c[-t] = 0;
            x--;
        }
        else if (t < 0 &&  c[-t] == 0) {
            cout << -1 << endl;
            return 0;
        }
        else if (t > 0 &&  c[t] == 0) {
            if (v[t] < day) {

            c[t] = 1;
            v[t] = day;
            x++;
            }
            else {
                 cout << -1 << endl;
            return 0;
            }

        }
        else if (t > 0 &&  c[t] == 1) {
            cout << -1 << endl;
            return 0;
        }
        tk++;

        if (x == 0) {
            day ++;
            ans.push_back(tk);
            tk = 0;
        }
    }
    if (x != 0) {
        cout << -1 << endl;
    }
    else {
        cout << ans.size() << endl;
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}
