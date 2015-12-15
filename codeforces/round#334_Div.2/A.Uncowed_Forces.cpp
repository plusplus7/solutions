#include <iostream>

using namespace std;

int main()
{
    int a[5], w[5], h[2];
    for (int i=0; i<5; i++) {
        cin >> a[i];
    }
    for (int i=0; i<5; i++) {
        cin >> w[i];
    }
    for (int i=0; i<2; i++) {
        cin >> h[i];
    }

    int score = h[0]*100 - h[1]*50;
    for (int i=0; i<5; i++) {
        int ap = (250-a[i]) * (i*2+2) - 50*w[i];
        if (ap < (i+1)*150) {
            ap = (i+1)*150;
        }
        score = score+ap;
    }
    cout << score << endl; 
    return 0;
}
