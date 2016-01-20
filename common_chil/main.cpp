#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int LCS[5001][5001];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str1,str2;
    cin >> str1 >> str2;
    int N = str1.length();

    for(int i=0;i<=N;i++)
    {
        LCS[i][0]=0;
        LCS[0][i]=0;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    cout << LCS[N][N] << endl;
    return 0;
}
