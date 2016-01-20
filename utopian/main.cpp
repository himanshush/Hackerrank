#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >>T;
    for(int i=0;i<T;i++)
    {
        int N;
        cin >> N;
        int H=1;
        for(int j=0;j<N;j++)
        {
            if(j%2==0)
                H=H*2;
            else
                H+=1;
        }
        cout << H <<endl;
    }
    return 0;
}
