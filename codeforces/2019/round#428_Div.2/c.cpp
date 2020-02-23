#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100005];
int v[100005];

double go(int x, double p, int l)
{
    if (v[x] == 1) {
        return 0.0f;
    }
    v[x] = 1;
    if (g[x].size() == 1 && x != 1) {
        return p*((double)l);
    }
    double newp = 0.0f;
    if (x == 1) {
        newp = p / ((double)(g[x].size()));
    }
    else
    {
        newp = p / ((double)(g[x].size()) - 1.0f);
    }
    double result = 0.0f;
    for (int i = 0; i < g[x].size(); i++)
    {
        int next = g[x][i];
        result += go(next, newp, l + 1);
    }
    return result;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        v[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    printf("%.8f\n", go(1, 1, 0));
}