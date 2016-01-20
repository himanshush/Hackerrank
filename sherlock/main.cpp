#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    int ch[26]={0};
    for(int i=0;i<str.length();i++)
    {
        ch[str[i]-'a']++;
    }
    int i;
    map<int,int> my_map;
    map<int,int> :: iterator it;
    map<int,int> :: iterator it1;
    int flag1=0;
    int flag2=0;
    for(i=0;i<26;i++)
    {
        if(ch[i]!=0)
        {
            it=my_map.find(ch[i]);
            if(it == my_map.end())
            {
                my_map[ch[i]]=1;
            }
            else
                my_map[ch[i]] +=1;
        }
    }
    if(my_map.size()>2)
        cout << "NO" <<endl;
    else
    {
        if(my_map.size()==1)
            cout<<"YES" <<endl;
        else{
            it=my_map.begin();
            it1 = ++it;
            cout << it->second <<' ' <<it1->second<<endl;
            if(it->second ==1||it1->second ==1)
            {

                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
