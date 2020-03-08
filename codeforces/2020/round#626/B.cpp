#include <bits/stdc++.h >
using namespace std;

int n, m, k;
int a[40005], b[40005];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    vector<int> ck;
    for (int i=1; i<=sqrt(k); i++){
        if (k%i == 0) {
            ck.push_back(i);
            if (i != k/i){
                ck.push_back(k/i);
            }
        }
    }

    map<int, int> la;
    la.clear();
    int al = -1;
    for (int i=0; i<n; i++){
        int t;
        scanf("%d", &t);
        if (t == 1 && al == -1) al=1;
        else if (t == 1 && al != -1) al++;
        else if (t == 0 && al != -1) {
            if (la.count(al) == 0) {
                la[al] = 1;
            } else {
                la[al] ++;
            }
            al = -1;
        }
    }
    if (al != -1) {
        if (la.count(al) == 0) {
            la[al] = 1;
        } else {
            la[al] ++;
        }
    }

    long long ans = 0ll;
    int bl = -1;
    for (int i=0; i<m; i++){
        int t;
        scanf("%d", &t);
        if (t == 1 && bl == -1) bl=1;
        else if (t == 1 && bl != -1) bl++;
        else if (t == 0 && bl != -1) {
            for (map<int,int>::iterator iter = la.begin(); iter != la.end(); iter++) {
                al = iter->first;
                for (int j=0; j<ck.size(); j++) {
                    int kc = k/ck[j];
                    if (ck[j] <= al && kc <= bl) {
                        ans += (long long)((al-ck[j]+1) * (bl-kc+1)) * (long long)(iter->second);
                    }
                }
            }
            bl = -1;
        }
    }
    if (bl != -1) {
        for (map<int,int>::iterator iter = la.begin(); iter != la.end(); iter++) {
            al = iter->first;
            for (int j=0; j<ck.size(); j++) {
                int kc = k/ck[j];
                if (ck[j] <= al && kc <= bl) {
                    ans += (long long)((al-ck[j]+1) * (bl-kc+1)) * (long long)(iter->second);
                }
            }
        }
    }
    cout << ans << endl;
}
