#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
using namespace std;

uint64_t input[100000];
uint64_t output[100000];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int T,i;

     cin >> T;
     int N;
     uint64_t M;
     uint64_t temp;
     scanf("%d %llu",&N,&M);
     printf("%ll",M);
     for(i=0;i<N;i++)
     {
         scanf("%ll",&temp);
     }
    return 0;
}
