#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdio.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    vector<pair<int,int> > vec;
    cin >> N;
    int tt,ts;
    for(int j=0;j<N;j++)
    {
        cin >> tt >> ts;
        vec.push_back(make_pair(tt+ts,j+1));
    }
    sort(vec.begin(),vec.end());
    for (std::vector< pair<int,int> >::iterator it = vec.begin() ; it != vec.end(); ++it)
        std::cout << it->second << ' ';
    return 0;
}
