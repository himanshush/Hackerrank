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
    int ans[101]={0};
    int xmin =10001;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
        if(xmin > arr[i])
            xmin = arr[i];
    }
    for(int i=0;i<N;i++)
        ans[arr[i]-xmin]++;
    int M;
    cin >> M;
    int k;
    for(int i=0;i<M;i++)
    {
        cin >>k;
        if(k-xmin >=0 && k-xmin <101)
            ans[k-xmin]--;
    }
    for(int i=0;i<101;i++)
    {
        if(ans[i] < 0)
            cout << i+xmin << ' ';
    }
    cout << endl;
    return 0;
}
