#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M;
    cin >> M;
   // cout << M <<endl;
    int arr[41];
    arr[0]=1;
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    for(int i=4;i<41;i++)
    {
        arr[i]=arr[i-1]+arr[i-4];
    }
    cout << arr[M] << endl;
    return 0;
}
