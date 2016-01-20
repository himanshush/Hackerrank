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
        long long arr[N];
//        int allneg = 0;
  //      int maxi = -10001;
        for(int j=0;j<N;j++)
        {
            cin >> arr[j];
        }
        long long ans=arr[0];
        long long curr=arr[0];
        long long ans2;
        if(arr[0]>0)
            ans2=arr[0];
        else
            ans2=0;
        for(int j=1;j<N;j++)
        {
            curr=max(curr+arr[j],arr[j]);
            ans=max(curr,ans);
            if(arr[j]>0)
                ans2+=arr[j];
        }
        if(ans<0)
            ans2=ans;
        cout << ans <<' ' << ans2 << endl;
    }
    return 0;
}
