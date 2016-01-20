#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int N;
        cin >> N;
        int arr[N];
        long long sum[N+1];
        sum[0]=0;
        for(int j=N-1;j>=0;j--)
        {
            cin >> arr[j];
            //sum[j+1] =sum[j]+arr[j];
        }
        for(int j=0;j<N;j++)
        {
            //cin >> arr[j];
            sum[j+1] =sum[j]+arr[j];
        }
        long long ans[N];
        ans[0]=arr[0];
        ans[1]=ans[0]+arr[1];
        ans[2]=ans[1]+arr[2];
        for(int j=3;j<N;j++)
        {
            ans[j]=sum[j]-ans[j-1]+arr[j];
            ans[j]=max(ans[j],sum[j-1]-ans[j-2]+arr[j]+arr[j-1]);
            ans[j]=max(ans[j],sum[j-2]-ans[j-3]+arr[j]+arr[j-1]+arr[j-2]);
        }
        cout << ans[N-1] << endl;
    }
    return 0;
}
