#include <iostream>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int arr[N];
    int sum[N+1];
    sum[0]=0;
    int lc[N][N];
    int MAX = 100000;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
        sum[i+1]=sum[i]+arr[i];
        if(sum[i+1]<=M)
            lc[0][i]=M-sum[i+1];
        else
            lc[0][i]=MAX;
        //cout << lc[0][i]<<' ';
    }
    //cout << endl;
    int ANS[N+1];
    ANS[0]=0;
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            if(sum[j+1]-sum[i] <=M)
                lc[i][j]=M-(sum[j+1]-sum[i]);
            else
                lc[i][j]=MAX;
            //cout << lc[i][j] <<' ';
        }
        //cout << endl;
    }
    /*
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
        //    if(sum[j+1]-sum[i] <=M)
          //      lc[i][j]=M-(sum[j+1]-sum[i]);
            //else
                //lc[i][j]=MAX;
            cout << lc[i][j] <<' ';
        }
        //cout << endl;
    }
    */
    for(int i=0;i<N;i++)
    {
        ANS[i+1]=MAX;
        for(int j=0;j<=i;j++)
        {
            if(ANS[i+1] > ANS[j]+lc[j][i])
                ANS[i+1]=ANS[j]+lc[j][i];
        }
        //cout << ANS[i+1] << endl;
    }
    cout << ANS[N] << endl;
    return 0;
}
