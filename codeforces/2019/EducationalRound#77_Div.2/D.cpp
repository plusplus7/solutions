#include <bits/stdc++.h>
using namespace std;

int m,n,k,t;
int a[200005];
int mxr[200005];

struct T
{
    int l;
    int r;
    int d;
    T(int l, int r, int d):l(l),r(r),d(d) {}
};

vector<T> gao;

bool cmp(int a, int b) {
    return a>b;
}

bool cmpgao(T a, T b) {
    return a.d < b.d;
}

bool cmpts(T &a, T &b){
    return a.r < b.r;
}

bool check(int x)
{
    int low = x == 0? 0:a[x-1];
    int idx = upper_bound(gao.begin(), gao.end(),  T(0, 0, low),cmpgao) - gao.begin();

    int mr = mxr[idx];
    cout << idx << " " << x << endl;
    return (idx*2)+n+1 <= t;
}

int main()
{
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i=0; i<m; i++) {
        scanf("%d", a+i);
    }
    sort(a, a+m, cmp);
    gao.clear();
    for (int i=0; i<k; i++) {
        int l, r,d;
        scanf("%d%d%d", &l, &r, &d);
        gao.push_back(T(l, r, d));
    }
    sort(gao.begin(), gao.end(), cmpgao);
    int tmr = gao[gao.size()-1].r;
    mxr[gao.size()-1] = tmr;
    for (int i=gao.size()-2; i>=0; i--) {
        if (gao[i].r > tmr){
            tmr = gao[i].r;
        }
        mxr[i] = tmr;
    }

    int e = m, s = 0;
    int ans = 0;
    while (e > s){
        int mid = (s+e)>>1;

        if (check(mid)) {
                ans = s;
            s = mid+1;
        } else {
            e = mid-1;
        }
    }
    cout << ans << endl;
}
