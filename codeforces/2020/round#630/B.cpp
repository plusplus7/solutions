#include <bits/stdc++.h>
using namespace std;
int a[1005];
int ans[1005];
map<int, vector<int> > mp;
int put(int x, int y) {
    if (mp.count(x) == 0) {
        vector<int> res;
        res.clear();
        res.push_back(y);
        mp[x] = res;
    } else {
        mp[x].push_back(y);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int x[11] = {2, 3,5,7,11,13,17,19, 23,29, 31};

    while (T--) {
        int n;
        mp.clear();
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", a+i);
            for (int j=0; j<11; j++) {
                if (a[i]%x[j] == 0) {
                    put(x[j], i);
                    break;
                }
            }
        }
        int color = 1;
        for (map<int, vector<int> > :: iterator iter = mp.begin(); iter != mp.end(); iter++) {
                int f = 0;
            for (int i=0; i< iter->second.size(); i++)  {
                ans[(iter->second)[i]]=color;
        f = 1;
            }
            color+=f;
        }
        printf("%d\n", color-1);
        for (int i=0; i<n; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");

    }
}
