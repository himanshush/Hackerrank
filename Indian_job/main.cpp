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
        int N,G;
        cin >> N >> G;
        int arr[N];
        for(int j=0;j<N;j++)
            cin >> arr[j];
        sort(arr,arr+N);
        reverse(arr,arr+N);
        long long f=arr[0];
        long long s=0;
        int found =0;
        for(int j=1;j<N;j++)
        {
            if(f>s)
            {
                s=s+arr[j];
            }
            else
                f=f+arr[j];
            //cout << f << ' ' << s << endl;
            if(f >G || s>G)
            {
                found =1;
                break;
            }
        }
        if(found ==1)
            cout << "NO" <<endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
