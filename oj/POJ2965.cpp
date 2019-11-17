#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iomanip>
#include <queue>
#define INF 0x7FFFFFFF
using namespace std;

int vis[65536];
pair<int, int> ans[65536];
queue<int> q;
int fp[16] = {
    0x0000F888, 0x0000F444, 0x0000F222, 0x0000F111,
    0x00008F88, 0x00004F44, 0x00002F22, 0x00001F11,
    0x000088F8, 0x000044F4, 0x000022F2, 0x000011F1,
	0x0000888F, 0x0000444F, 0x0000222F, 0x0000111F
};

int main()
{
    int board = 0;
    for (int i=0; i<4; i++) {
        char t[10];
        cin >> t;
        for (int j=0; j<4; j++) {
            if (t[j] == '-') {
                board = board<<1;
            } else {
                board = (board<<1) | 1;
            }
        }
    }
      //  cout << board<<endl;
        memset(vis, -1, sizeof(vis));
        vis[board] = 0;
        ans[board] = make_pair(0, -1);
        q.push(board);
        while (!q.empty()) {
            int cb = q.front();
            q.pop();
            int step = vis[cb];
            if (cb == 0) {
                break;
            }
            for (int i=0; i<16; i++) {
                int next = cb ^ fp[i];
             //   cout << cb << " " << fp[i] << " " << next << endl;
                if (vis[next] == -1) {
                    ans[next] = make_pair(cb, i);
                    vis[next] = step+1;
                    q.push(next);
                    continue;
                }
            }
        }
        vector<int> tans;
        tans.clear();
        pair<int, int> c = ans[0];
        while (c.first != 0) {
            tans.push_back(c.second);
            c = ans[c.first];
        }

        cout << tans.size() << endl;

        for (int i=tans.size()-1; i>=0; i--) {
            cout << tans[i]/4 + 1 << " " << tans[i]%4 + 1 << endl;
        }
        return 0;

}
