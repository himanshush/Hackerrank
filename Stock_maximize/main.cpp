#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,N;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> N;
        int in[N];
        long long profit = 0;
        int curr_max = -1;
        for(int j=0;j<N;j++)
        {
            cin >> in[j];
        }
        for(int j=N-1;j>=0;j--)
        {
          if(in[j] > curr_max)
                curr_max = in[j];
          profit += curr_max-in[j];
        }
        cout << profit << endl;
    }
    return 0;
}
