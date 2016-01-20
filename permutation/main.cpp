#include <iostream>
#include <string>

using namespace std;

void permutation(string str, int k,int n)
{
    if(k==n)
        cout << str << endl;
    else
    {
        for(int i=k;i<n;i++)
        {
            char tmp = str[i];
            str[i]=str[k];
            str[k]=tmp;
            permutation(str,k+1,n);
            tmp = str[i];
            str[i]=str[k];
            str[k]=tmp;
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    string str = "abcd";
    permutation(str,0,str.length());
    return 0;
}
