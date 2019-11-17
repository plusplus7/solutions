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
queue<int> q;
int fp[16] = {
    0x0000C800, 0x0000E400, 0x00007200, 0x00003100,
    0x00008C80, 0x00004E40, 0x00002720, 0x00001310,
    0x000008C8, 0x000004E4, 0x00000272, 0x00000131,
	0x0000008C, 0x0000004E, 0x00000027, 0x00000013
};

int main()
{
    int board = 0;
    for (int i=0; i<4; i++) {
        char t[10];
        cin >> t;
        for (int j=0; j<4; j++) {
            if (t[j] == 'b') {
                board = board<<1;
            } else {
                board = (board<<1) | 1;
            }
        }
    }
      //  cout << board<<endl;
        memset(vis, -1, sizeof(vis));
        vis[board] = 0;
        q.push(board);
        while (!q.empty()) {
            int cb = q.front();
            q.pop();
            int step = vis[cb];
            if ((cb&0x0000FFFF) == 0x0000FFFF || cb == 0) {
                cout << step << endl;
                return 0;
            }
            for (int i=0; i<16; i++) {
                int next = cb ^ fp[i];
             //   cout << cb << " " << fp[i] << " " << next << endl;
                if (vis[next] == -1) {
                    vis[next] = step+1;
                    q.push(next);
                    continue;
                }
            }
        }
        cout <<"Impossible"<<endl;
        return 0;

}
