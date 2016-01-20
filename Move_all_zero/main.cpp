#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
    {
        int N;
        cin >>N;
        int arr[N];
        for(int j=0;j<N;j++)
            cin >> arr[j];
        int zi=N-1;
        int oi=N-1;
        for(zi=N-1;zi >=0;zi--)
        {
            if(arr[zi]==0)
            {
                if(zi!=oi)
                    swap(arr[zi],arr[oi]);
                oi--;
            }
        }
        for(int j=0;j<N;j++)
            cout << arr[j] <<' ';
        cout << endl;
    }
	return 0;
}
