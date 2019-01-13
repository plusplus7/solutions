#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int n;

vector< int > g[200005];
vector< int > p[200005];
pair<int, int> e[200006];

int results[200006];
int ind[200006];
int color[200006];
int K;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        g[i].clear();
        ind[i] = 0;
    }
    K = 0;
    memset(results, 0, sizeof(results));

    for (int i=0; i<n-1; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        e[i].first = t1;
        e[i].second = t2;
        ind[t1] ++;
        ind[t2] ++;
        K = ind[t1] > K ? ind[t1] : K;
        K = ind[t2] > K ? ind[t2] : K;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    K = K + 1;
    for (int i=0; i<n-1; i++) {
        int t1 = e[i].first;
        int t2 = e[i].second;
        set<int> colors;
        for (int i=1; i<=K; i++) {
            colors.insert(i);
        }
        for (int j=0; j<g[t1].size(); j++) {
            int v = g[t1][j];
            if (results[v] != 0 && colors.count(results[v]) > 0) {
                colors.erase(results[v]);
            }
        }
        for (int j=0; j<g[t2].size(); j++) {
            int v = g[t2][j];
            if (results[v] != 0 && colors.count(results[v]) > 0) {
                colors.erase(results[v]);
            }
        }
        for (int j=0; j<g[t1].size(); j++) {
            int v = g[t1][j];
            if (results[v] == 0) {
                results[v] = *(colors.begin());
                colors.erase(results[v]);
            }
        }
        for (int j=0; j<g[t2].size(); j++) {
            int v = g[t2][j];
            if (results[v] == 0) {
                results[v] = *(colors.begin());
                colors.erase(results[v]);
            }
        }
    }
/*    for (int i=1; i<=n; i++) {
        set<int> colors;
        for (int i=1; i<=K; i++) {
            colors.insert(i);
        }
        for (int j=0; j<g[i].size(); j++) {
            int v = g[i][j];
            if (results[v] != 0) {
                colors.erase(results[v]);
            }
        }
        for (int j=0; j<g[i].size(); j++) {
            int v = g[i][j];
            if (results[v] != 0) {
                colors.erase(results[v]);
            }
        }
        if (results[i] != 0) {
            colors.erase(results[i]);
        } else {
            results[i] = *(colors.begin());
            colors.erase(results[i]);
        }
        for (int j=0; j<g[i].size(); j++) {
            int v = g[i][j];
            if (results[v] == 0) {
                results[v] = *(colors.begin());
                colors.erase(results[v]);
            }
        }
    }
    */
    printf("%d\n", K);
    for (int i=1; i<n; i++) {
        printf("%d ", results[i]);
    }
    printf("%d\n", results[n]);
    
}
