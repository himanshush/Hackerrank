/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
#include <iterator>
#include <functional>

using namespace std;
int main(void){
//Helpers for input and output

   int N, K;
   cin >> N >> K;
    int C[N];
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }
   sort(C,C+N, std::greater<int>());
   //reverse(begin(C),end(C));
   int result=0;
   int t =0;
   for(int i=0;i<N;i++)
   {
       if(i%K == 0)
            t++;
       result = result+t*C[i];
   }
   cout << result << "\n";

   return 0;
}
