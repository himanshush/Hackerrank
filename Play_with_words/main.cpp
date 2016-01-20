#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    int N = str.length();
    long long arr[N][N];
    for(int i=0;i<N;i++)
        arr[i][i]=1;
    for(int len=2;len<=N;len++)
    {
        for(int i=0;i<=N-len;i++)
        {
            if(str[i]==str[i+len-1])
            {
                if(len==2)
                    arr[i][i+len-1]=2;
                else
                    arr[i][i+len-1]=2+arr[i+1][i+len-2];
            }
            else
                arr[i][i+len-1] = max(arr[i][i+len-2],arr[i+1][i+len-1]);
        }
    }
    long long ans = -1;
    for(int i=0;i<N-1;i++)
    {
        long long tmp = arr[0][i]*arr[i+1][N-1];
        if(tmp > ans)
            ans=tmp;
        }
    cout << ans<<endl;
    return 0;
}
