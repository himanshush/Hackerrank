#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int i=0;i<T; i++)
    {
        string str;
        cin >> str;
        int j;
        int found =0;
        for(j=str.length()-1;j>0;j--)
        {
            if(str[j] > str[j-1])
            {
                found = 1;
                break;
            }
        }
        if(found == 0)
            cout << "no answer" << endl;
        else
        {
            int k;
            //cout << j << endl;

            for(k=str.length()-1;k>=j;k--)
            {
                if(str[k] > str[j-1])
                {
                    swap(str[j-1],str[k]);
                    break;
                }
            }
            reverse(str.begin()+j,str.end());
            cout << str << endl;
        }
    }
    return 0;
}
