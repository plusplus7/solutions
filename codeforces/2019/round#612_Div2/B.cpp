#include <bits/stdc++.h>

using namespace std;
set<string> st;
string card[1505];

int main() {
    int n, k;
    int ans = 0;
    cin >>n >> k;
    st.clear();
    for (int i=0; i<n; i++) {
        cin >> card[i];
        st.insert(card[i]);
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++)  {
            string ts = "";
            for (int l=0; l<k; l++) {
                if (card[i][l] == card[j][l]) {
                    ts += card[i][l];
                } else {
                    char dr[4] = "SET";
                    for (int td=0; td<3; td++) {
                        if (dr[td] != card[i][l] && dr[td] != card[j][l])
                        {
                            ts += dr[td];
                            break;
                        }
                    }
                }
            }
        //    cout <<i <<" " << j<< " "<< ts << " " << st.count(ts)<< endl;
            if (st.count(ts) != 0 && ts != card[i] && ts != card[j]) {
                ans ++;
            }
        }
    }
    cout << ans/3 << endl;

}
