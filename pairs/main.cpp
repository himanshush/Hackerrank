#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int dfs(int root,list<int> *graph,int *arr)
{
    if(graph[root].size() == 0)
        return 0;
    else
    {
        list<int>:: iterator it;
        for(it=graph[root].begin();it!=graph[root].end();++it)
            arr[root] += dfs(*it,graph,arr)+1;
    }
    return arr[root];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    cin >> N >> M;
    list<int>  graph[N+1];
    for(int j=0;j<M;j++)
    {
        int u,v;
        cin >> u >> v;
        graph[v].push_back(u);
    }
    int children[N+1];
    int visited[N+1];
    for(int i=0;i<=N;i++)
    {
        children[i]=0;
        visited[i]=-1;
    }
    dfs(1,graph,children);
    int ans=0;
    for(int i=0;i<=N;i++)
    {
        if(children[i]!=0 && children[i]%2==1)
            ans++;
        //cout << i << ' ' << children[i] <<endl;
    }
    cout << ans-1 << endl;
    return 0;
}
