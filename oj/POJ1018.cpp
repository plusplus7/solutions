#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>

#include <iomanip>
#define INF 0x7FFFFFFF
using namespace std;

vector< vector<pair<int, int> > > m;

bool greater_bp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

double solve()
{
    long long ans_b = INF;
    long long ans_p = INF;
    for (int i=0; i<m.size(); i++) {
        for (int j=0; j<m[i].size(); j++) {
            pair<int, int> minbp = m[i][j];
            int sum_p = minbp.second, k;
            for ( k=0; k<m.size(); k++) {
                if (k == i) continue;
                int low = lower_bound(m[k].begin(), m[k].end(), minbp, greater_bp) - m[k].begin();
         //       cout << "("<<minbp.first << ", " << minbp.second << "): " << k << " -> " << low << endl;;
                if (low == m[k].size()) break;

                int min_p = m[k][low].second;
                for (int l=low; l<m[k].size(); l++)
                {
                    if (m[k][l].second < min_p) {
                        min_p = m[k][l].second;
                    }
                }
                //cout << "+" << min_p << endl;
                sum_p += min_p;
            }
            if (k != m.size()) continue;
          //  cout << minbp.first << " " << sum_p << endl;
            if (ans_b == INF || ans_b*(long long)sum_p < (long long)minbp.first*ans_p) {
                ans_b = minbp.first;
                ans_p = sum_p;
            }
         //   cout << "-> " << ans_b <<" "<< ans_p<<endl;
        }
    }
    return (double)ans_b/(double)ans_p;
}

int main()
{
    int t;
    while (cin >> t) {
        while (t--) {
            int n,s;
            cin >> n;
            m.clear();
            while (n--) {

                cin >> s;
                vector< pair<int, int> > tm;
                for (int i=0; i<s; i++) {
                    int b, p;
                    cin >> b >> p;
                    tm.push_back(make_pair(b, p));
                }
                sort(tm.begin(), tm.end(), greater_bp);
                m.push_back(tm);
            }
           /*  for (int i=0; i<m.size(); i++) {
                    cout << i << ": ";
                for (int j=0; j<m[i].size(); j++) {
                        cout << m[i][j].first << " " << m[i][j].second << " ";
                }
                cout << endl;
             }*/
            cout << fixed << setprecision(3) <<solve()<<endl;
        }
    }
}
