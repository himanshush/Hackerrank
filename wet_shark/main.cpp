#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m,r,s;
    cin >> m >>r >>s;
    int arr[m];
    for(int i=0;i<m;i++)
        cin >> arr[i];
    int sum = (r+s)/2;
    int diff = (r-s)/2;
    //cout << sum << ' ' << diff <<endl;
    long long ans[m+1][sum+1];
    for(int i=0;i<=sum;i++)
        ans[0][i]=0;
    for(int i=0;i<=m;i++)
        ans[i][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-arr[i-1]>=0)
                ans[i][j]=ans[i-1][j-arr[i-1]]+ans[i-1][j];
            //else
             //   ans[i][j]=ans[i-1][j];
            //cout << ans[i][j] << endl;
        }
    }
    long long total=0;
    long long a,b,c;
    const long long mm=1000000007;
    for(int i=2;i<=m;i++)
    {
        /*a= ans[i][sum] %mm;
        b= ans[i][diff]%mm;
        c= (a*b)%mm;
        total=total+c;*/
        total=total+(ans[i][sum])*(ans[i][diff]);
    }
    cout << total << endl;
    return 0;
}
