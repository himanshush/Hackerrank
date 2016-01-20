#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    cin >> N >> M;
    long long ans[M][N+1];
    int arr[M];
    for(int i=0;i<M;i++)
        cin >> arr[i];
    for(int i=0;i<M;i++)
        ans[i][0]=1;
    for(int i=0;i<M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ans[i][j]=-1;
        }
    }
    for(int i=0;i<M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(j-arr[i] >=0 && ans[i][j-arr[i]]!=-1)
            {
                if(i!=0 && ans[i-1][j]!=-1)
                    ans[i][j]=ans[i-1][j]+ans[i][j-arr[i]];
                else
                    ans[i][j]=ans[i][j-arr[i]];
            }
            else if(i!=0)
                ans[i][j]=ans[i-1][j];
            //cout << ans[i][j]<<endl;
        }
    }
    cout << ans[M-1][N] <<endl;
    return 0;
}
