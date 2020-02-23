#include <bits/stdc++.h>
using namespace std;
int n, q[100005][3];
vector<int> v[100005], v1,v2;
vector<int> ans;
int ct[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n-2; i++) {
        for (int j=0;j<3; j++) {
            scanf("%d", &q[i][j]);
            v[q[i][j]].push_back(i);
        }
    }

    for (int i=1; i<=n; i++) {
        if (v[i].size() == 1) {
            v1.push_back(i);
        }
        else if (v[i].size() == 2) {
            v2.push_back(i);
        }
    }
    vector<int> ans;
    ans.clear();

    ans.push_back(v1[0]);
  //  ct[v1[0]]=1;
    int l2=0;
    if (v[v2[0]][0] == v[v1[0]][0] || v[v2[0]][1] == v[v1[0]][0]) {
        ans.push_back(v2[0]);
        l2 = v2[1];
       //  ct[v2[0]]=1;
    } else {
        ans.push_back(v2[1]);
        l2 = v2[0];
       // ct[v2[1]]=1;
    }
    for (int i=2; i<n-2; i++) {

       // cout<<i<<endl;
        int tc1, tc2;
        for (int j=0; j<v[ans[i-2]].size(); j++) {
           // cout << v[ans[i-2]][j] << " " << ct[v[ans[i-2]][j]] << endl;
            if (ct[v[ans[i-2]][j]] != 1){
                tc1 = v[ans[i-2]][j];
            }
        }
        /*for (int j=0; j<3; j++) {
            if (ct[v[ans[i-1]][j]] != 1 && v[ans[i-1]][j] != tc1){
                tc2 = v[ans[i-1]][j];
            }
        }*/ //cout<<i<< " " << tc1 << endl;
        int tc3;
        for (int j=0; j<3; j++) {
            if (q[tc1][j] != ans[i-1] && q[tc1][j] != ans[i-2])
            {
                tc3 = q[tc1][j];
                break;
            }
        } //cout<<i<<endl;
        ans.push_back(tc3);
        ct[tc1] = 1;
    }
    ans.push_back(l2);
    ans.push_back(v1[1]);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
