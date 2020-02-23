#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

map< int, map<int , map <int, map<int ,int > > > > mark;

map<int, map<int, int> > ct;

int is_visited(int x, int y) {
    if (ct.count(x) != 0) {
        if (ct[x].count(y) != 0) {
            return 1;
        }
    }
    return 0;
}

void vis(int x, int y) {
    if (ct.count(x) == 0) {
        map<int ,int > tmp;
        tmp.clear();
        ct[x] = tmp;
    }
    ct[x][y] = 1;
}

int is_marked(int x, int y, int d, int l) {
    if (mark.count(x) != 0) {
        if (mark[x].count(y) != 0) {
            if (mark[x][y].count(d) != 0) {
                if (mark[x][y][d].count(l) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void markit(int x, int y, int d, int l) {
    if (mark.count(x) == 0) {
        map<int , map <int, map<int ,int > > > tmp;
        tmp.clear();
        mark[x] = tmp;
    }
    if (mark[x].count(y) == 0) {
        map <int, map<int ,int > > tmp;
        tmp.clear();
        mark[x][y] = tmp;
    }
    if (mark[x][y].count(d) == 0) {
        map<int ,int > tmp;
        tmp.clear();
        mark[x][y][d] = tmp;
    }
    mark[x][y][d][l] = 1;
}

void ad(int &x, int &y, int d) {
    if (d == 0) {
        y++;
    } else if (d == 45) {
        x++;
        y++;
    } else if (d == 90) {
        x++;
    } else if (d == 135) {
        x++;
        y--;
    } else if (d == 180) {
        y--;
    } else if (d == 225) {
        x--;
        y--;
    } else if (d == 270) {
        x--;
    } else if (d == 315) {
        x--;
        y++;
    } else if (d == 360) {
        y++;
    }
}

int n, a[35];
int ans;
void go(int x, int y, int d, int c) {
    if (is_marked(x, y, d, c) == 1) {
        return ;
    }
    int tx = x;
    int ty = y;
    for (int k=0; k<a[c]; k++) {
        ad(tx, ty, d);
        if (is_visited(tx, ty) == 0) {
            ans ++;
            vis(tx, ty);
        }
    }
    markit(x, y, d, c);
    if (c == n-1) {
        return ;
    }
    int xd = ((d-45) + 360) %360;
    int yd = ((d+45) + 360) %360;
    if (is_marked(tx, ty, xd, c+1) == 0) {
        go(tx, ty, xd, c+1);
    }
    if (is_marked(tx, ty, yd, c+1) == 0) {
        go(tx, ty, yd, c+1);
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    ans = 0;
    go(0, -1, 0, 0);

    cout << ans << endl;
    return 0;
}
