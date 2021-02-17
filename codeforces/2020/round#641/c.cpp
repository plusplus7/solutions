#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200007;
int vis[maxn]; 
int prime[maxn];
int lp;
int p1[maxn];
int p0[maxn];
 
void sieve(long long n){
    long long m = (long long)sqrt(n + 0.5);
    memset(vis, 0, sizeof(vis));
    vis[2] = 0;
    for (long long i = 3; i <= m; i += 2) {
        if(!vis[i])
            for (long long j = i * i; j <= n; j += i)
                vis[j] = 1;
        if(i * i > n)
            break;
    }
}
 
long long gen(long long n){
    sieve(n);
    long long c = 1;
    prime[0] = 2;
    for (long long i = 3; i <= n; i += 2)
        if(!vis[i])
            prime[c++] = i;
    return c;
}
 
void solve()
{
    int n;
    scanf("%d", &n);
    memset(p0, 0x3f, sizeof(p0));
    memset(p1, 0x3f, sizeof(p1));
    int t;
    for (int i=0; i<n; i++) {
        scanf("%d", &t);
        for (int k=0; k<lp/2;k++) {
            int j = prime[k];
            int c = 0;
            while (t%j == 0) {
                c++;
                t/=j;
            }
            if (c < p0[j]) {
                p1[j] = p0[j];
                p0[j] = c;
            } else if (c < p1[j]) {
                p1[j] = c;
            }
        }
    }
    int ans = 1;
    for (int j = 0; j < lp; j++) {
        if (p1[j] == 0x3f3f3f3f) continue;
        ans *= pow(j, p1[j]);
    }
    printf("%d\n", ans);
}

int main()
{
    lp = gen(200006);
        solve();
}