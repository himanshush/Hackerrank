#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    int arr[N];
    long long tmp[N];
    tmp[0]=1;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    for(int i=1;i<N;i++)
    {
        if(arr[i] >arr[i-1])
            tmp[i]=1+tmp[i-1];
        else
            tmp[i]=1;
    }
    for(int i=N-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1])
            tmp[i]=max(1+tmp[i+1],tmp[i]);
    }
    long long ans=0;
    for(int i=0;i<N;i++)
        ans+=tmp[i];
    cout << ans << endl;
    return 0;
}
