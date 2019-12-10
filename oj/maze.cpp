#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <time.h>
#include <windows.h>
using namespace std;
#define MAXSIZE 1638400
int rank[MAXSIZE];
int parent[MAXSIZE];
const int wid=32;
void Init()
{
     memset(rank, 0, sizeof(rank));
     for(int i=0; i < MAXSIZE; ++i )
         parent[i] = i;
}

int FindSet(int x)
{
    if( x != parent[x] )
         parent[x] = FindSet(parent[x]);
     return parent[x];
}

void UnionSet(int root1, int root2)
{
     int x = FindSet(root1), y = FindSet(root2);
     if( x == y ) return ;
     if( rank[x] > rank[y] ) parent[y] = x;
     else{
         parent[x] = y;
         if( rank[x] == rank[y] ) ++rank[y];
     }
}
int postolist(int x,int y)
{
    return x*wid+y;
}
int main()
{
    int n,x,y,i,j,d,xt1,yt1,xt2,yt2;

    char dun[500][500];
    int dir[4][2]={
                {0,1},{1,0},{-1,0},{0,-1}};
    Init();
    for (i=0; i<wid; i++)
    {
        for (j=0; j<wid; j++)
        {
            dun[i][j]='8';
        }
    }
    for (i=1; i<wid; i++)
    {
        if (i%2 == 1)
        {
            for (j=1; j<wid; j+=2)
            {
                dun[i][j]='1';
            }
        }
        else
        {
            for (j=2; j<wid; j+=2)
            {
                dun[i][j]='9';
            }
        }

    }
    srand(time(NULL));
    while (FindSet(postolist(1,1)) != FindSet(postolist(wid-3,wid-3)))
    {

        do{
        x=rand()%(wid-2)+1;
        y=(rand()+123)%(wid-2)+1;
        }while (dun[x][y] != '8');
        d=x%2;

        if (d == 0)
        {
            xt1=x+1;
            yt1=y;
            xt2=x-1;
            yt2=y;
            if (FindSet(postolist(xt1,yt1)) != FindSet(postolist(xt2,yt2)))
            {
                dun[x][y]='1';
                UnionSet(postolist(xt1,yt1),postolist(xt2,yt2));
            }
        }
        else if (d == 1)
        {
            xt1=x;
            yt1=y+1;
            xt2=x;
            yt2=y-1;
            if (FindSet(postolist(xt1,yt1)) != FindSet(postolist(xt2,yt2)))
            {
                dun[x][y]='1';
                UnionSet(postolist(xt1,yt1),postolist(xt2,yt2));
            }
        }

    }
    for (i=0; i<wid; i++)
    {
        dun[i][wid-1]='8';
        dun[wid-1][i]='8';
    }

    for (i=0; i<wid; i++)
    {
        for (j=0; j<wid; j++)
        {
            if(dun[i][j] == '1') {
                printf("  ");
            } else {
                printf("¡ö");
            }
        }
        printf("\n");
    }
    return 0;
}
