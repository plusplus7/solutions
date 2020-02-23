#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int m[1005];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", m+i);
    }

    vector<int> ans;
    long long ma = -1;
    for (int i=0; i<n; i++) {
        int tans[1005];
        long long mta = (long long)m[i];
        tans[i] = m[i];
        for (int j=i-1; j>=0; j--) {
            tans[j] = min(tans[j+1], m[j]);
            mta+=(long long)tans[j];
        }
        for (int j=i+1; j<n; j++) {
            tans[j] = min(tans[j-1], m[j]);
            mta+=(long long)tans[j];
        }
        if (ma < mta) {
            ma = mta;
            ans.clear();
            for(int j=0; j<n; j++){
                ans.push_back(tans[j]);
            }
        }
    }
    for (int i=0; i<ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
