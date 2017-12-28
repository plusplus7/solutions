#include <bits/stdc++.h>
using namespace std;

int n, a[1507], ic, b[1507][1507];

class BinTree : vector<int>
{
  public:
    explicit BinTree(int k = 0)
    {
        assign(k + 1, 0);
    }
    int lowbit(int k)
    {
        return k & -k;
    }
    int sum(int k)
    {
        return k > 0 ? sum(k - lowbit(k)) + (*this)[k] : 0;
    }
    int last()
    {
        return size() - 1;
    }
    void add(int k, int w)
    {
        if (k > last())
            return;
        (*this)[k] += w;
        add(k + lowbit(k), w);
    }
};

int gc = 0;
int getIC(int s, int e) {
    BinTree t(n);
    int ic = 0;
    for (int i=e; i>=s; i--) {
        ic += t.sum(a[i]);
        t.add(a[i], 1);
    }
    return ic;
}
int solve(int s, int e)
{
    for (int i = 0; i <= (e - s) / 2; i++)
    {
        int t = a[s+i];
        a[s+i] = a[e-i];
        a[e-i] = t;
    }
    int ic = getIC(s, e);
    int fc = ((e-s+1) * (e-s))/2;
    int pc = fc - ic;
    gc += pc - ic;
    return gc&1;
}


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }
    int q;

    gc = getIC(1, n);
    scanf("%d", &q);
    while (q--)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        printf("%s\n", solve(s, e)? "odd":"even");
    }
    return 0;
}