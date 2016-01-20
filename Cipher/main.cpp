#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,K,result;
    cin >> N >> K;
    string str,outstr;
    cin >> str;
    reverse(str.begin(),str.end());
    for(int i=0;i<N;i++)
    {
        result=str.at(i)-'0';
        for(int j=i-1;j>i-K&&j>=0;j--)
            result = result^(outstr.at(j)-'0');
        outstr.push_back(result+'0');
    }
    reverse(outstr.begin(),outstr.end());
    cout << outstr;
    return 0;
}
