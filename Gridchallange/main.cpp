#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,N;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int found = 1;
        string str[100];
        cin >> N;
        for(int j=0;j<N;j++)
        {
            cin >> str[j];
            sort(str[j].begin(),str[j].end());
        }
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N-1;k++)
            {
                if(str[k][j] > str[k+1][j])
                {
                    found = 0;
                    break;
                }
            }
        }
        if(found ==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
