#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cb = 0, cw = 0;
    cin >> n;
    char b[500];
    cin >> b;

    for (int i=0; i<n; i++) {
        if (b[i] == 'B') cb++;
        else cw ++;
    }
    if ((cb&1) == 1 && (cw&1) == 1) {
        printf("-1\n");
        return 0;
    }
    char tc = 'B';
    if ((cw&1) == 0) {
        tc = 'W';
    }
    else
    {
        tc = 'B';
    }

    vector<int> ans;
    ans.clear();
    for (int i=0; i<n-1; i++) {
        if (b[i] == tc) {
            ans.push_back(i+1);
            if (b[i+1] == 'B') {
                b[i+1]='W';
            } else if (b[i+1] == 'W') {
                b[i+1]='B';
            }
        }
    }
    cout << ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}