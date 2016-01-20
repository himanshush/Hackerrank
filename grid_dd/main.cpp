#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

//int INT_MIN=10000;
int arr[100][100];
int ans[100][100][100];
int N,M;
int fun(int x,int y1,int y2)
{
    if(x==N-1 && y1==0 && y2==M-1)
        return arr[x][y1]+arr[x][y2];
    if(x==N-1)
        return INT_MIN;
    if(ans[x][y1][y2]!=-1)
        return ans[x][y1][y2];
    int tmp;
    if(y1==y2)
        tmp=arr[x][y1];
    else
        tmp = arr[x][y1]+arr[x][y2];
    int an=INT_MIN;
    an=max(an,tmp+fun(x+1,y1,y2));
    an=max(an,tmp+fun(x+1,y1+1,y2));
    an=max(an,tmp+fun(x+1,y1-1,y2));
    an=max(an,tmp+fun(x+1,y1,y2+1));
    an=max(an,tmp+fun(x+1,y1,y2-1));
    an=max(an,tmp+fun(x+1,y1+1,y2-1));
    an=max(an,tmp+fun(x+1,y1+1,y2+1));
    an=max(an,tmp+fun(x+1,y1-1,y2+1));
    an=max(an,tmp+fun(x+1,y1-1,y2-1));

    ans[x][y1][y2]=an;
    return ans[x][y1][y2];
}
int main()
{
    //int N,M;
    cin >> N >> M;
    //int arr[i][j];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> arr[i][j];
        }
    }
   // int ans[N][M][M];
    memset(ans,-1,sizeof(ans));
    cout << fun(0,0,M-1) << endl;;
    return 0;
}
