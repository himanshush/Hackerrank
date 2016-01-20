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
        string s1,s2;
        int n,s;
        cin >> s;
        cin >> s1;
        cin >> s2;
        int best=0;
        n=s1.length();
        for(int k=0;k<n;k++)
        {
            for(int p=0;p<n;p++)
            {
                int bad=0;
                for(int l=0;l<n;l++)
                {
                    if(p+l>=n || k+l>=n)
                    {
                        best=max(best,l);
                        break;
                    }
                    if(s1[k+l]!=s2[p+l])
                        bad++;
                    if(bad >s)
                    {
                        best=max(best,l);
                        break;
                    }
                }
            }
        }
        cout << best <<endl;
    }
    return 0;
}
