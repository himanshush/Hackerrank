#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fun(long long A[],long long B[],int start,int N)
{
    int i=start;
    int j=start+1;
    long long cap=A[i]-B[i];
    while(i!=j)
    {
        while(cap < 0 && i!=j)
        {
            cap=cap-(A[i]-B[i]);
            i=(i+1)%N;
            if(i==start)
                return -1;
        }
        cap=cap+(A[j]-B[j]);
        j=(j+1)%N;
    }
    if(cap <0)
        return -1;
    else
        return j;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    long long C;
    cin >> N >> C;
    long long A[N];
    long long B[N];
    for(int i=0;i<N;i++)
    {
        cin >>A[i];
        if(A[i]>C)
            A[i]=C;
    }
    for(int i=0;i<N;i++)
        cin >>B[i];
    int ans=0;
    int j;
    int visit[N];
    for(int i=0;i<N;i++)
        visit[i]=0;
    for(int i=0;i<N;)
    {
        j = fun(A,B,i,N);
        if(j==-1||visit[j]==1)
            break;
        visit[j]=1;
        i=j+1;
        ans++;
    }
    cout << ans <<endl;
    return 0;
}
