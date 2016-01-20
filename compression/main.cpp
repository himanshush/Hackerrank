#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
char out[1025];

string compression(string str)
{
    int ch[52]={0};
    int N=str.length();
    int j=0;
    for(int i=0;i<N;i++)
    {
        ch[str[i]-'a']=1;
        while(str[i]==str[i+1])
        {
            ch[str[i]-'a']++;
            i=i+1;
        }
        if(ch[str[i]-'a'] == 1)
         {
            out[j]=str[i];
            j++;
         }
        else
        {
            out[j]=str[i];
            out[j+1]=ch[str[i]-'a']+'0';
            j=j+2;
        }
    }
    out[j]='\0';
    string p(out);
    //cout << p << endl;
    return p;
}
int main()
{
    string str;
    cin >> str;
    cout << compression(str);
    return 0;
}
