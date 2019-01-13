#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2000000005;
const int maxn = 1e7 + 10;
bool t[maxn];
int pri[maxn/10];
int cnt;

void getPri()
{
    cnt = 0;
    for(int i=2;i*i<=N;i++)
    {
        if(!t[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                t[j] = true;
            }
        }
    }
    for(int i=2;i<=2*N;i++)
    {
        if(!t[i])
        {
            pri[cnt++] = i;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int n;
    getPri();
    int C = 1;
    while(T--)
    {
        scanf("%d",&n);
        int ret = 0;
        for(int i=0;pri[i]<=n/2;i++)
        {
            if(!t[n-pri[i]]) ret ++;
        }
        printf("Case %d: %d\n",C++,ret);
    }   
    return 0;
}
